/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:58:41 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:26:32 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"
#include "../includes/ft_utils.h"

static void	counter(int base, int *len, size_t arg)
{
	while (arg / base != 0)
	{
		arg = arg / base;
		(*len)++;
	}
	(*len)++;
}

static int	ft_print_space(t_data *data, int p_len)
{
	int	width;
	int	count_space;

	width = data->width;
	count_space = width > p_len ? width - p_len : 0;
	if (data->flag_zero == '.')
		ft_putchar_n(' ', count_space);
	else if (data->flag_zero == '0')
	{
		ft_putchar_n('0', 1);
		ft_putchar_n('x', 1);
		ft_putchar_n('0', count_space);
	}
	return (count_space);
}

static void	ft_print_pointer(t_data *data, size_t p_nbr)
{
	if (data->flag_zero != '0')
	{
		ft_putchar_n('0', 1);
		ft_putchar_n('x', 1);
	}
	ft_un_putnbr(p_nbr, 16, 0);
}

int			ft_p_type(t_data *data, va_list *args)
{
	size_t	p_nbr;
	int		length;
	int		p_len;

	p_nbr = va_arg(*args, size_t);
	p_len = 2;
	counter(16, &p_len, p_nbr);
	length = p_len;
	if (data->flag_minus == '.')
		length += ft_print_space(data, p_len);
	ft_print_pointer(data, p_nbr);
	if (data->flag_minus == '-')
		length += ft_print_space(data, p_len);
	return (length);
}
