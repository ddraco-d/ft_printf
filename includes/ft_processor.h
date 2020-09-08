/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:01:37 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:17:56 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H
# include "ft_parser.h"

int	ft_processor(t_data *data, va_list *args);
int ft_int_type(t_data *data, va_list *args);
int ft_uxx_type(t_data *data, va_list *args);
int ft_c_type(t_data *data, va_list *args);
int ft_s_type(t_data *data, va_list *args);
int ft_p_type(t_data *data, va_list *args);

#endif
