/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddraco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:27:21 by ddraco            #+#    #+#             */
/*   Updated: 2020/07/28 01:16:00 by ddraco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_data
{
	unsigned char	flag_zero;
	unsigned char	flag_minus;
	int				width;
	int				precision;
	char			type;
}					t_data;
int					ft_type_parse(const char *format, t_data *data);
t_data				*ft_parser(const char **format, va_list *args);
int					ft_flag_parse(const char *format, t_data *data);
int					ft_width_parse(const char *format,
							va_list *args, t_data *data);
int					ft_precision_parse(const char *format,
							va_list *args, t_data *data);
#endif
