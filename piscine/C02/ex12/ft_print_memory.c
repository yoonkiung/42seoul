/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:51:46 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/16 01:39:23 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	is_printable(char c)
{
	bool	ans;

	if (c < ' ' || c == 127)
		ans = false;
	else
		ans = true;
	return (ans);
}

void	to_hexa(unsigned char c)
{
	char	*arr;

	arr = "0123456789abcdef";
	write(1, &arr[c / 16], 1);
	write(1, &arr[c % 16], 1);
}

void	to_content_hexa(char *str)
{
	int	i;

	i = 0;
	while (str[i] && i < 16)
	{
		to_hexa(str[i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	to_printable(char *str)
{
	int	i;
	int	size;
	int	blank;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	blank = 16 - size;
	while (i < blank)
	{
		write(1, " ", 1);
		i++;
	}
	i = 0;
	while (str[i] && i < 16)
	{
		if (is_printable(str[i]))
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i < size)
	{
		j = 56;
		while (j >= 0)
		{
			to_hexa(((unsigned long)(addr + i)) >> j);
			j -= 8;
		}
		write(1, ":", 1);
		write(1, " ", 1);
		to_content_hexa(addr + i);
		to_printable(addr + i);
		i += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
