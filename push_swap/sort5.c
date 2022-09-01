/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:06:25 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/04 01:06:32 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_all_big(t_deque *deq, int big_pivot, int len)
{
	t_node	*temp;
	int		empty;

	empty = 0;
	temp = deq->tail;
	while (len-- > 0)
	{
		if (temp->data < big_pivot)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

int	push_and_rotate_if_a(t_deque *a, t_deque *b, int *rb, int small_pivot)
{
	int	empty;

	empty = 0;
	push(a, b, "pb\n", &empty);
	if (dqgetlast(b) > small_pivot)
		rotate(b, "rb\n", rb);
	return (1);
}

int	is_all_small(t_deque *deq, int small_pivot, int len)
{
	t_node	*temp;
	int		empty;

	empty = 0;
	temp = deq->tail;
	while (len-- > 0)
	{
		if (temp->data >= small_pivot)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

int	push_and_rotate_if_b(t_deque *a, t_deque *b, int *ra, int big_pivot)
{
	int	empty;

	empty = 0;
	push(b, a, "pa\n", &empty);
	if (dqgetlast(a) < big_pivot)
		rotate(a, "ra\n", ra);
	return (1);
}

int	rotate_if_b(t_deque *b, int pb, int *rb, int small_pivot)
{
	if (size(b) == pb && is_all_big(b, small_pivot, pb))
	{
		(*rb)++;
		return (0);
	}
	rotate(b, "rb\n", rb);
	return (1);
}
