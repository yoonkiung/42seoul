/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:31:03 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/11 15:31:04 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	dqremovefirst(t_deque *pdeq)
{
	t_node	*temp;
	int		curdata;

	if (dequeisempty(pdeq))
		return (0);
	curdata = pdeq->head->data;
	if (pdeq->head == pdeq->tail)
	{
		free(pdeq->head);
		pdeq->head = NULL;
		pdeq->tail = NULL;
		return (curdata);
	}
	temp = pdeq->head->next;
	pdeq->head->next->prev = NULL;
	pdeq->head->next = NULL;
	free(pdeq->head);
	pdeq->head = temp;
	return (curdata);
}

int	dqremovelast(t_deque *pdeq)
{
	t_node	*temp;
	int		curdata;

	if (dequeisempty(pdeq))
		return (0);
	curdata = pdeq->tail->data;
	if (pdeq->head == pdeq->tail)
		return (dqremovefirst(pdeq));
	temp = pdeq->tail->prev;
	pdeq->tail->prev->next = NULL;
	pdeq->tail->prev = NULL;
	free(pdeq->tail);
	pdeq->tail = temp;
	return (curdata);
}

int	dqgetfirst(t_deque *pdeq)
{
	return (pdeq->head->data);
}

int	dqgetlast(t_deque *pdeq)
{
	return (pdeq->tail->data);
}

void	dqfreeall(t_deque *pdeq)
{
	if (dequeisempty(pdeq))
		return ;
	while (pdeq->head != NULL)
		dqremovelast(pdeq);
}
