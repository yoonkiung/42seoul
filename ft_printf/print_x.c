/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:03:41 by kiyoon            #+#    #+#             */
/*   Updated: 2022/01/05 16:13:36 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(va_list ap)
{
	unsigned int	nb;
	char			arr[20];
	char			*base;
	int				i;

	nb = va_arg(ap, unsigned int);
	i = 0;
	while (i < 20)
		arr[i++] = '\0';
	i = 0;
	base = "0123456789abcdef";
	while (1)
	{
		arr[i] = base[nb % 16];
		nb = nb / 16;
		if (nb == 0)
			break ;
		i++;
	}
	ft_strrev(arr);
	ft_putstr_fd(arr, 1);
	return (ft_strlen(arr));
}
