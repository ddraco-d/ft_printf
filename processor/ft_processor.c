/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:01:24 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:25:08 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

int	ft_processor(t_data *data, va_list *args)
{
	char	type;
	int		i;

	i = 0;
	type = data->type;
	if (type == 'd' || type == 'i')
		i = ft_int_type(data, args);
	if (type == 'x' || type == 'X' || type == 'u')
		i = ft_uxx_type(data, args);
	if (type == 'c' || type == '%')
		i = ft_c_type(data, args);
	if (type == 's')
		i = ft_s_type(data, args);
	if (type == 'p')
		i = ft_p_type(data, args);
	free(data);
	return (i);
}
