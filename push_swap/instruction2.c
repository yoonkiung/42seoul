/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:58:32 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/27 09:58:35 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	reverse_rotate_double(t_deque *a, t_deque *b, char *str)
{
	int	temp;

	if (dequeisempty(a) || a->head == a->tail
		|| dequeisempty(b) || b->head == b->tail)
		return (1);
	temp = dqgetfirst(a);
	if (!dqaddlast(a, temp))
		return (0);
	dqremovefirst(a);
	temp = dqgetfirst(b);
	if (!dqaddlast(b, temp))
		return (0);
	dqremovefirst(b);
	ft_putstr_fd(str, 1);
	return (1);
}

int	size(t_deque *pdeq)
{
	int		count;
	t_node	*temp;

	count = 1;
	temp = pdeq->head;
	if (dequeisempty(pdeq))
		return (0);
	while (pdeq->head != pdeq->tail)
	{
		count++;
		pdeq->head = pdeq->head->next;
	}
	pdeq->head = temp;
	return (count);
}
