/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:07:55 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/20 17:07:56 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_next_min(t_deque *deq, int len, int min)
{
	int		next_min;
	t_node	*temp;

	next_min = INT_MAX;
	temp = deq->tail;
	while (len-- > 0)
	{
		if (temp->data > min && next_min > temp->data)
			next_min = temp->data;
		temp = temp->prev;
	}
	return (next_min);
}

void	do_reverse(t_deque *a, t_deque *b, int ra, int rb)
{
	int	len_a;
	int	len_b;

	len_a = deq_len(a);
	len_b = deq_len(b);
	if (len_a == ra || len_b == rb)
	{
		if (len_a == ra && len_b == rb)
			return ;
		else if (len_a == ra)
			while (rb-- > 0)
				reverse_rotate(b, "rrb\n");
		else
			while (ra-- > 0)
				reverse_rotate(a, "rra\n");
		return ;
	}
	rotate_if_diff(a, b, ra, rb);
}

void	init_variable(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

void	do_instruct_a(t_deque *a, t_deque *b, int len)
{
	int	ra;
	int	pb;
	int	rb;
	int	big_pivot;
	int	small_pivot;

	init_variable(&ra, &pb, &rb);
	if (!choose_pivot(a, len, &big_pivot, &small_pivot))
		when_error(a, b);
	while (len-- > 0)
	{
		if (dqgetlast(a) > big_pivot)
		{
			if (is_all_big(a, big_pivot, len + 1))
				break ;
			rotate(a, "ra\n", &ra);
		}
		else
			pb += push_and_rotate_if_a(a, b, &rb, small_pivot);
	}
	do_reverse(a, b, ra, rb);
	q_sort_a(a, b, ra + len + 1);
	q_sort_b(a, b, rb);
	q_sort_b(a, b, pb - rb);
}

void	do_instruct_b(t_deque *a, t_deque *b, int len)
{
	int	ra;
	int	pa;
	int	rb;
	int	big_pivot;
	int	small_pivot;

	init_variable(&ra, &pa, &rb);
	if (!choose_pivot(b, len, &big_pivot, &small_pivot))
		when_error(a, b);
	while (len-- > 0)
	{
		if (dqgetlast(b) < small_pivot)
		{
			if (!is_all_small(b, small_pivot, len + 1))
				rotate(b, "rb\n", &rb);
			else
				break ;
		}
		else
			pa += push_and_rotate_if_b(a, b, &ra, big_pivot);
	}
	q_sort_a(a, b, pa - ra);
	do_reverse(a, b, ra, rb);
	q_sort_a(a, b, ra);
	q_sort_b(a, b, rb + len + 1);
}
