/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:36:17 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:18:49 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"
#include "../includes/ft_utils.h"

int		ft_flag_parse(const char *format, t_data *data)
{
	int i;

	i = 0;
	data->flag_zero = '.';
	data->flag_minus = '.';
	while (*format == '0' || *format == '-')
	{
		if (*format == '0')
			data->flag_zero = '0';
		else if (*format == '-')
			data->flag_minus = '-';
		format++;
		i++;
	}
	return (i);
}
