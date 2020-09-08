/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:36:13 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:19:22 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"
#include "../includes/ft_utils.h"

t_data		*ft_parser(const char **format, va_list *args)
{
	t_data	*data;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	(*format) += ft_flag_parse(*format, data);
	(*format) += ft_width_parse(*format, args, data);
	(*format) += ft_precision_parse(*format, args, data);
	if (data->flag_zero == '0' && data->flag_minus == '-')
		data->flag_zero = '.';
	if (ft_type_parse(*format, data))
		(*format)++;
	else
	{
		free(data);
		return (NULL);
	}
	return (data);
}
