/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:36:20 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:24:52 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"
#include "../includes/ft_utils.h"

static int	len_from_str(const char *format)
{
	int		len;

	len = 0;
	while (ft_isdigit(*format))
	{
		len++;
		format++;
	}
	return (len);
}

static int	precision(const char *format, va_list *args, t_data *data)
{
	int		i;

	i = 0;
	if (*format == '*')
	{
		data->precision = va_arg(*args, int);
		data->precision = data->precision < 0 ? -1 : data->precision;
		i++;
	}
	else if ((ft_isdigit(*format)))
	{
		data->precision = ft_atoi(format);
		i += len_from_str(format);
	}
	else
		data->precision = 0;
	if (data->flag_zero == '0' && data->precision != -1)
		data->flag_zero = '.';
	return (i);
}

int			ft_precision_parse(const char *format,
								va_list *args, t_data *data)
{
	int		i;

	i = 0;
	data->precision = -1;
	if (*format == '.')
	{
		i++;
		format++;
		i += precision(format, args, data);
	}
	return (i);
}
