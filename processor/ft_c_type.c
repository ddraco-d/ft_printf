/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:58:46 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:22:19 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"
#include "../includes/ft_utils.h"

static int	ft_print_space(t_data *data)
{
	int spaces;

	spaces = (data->width > 0 ? data->width - 1 : 0);
	if (data->flag_zero == '0' && data->type == '%')
		ft_putchar_n('0', spaces);
	else
		ft_putchar_n(' ', spaces);
	return (spaces);
}

int			ft_c_type(t_data *data, va_list *args)
{
	char	c;
	int		i;

	if (data->type == 'c')
		c = (char)va_arg(*args, int);
	else
		c = '%';
	i = 1;
	if (data->flag_minus == '.')
		i += ft_print_space(data);
	write(1, &c, 1);
	if (data->flag_minus == '-')
		i += ft_print_space(data);
	return (i);
}
