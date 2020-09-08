/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:48:19 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:17:28 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/ft_parser.h"
#include "includes/ft_processor.h"
#include "includes/ft_utils.h"

static int	find_spec(const char **format, int *length)
{
	while (**format && **format != '%')
	{
		write(1, *format, 1);
		(*format)++;
		(*length)++;
	}
	if (**format == '%')
	{
		(*format)++;
		return (1);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	t_data	*info;
	int		flag;

	flag = 0;
	va_start(args, format);
	length = 0;
	while (*format && find_spec(&format, &length) && flag != -1)
	{
		if ((info = ft_parser(&format, &args)) != NULL)
			length += ft_processor(info, &args);
		else if (*format)
			flag = -1;
	}
	va_end(args);
	if (flag == -1)
		return (-1);
	return (length);
}
