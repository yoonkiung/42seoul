/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:20:53 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/08 12:29:11 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	isin_dec(char *str)
{
	if (ft_strncmp(str, "0", 20) == 0 || ft_strncmp(str, "-1", 20) == 0)
		return (1);
	if (ft_atoi(str) == 0 || ft_atoi(str) == -1)
		return (0);
	return (1);
}

int	check_error(char *str)
{
	if (!is_all_digit(str))
		return (0);
	if (!isin_dec(str))
		return (0);
	return (1);
}

int	input(int ac, char **av, t_deque *a, t_deque *b)
{
	dequeinit(b);
	if (ac == 2)
	{
		if (!input_ac_is_1(av, a))
			return (0);
	}
	else
	{
		if (!input_normal_case(ac, av, a))
			return (0);
	}
	return (1);
}

int	is_all_diff(t_deque *deq)
{
	int		len;
	int		*arr;
	int		i;
	t_node	*temp;

	len = size(deq);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	i = 0;
	temp = deq->tail;
	insert_arr(i, len, arr, temp);
	quicksort(arr, 0, len - 1);
	i = 0;
	while (i < len - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			free(arr);
			return (0);
		}
		i++;
	}
	free(arr);
	return (1);
}
