/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:50:24 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/04 19:50:26 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_pa(t_deque *a, t_deque *b)
{
	push_bonus(b, a);
}

void	do_pb(t_deque *a, t_deque *b)
{
	push_bonus(b, a);
}

void	do_sa_sb(t_deque *deq)
{
	swap_bonus(deq);
}

void	do_ss(t_deque *a, t_deque *b)
{
	do_sa_sb(a);
	do_sa_sb(b);
}

void	do_ra_rb(t_deque *deq)
{
	reverse_rotate_bonus(deq);
}
