/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:36:22 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:19:30 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

int		ft_type_parse(const char *format, t_data *data)
{
	if (*format == 'd')
		data->type = 'd';
	else if (*format == 'i')
		data->type = 'i';
	else if (*format == 'c')
		data->type = 'c';
	else if (*format == 's')
		data->type = 's';
	else if (*format == 'p')
		data->type = 'p';
	else if (*format == 'x')
		data->type = 'x';
	else if (*format == 'X')
		data->type = 'X';
	else if (*format == '%')
		data->type = '%';
	else if (*format == 'u')
		data->type = 'u';
	else
		return (0);
	return (1);
}
