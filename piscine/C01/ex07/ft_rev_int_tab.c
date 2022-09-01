/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:44:54 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/15 22:05:42 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	temp;

	start = 0;
	while (start < size / 2)
	{
		temp = tab[start];
		tab[start] = tab[size - start - 1];
		tab[size - start - 1] = temp;
		start++;
	}
}
