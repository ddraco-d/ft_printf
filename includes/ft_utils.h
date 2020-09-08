/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 22:43:46 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:18:04 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(ssize_t n, int fd);
int		ft_len_int(ssize_t nbr);
void	ft_putchar_n(char c, int n);
void	ft_putchar_fd(char c, int fd);
void	ft_un_putnbr(size_t n, int base, int is_upper);

#endif
