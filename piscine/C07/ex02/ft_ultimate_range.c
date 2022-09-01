/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:17:06 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/22 18:22:30 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*new;
	int	bound;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	bound = max - min;
	new = (int *)malloc(sizeof(int) * bound);
	if (!new)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (i < bound)
		new[i++] = min++;
	*range = new;
	return (bound);
}
