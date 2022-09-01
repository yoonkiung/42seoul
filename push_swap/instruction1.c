/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:34:15 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/15 14:34:17 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_deque *pdeq, char *str)
{
	int	temp;

	if (pdeq->head == pdeq->tail || dequeisempty(pdeq))
		return ;
	temp = dqgetlast(pdeq);
	pdeq->tail->data = pdeq->tail->prev->data;
	pdeq->tail->prev->data = temp;
	ft_putstr_fd(str, 1);
}

void	push(t_deque *a, t_deque *b, char *str, int *count)
{
	t_node	*temp;

	if (dequeisempty(a))
		return ;
	(*count)++;
	ft_putstr_fd(str, 1);
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

void	link_to_b(t_deque *b, t_node *temp)
{
	temp->prev = b->tail;
	b->tail->next = temp;
	b->tail = temp;
}

void	rotate(t_deque *deq, char *str, int	*count)
{
	t_node	*temp;

	(*count)++;
	if (dequeisempty(deq) || deq_len(deq) == 1)
		return ;
	ft_putstr_fd(str, 1);
	temp = deq->tail;
	deq->tail = temp->prev;
	deq->tail->next = NULL;
	temp->prev = NULL;
	temp->next = deq->head;
	deq->head->prev = temp;
	deq->head = temp;
}

int	reverse_rotate(t_deque *deq, char *str)
{
	int	temp;

	if (dequeisempty(deq) || deq->head == deq->tail)
		return (1);
	temp = dqgetfirst(deq);
	if (!dqaddlast(deq, temp))
		return (0);
	dqremovefirst(deq);
	ft_putstr_fd(str, 1);
	return (1);
}
