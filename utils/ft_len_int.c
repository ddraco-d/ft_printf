/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 15:26:33 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:26:57 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

int	ft_len_int(ssize_t nbr)
{
	int len;

	len = (nbr == 0 ? 1 : 0);
	if (nbr < 0)
		len += 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
