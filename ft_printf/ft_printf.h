/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:22:38 by kiyoon            #+#    #+#             */
/*   Updated: 2022/01/06 10:05:38 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		print_c(va_list ap);

int		print_d(va_list ap);

int		print_p(va_list ap);

int		print_s(va_list ap);

int		print_u(va_list ap);

int		print_x(va_list ap);

int		print_xx(va_list ap);

char	*utoa(unsigned int n);

void	ft_strrev(char *str);

int		ft_printf(const char *format, ...);

int		to_print(const char *format, va_list ap);

int		exist_tag(char *format, va_list ap);

int		is_tag(char c, char *tag);

int		count_tag(const char *format);

#endif
