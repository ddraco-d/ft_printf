/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:58:44 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:29:06 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"
#include "../includes/ft_utils.h"

static int	ft_print_spaces(t_data *data, int arg_len, ssize_t arg)
{
	int		spaces;
	int		preci;
	int		width;
	char	what_symb;

	spaces = 0;
	width = data->width;
	if (arg < 0)
		preci = (data->precision >= arg_len ? data->precision + 1 : arg_len);
	else
		preci = (data->precision >= arg_len ? data->precision : arg_len);
	spaces = (width > preci ? width - preci : 0);
	if (data->flag_zero == '0')
		what_symb = '0';
	else
		what_symb = ' ';
	ft_putchar_n(what_symb, spaces);
	return (spaces);
}

static int	ft_print_zero(t_data *data, int arg_len, ssize_t arg)
{
	int		precision;
	int		count_zero;

	precision = data->precision;
	if (arg >= 0)
		count_zero = precision > arg_len ? precision - arg_len : 0;
	else
	{
		arg_len--;
		count_zero = precision > arg_len ? precision - arg_len : 0;
	}
	ft_putchar_n('0', count_zero);
	return (count_zero);
}

int			ft_int_type(t_data *data, va_list *args)
{
	ssize_t arg;
	int		i;
	int		arg_len;

	arg = va_arg(*args, int);
	arg_len = ft_len_int(arg);
	arg_len = (data->precision == 0 && arg == 0 ? 0 : arg_len);
	i = arg_len;
	data->flag_zero == '0' && arg < 0 ? ft_putchar_n('-', 1) : 0;
	if (data->flag_minus == '.')
		i += ft_print_spaces(data, arg_len, arg);
	data->flag_zero == '.' && arg < 0 ? ft_putchar_n('-', 1) : 0;
	i += ft_print_zero(data, arg_len, arg);
	if (!(data->precision == 0 && arg == 0))
		arg >= 0 ? ft_putnbr_fd(arg, 1) : ft_putnbr_fd(arg * (-1), 1);
	if (data->flag_minus == '-')
		i += ft_print_spaces(data, arg_len, arg);
	return (i);
}
