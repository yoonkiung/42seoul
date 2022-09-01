/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:03:35 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/14 11:31:57 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(char i, char j, char k);

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			k = 0;
			while (k < 10)
			{
				if ((k != j && k != i && j != i) && (i < j && i < k && j < k))
					print_comb(i + 48, j + 48, k + 48);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	print_comb(char i, char j, char k)
{
	char	a;
	char	b;

	a = ',';
	b = ' ';
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i == '7' && j == '8' && k == '9')
		return ;
	write(1, &a, 1);
	write(1, &b, 1);
}
