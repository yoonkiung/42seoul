/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:58:32 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/27 09:58:35 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	reverse_rotate_double_bonus(t_deque *a, t_deque *b)
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
	return (1);
}
