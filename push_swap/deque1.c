/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:47:34 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/11 14:47:37 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dequeinit(t_deque *pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int	dequeisempty(t_deque *pdeq)
{
	if (pdeq->head == NULL)
		return (TRUE);
	return (FALSE);
}

int	dqaddfirst(t_deque *pdeq, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
	{
		dqfreeall(pdeq);
		return (0);
	}
	newnode->data = data;
	newnode->prev = NULL;
	if (dequeisempty(pdeq))
	{
		newnode->next = NULL;
		pdeq->tail = newnode;
	}
	else
	{
		newnode->next = pdeq->head;
		pdeq->head->prev = newnode;
	}
	pdeq->head = newnode;
	return (1);
}

int	dqaddlast(t_deque *pdeq, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
	{
		dqfreeall(pdeq);
		return (0);
	}
	newnode->data = data;
	newnode->prev = pdeq->tail;
	if (dequeisempty(pdeq))
		pdeq->head = newnode;
	else
		pdeq->tail->next = newnode;
	newnode->next = NULL;
	pdeq->tail = newnode;
	return (1);
}

int	deq_len(t_deque *deq)
{
	t_node	*temp;
	int		i;

	if (!deq)
		return (0);
	temp = deq->head;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
