/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:16:08 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/22 17:16:13 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;
	int	range;

	range = max - min;
	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * range);
	if (!arr)
		return (0);
	i = 0;
	while (i < range)
		arr[i++] = min++;
	return (arr);
}
