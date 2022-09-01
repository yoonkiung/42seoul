/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:39:24 by kiyoon            #+#    #+#             */
/*   Updated: 2022/01/05 16:14:20 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

static unsigned int	ft_abs(unsigned int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static unsigned int	get_malloc_size(unsigned int n)
{
	unsigned int	size;
	unsigned int	nb;

	size = 0;
	if (n == 0)
		return (2);
	nb = ft_abs(n);
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	if (n < 0)
		size++;
	return (size + 1);
}

char	*utoa(unsigned int n)
{
	char			*arr;
	unsigned int	i;
	unsigned int	nb;

	arr = (char *)malloc(sizeof(char) * get_malloc_size(n));
	if (!arr)
		return (NULL);
	if (n == 0)
		ft_strlcpy(arr, "0", 2);
	else
	{
		i = 0;
		nb = ft_abs((unsigned int)n);
		while (nb > 0)
		{
			arr[i++] = (nb % 10) + '0';
			nb /= 10;
		}
		if (n < 0)
			arr[i++] = '-';
		arr[i] = '\0';
		ft_strrev(arr);
	}
	return (arr);
}
