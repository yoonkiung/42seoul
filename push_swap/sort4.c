/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:19:49 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/28 14:19:51 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pushonlymax(t_deque *a, t_deque *b)
{
	int	first;
	int	second;
	int	third;
	int	empty;

	empty = 0;
	first = b->tail->data;
	second = b->tail->prev->data;
	third = b->tail->prev->prev->data;
	if (first > second && first > third)
		push(b, a, "pa\n", &empty);
	else if (second > first && second > third)
	{
		rotate(b, "rb\n", &empty);
		push(b, a, "pa\n", &empty);
		reverse_rotate(b, "rrb\n");
	}
	else
	{
		rotate(b, "rb\n", &empty);
		rotate(b, "rb\n", &empty);
		push(b, a, "pa\n", &empty);
		reverse_rotate(b, "rrb\n");
		reverse_rotate(b, "rrb\n");
	}
}

void	lenisthree_reverse(t_deque *a, t_deque *b)
{
	int	empty;

	empty = 0;
	pushonlymax(a, b);
	lenistwo(b, "sb\n", 0);
	push(a, b, "pb\n", &empty);
}

void	rotate_if_diff(t_deque *a, t_deque *b, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		reverse_rotate_double(a, b, "rrr\n");
		ra--;
		rb--;
	}
	if (ra == 0 && rb == 0)
		return ;
	else if (ra > 0)
		while (ra-- > 0)
			reverse_rotate(a, "rra\n");
	else
		while (rb-- > 0)
			reverse_rotate(b, "rrb\n");
}

int	already_sorted(t_deque *deq, int len, int dep)
{
	t_node	*temp;

	temp = deq->tail;
	if (dep == 1)
	{
		while (len-- > 1)
		{
			if (temp->data >= temp->prev->data)
				return (0);
			temp = temp->prev;
		}
	}
	else
	{
		while (len-- > 1)
		{
			if (temp->data <= temp->prev->data)
				return (0);
			temp = temp->prev;
		}
	}
	return (1);
}

void	lenisthree_init(t_deque *a)
{
	int	empty;
	int	max;

	if (already_sorted(a, 3, 1))
		return ;
	empty = 0;
	max = find_min_max(a, 1, 3);
	if (a->tail->data == max)
	{
		rotate(a, "ra\n", &empty);
		if (!already_sorted(a, 3, 1))
			swap(a, "sa\n");
		return ;
	}
	else if (a->tail->prev->data == max)
	{
		reverse_rotate(a, "rra\n");
		if (!already_sorted(a, 3, 1))
			swap(a, "sa\n");
	}
	else
		lenistwo(a, "sa\n", 1);
}
