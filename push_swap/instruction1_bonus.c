/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:34:15 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/15 14:34:17 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap_bonus(t_deque *pdeq)
{
	int	temp;

	if (pdeq->head == pdeq->tail || dequeisempty(pdeq))
		return ;
	temp = dqgetlast(pdeq);
	pdeq->tail->data = pdeq->tail->prev->data;
	pdeq->tail->prev->data = temp;
}

void	push_bonus(t_deque *a, t_deque *b)
{
	t_node	*temp;

	if (dequeisempty(a))
		return ;
	temp = a->tail;
	if (size(a) == 1)
	{
		a->head = NULL;
		a->tail = NULL;
	}
	else
	{
		a->tail = a->tail->prev;
		a->tail->next = NULL;
	}
	if (dequeisempty(b))
	{
		b->head = temp;
		b->tail = temp;
		return ;
	}
	link_to_b(b, temp);
}

void	rotate_bonus(t_deque *deq)
{
	t_node	*temp;

	if (dequeisempty(deq) || deq_len(deq) == 1)
		return ;
	temp = deq->tail;
	deq->tail = temp->prev;
	deq->tail->next = NULL;
	temp->prev = NULL;
	temp->next = deq->head;
	deq->head->prev = temp;
	deq->head = temp;
}

int	reverse_rotate_bonus(t_deque *deq)
{
	int	temp;

	if (dequeisempty(deq) || deq->head == deq->tail)
		return (1);
	temp = dqgetfirst(deq);
	if (!dqaddlast(deq, temp))
		return (0);
	dqremovefirst(deq);
	return (1);
}
