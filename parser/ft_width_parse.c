/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:36:26 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:22:05 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"
#include "../includes/ft_utils.h"

int				ft_width_parse(const char *format, va_list *args, t_data *data)
{
	int i;

	i = 0;
	if (*format == '*')
	{
		data->width = va_arg(*args, int);
		if (data->width < 0)
		{
			data->width = data->width * (-1);
			data->flag_minus = '-';
		}
		i++;
	}
	else if ((ft_isdigit(*format)))
	{
		data->width = ft_atoi(format);
		i += ft_len_int(data->width);
	}
	else
		data->width = 0;
	return (i);
}
