/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:26:01 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/16 17:22:01 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c);
bool	is_printable(char c);
void	to_hexa(unsigned char c);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_printable(str[i]))
			ft_putchar(str[i]);
		else
			to_hexa(str[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

bool	is_printable(char c)
{
	return (c >= ' ' && c < 127);
}

void	to_hexa(unsigned char c)
{
	ft_putchar('\\');
	ft_putchar("0123456789abcdef"[c / 16]);
	ft_putchar("0123456789abcdef"[c % 16]);
}
