/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:39:27 by kiyoon            #+#    #+#             */
/*   Updated: 2022/01/05 16:13:21 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(va_list ap)
{
	unsigned int	nb;
	char			*arr;
	int				len;

	nb = va_arg(ap, unsigned int);
	arr = utoa(nb);
	ft_putstr_fd(arr, 1);
	len = ft_strlen(arr);
	free(arr);
	return (len);
}
