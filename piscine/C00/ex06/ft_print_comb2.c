/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:18:12 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/14 17:12:14 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char a, char b, char c, char d);
void	add(char *a, char *b, char *c, char *d);

void	ft_print_comb2(void)
{
	char	i;
	char	j;
	char	k;
	char	l;

	i = '0';
	j = '0';
	while (i <= '9' && j <= '9')
	{
		add(&i, &j, &k, &l);
		while (k <= '9' && l <= '9')
		{
			ft_print(i, j, k, l);
			add(&k, &l, &k, &l);
		}
		add(&i, &j, &i, &j);
	}
}

void	ft_print(char a, char b, char c, char d)
{
	char	blank;
	char	coma;

	blank = ' ';
	coma = ',';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &blank, 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!(a == '9' && b == '8' && c == '9' && d == '9'))
	{
		write(1, &coma, 1);
		write(1, &blank, 1);
	}
}

void	add(char *a, char *b, char *c, char *d)
{
	if (*b == '9')
	{
		*c = *a + 1;
		*d = '0';
	}
	else
	{
		*c = *a;
		*d = *b + 1;
	}
}
