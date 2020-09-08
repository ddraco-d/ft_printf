/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:58:50 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:28:18 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"
#include "../includes/ft_utils.h"

static int	ft_print_space(t_data *data, int str_len)
{
	int		spaces;
	int		width;
	int		preci;

	spaces = 0;
	width = data->width;
	if (data->precision != -1)
		preci = str_len > data->precision ? data->precision : str_len;
	else
		preci = str_len;
	spaces = width > preci ? width - preci : 0;
	ft_putchar_n(' ', spaces);
	return (spaces);
}

static int	ft_print_str(t_data *data, char *s)
{
	int		str_len;
	int		i;
	int		len;

	str_len = ft_strlen(s);
	if (data->precision != -1)
		i = str_len > data->precision ? data->precision : str_len;
	else
		i = str_len;
	len = i;
	while (len > 0)
	{
		write(1, s, 1);
		s++;
		len--;
	}
	return (i);
}

int			ft_s_type(t_data *data, va_list *args)
{
	int		i;
	char	*s;

	s = va_arg(*args, char*);
	i = 0;
	if (!s)
		s = "(null)";
	if (data->flag_minus == '.')
		i += ft_print_space(data, ft_strlen(s));
	i += ft_print_str(data, s);
	if (data->flag_minus == '-')
		i += ft_print_space(data, i);
	return (i);
}
