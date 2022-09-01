/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:04:25 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/20 16:04:27 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	lenistwo(t_deque *a, char *str, int dep)
{
	if (dep == 1)
	{
		if (a->tail->data > a->tail->prev->data)
			swap(a, str);
		return ;
	}
	if (a->tail->data < a->tail->prev->data)
		swap(a, str);
	return ;
}

void	pushonlyleast(t_deque *a, t_deque *b)
{
	int	first;
	int	second;
	int	third;
	int	empty;

	empty = 0;
	first = a->tail->data;
	second = a->tail->prev->data;
	third = a->tail->prev->prev->data;
	if (first < second && first < third)
		push(a, b, "pb\n", &empty);
	else if (second < first && second < third)
	{
		rotate(a, "ra\n", &empty);
		push(a, b, "pb\n", &empty);
		reverse_rotate(a, "rra\n");
	}
	else
	{
		rotate(a, "ra\n", &empty);
		rotate(a, "ra\n", &empty);
		push(a, b, "pb\n", &empty);
		reverse_rotate(a, "rra\n");
		reverse_rotate(a, "rra\n");
	}
}

void	lenisthree(t_deque *a, t_deque *b)
{
	int	empty;

	empty = 0;
	if (already_sorted(a, 3, 1))
		return ;
	if (size(a) == 3)
	{
		lenisthree_init(a);
		return ;
	}
	pushonlyleast(a, b);
	lenistwo(a, "sa\n", 1);
	push(b, a, "pa\n", &empty);
}

int	find_min_max(t_deque *a, int dep, int len)
{
	int		ans;
	int		i;
	t_node	*temp;

	temp = a->tail;
	i = 0;
	if (dep == 1)
	{
		ans = INT_MIN;
		while (i++ < len)
		{
			if (ans < temp->data)
				ans = temp->data;
			temp = temp->prev;
		}
		return (ans);
	}
	ans = INT_MAX;
	while (i++ < len)
	{
		if (ans > temp->data)
			ans = temp->data;
		temp = temp->prev;
	}
	return (ans);
}

void	lenisfive(t_deque *a, t_deque *b)
{
	int	next_min;
	int	min;
	int	i;
	int	empty;

	if (already_sorted(a, 5, 1))
		return ;
	empty = 0;
	i = 0;
	min = find_min_max(a, 0, 5);
	next_min = find_next_min(a, 5, min);
	while (i++ < 5)
	{
		if (a->tail->data == min || a->tail->data == next_min)
			push(a, b, "pb\n", &empty);
		else
			rotate(a, "ra\n", &empty);
	}
	i = 0;
	if (size(a) > 3)
		while (i++ < 3)
			reverse_rotate(a, "rra\n");
	lenistwo(b, "sb\n", 0);
	lenisthree(a, b);
	push_iter(b, a, "pa\n", 2);
}
