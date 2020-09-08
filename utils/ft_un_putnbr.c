/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:21:04 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:32:48 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

void	ft_un_putnbr(size_t n, int base, int is_upper)
{
	char	*buf;

	if (is_upper)
		buf = "0123456789ABCDEF";
	else
		buf = "0123456789abcdef";
	if (n / base != 0)
		ft_un_putnbr(n / base, base, is_upper);
	ft_putchar_n(buf[n % base], 1);
}
