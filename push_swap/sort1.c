/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:11:33 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/04 18:23:21 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	choose_pivot(t_deque *deq, int len, int *big_pivot, int *small_pivot)
{
	t_node	*temp;
	int		i;
	int		*arr;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	i = 0;
	temp = deq->tail;
	while (i < len)
	{
		arr[i++] = temp->data;
		temp = temp->prev;
	}
	quicksort(arr, 0, len - 1);
	*small_pivot = arr[len / 3];
	*big_pivot = arr[2 * (len / 3)];
	free(arr);
	return (1);
}

void	q_sort_a(t_deque *a, t_deque *b, int len)
{
	if (already_sorted(a, len, 1))
		return ;
	if (len <= 2 || len == 3 || len == 5)
	{
		if (len == 2)
			lenistwo(a, "sa\n", 1);
		if (len == 3)
			lenisthree(a, b);
		if (len == 5)
			lenisfive(a, b);
		return ;
	}
	do_instruct_a(a, b, len);
}

void	q_sort_b(t_deque *a, t_deque *b, int len)
{
	int	empty;

	empty = 0;
	if (already_sorted(b, len, 0))
	{
		push_iter(b, a, "pa\n", len);
		return ;
	}
	if (size(b) == 3)
	{
		lenisthree_in_b(a, b);
		return ;
	}
	if (len <= 2)
	{
		if (len == 2)
		{
			lenistwo(b, "sb\n", 0);
			push_iter(b, a, "pa\n", 2);
		}
		else if (len == 1)
			push(b, a, "pa\n", &empty);
		return ;
	}
	do_instruct_b(a, b, len);
}

void	lenisthree_in_b(t_deque *a, t_deque *b)
{
	int	empty;

	empty = 0;
	if (find_min_max(b, 1, 3) == b->tail->data)
	{
		push(b, a, "pa\n", &empty);
		lenistwo(b, "sb\n", 0);
		push_iter(b, a, "pa\n", 2);
	}
	else if (find_min_max(b, 1, 3) == b->tail->prev->data)
	{
		rotate(b, "rb\n", &empty);
		push(b, a, "pa\n", &empty);
		lenistwo(b, "sb\n", 0);
		push_iter(b, a, "pa\n", 2);
	}
	else
	{
		reverse_rotate(b, "rrb\n");
		push(b, a, "pa\n", &empty);
		lenistwo(b, "sb\n", 0);
		push_iter(b, a, "pa\n", 2);
	}
}

void	push_iter(t_deque *from, t_deque *to, char *str, int count)
{
	int	empty;

	empty = 0;
	while (count-- > 0)
		push(from, to, str, &empty);
}
