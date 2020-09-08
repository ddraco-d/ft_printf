/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxx_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:58:53 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:32:31 by ddraco           ###   ########.fr       */
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

static int	ft_print_spaces(t_data *data, int arg_len)
{
	int		spaces;
	int		preci;
	int		width;
	char	what_symb;

	width = data->width;
	preci = (data->precision >= arg_len ? data->precision : arg_len);
	spaces = (width > preci ? width - preci : 0);
	if (data->flag_zero == '0')
		what_symb = '0';
	else
		what_symb = ' ';
	ft_putchar_n(what_symb, spaces);
	return (spaces);
}

static int	ft_print_zero(t_data *data, int arg_len)
{
	int		precision;
	int		count_zero;

	precision = data->precision;
	count_zero = (precision > arg_len ? precision - arg_len : 0);
	ft_putchar_n('0', count_zero);
	return (count_zero);
}

int			ft_uxx_type(t_data *data, va_list *args)
{
	int		base;
	int		is_up;
	size_t	arg;
	int		len;
	int		i;

	len = 0;
	arg = va_arg(*args, unsigned int);
	is_up = (data->type == 'X' ? 1 : 0);
	base = (data->type == 'u' ? 10 : 16);
	counter(base, &len, arg);
	len = (data->precision == 0 && arg == 0 ? 0 : len);
	i = len;
	if (data->flag_minus == '.')
		i += ft_print_spaces(data, len);
	i += ft_print_zero(data, len);
	if (!(data->precision == 0 && arg == 0))
		ft_un_putnbr(arg, base, is_up);
	if (data->flag_minus == '-')
		i += ft_print_spaces(data, len);
	return (i);
}
