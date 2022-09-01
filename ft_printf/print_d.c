/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:27:17 by kiyoon            #+#    #+#             */
/*   Updated: 2022/01/05 16:12:44 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(va_list ap)
{
	int		nb;
	int		len;
	char	*arr;

	nb = va_arg(ap, int);
	ft_putnbr_fd(nb, 1);
	arr = ft_itoa(nb);
	len = ft_strlen(arr);
	free(arr);
	return (len);
}
