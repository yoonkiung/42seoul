/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:55:49 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/04 19:55:50 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	do_rr(t_deque *a, t_deque *b)
{
	do_ra_rb(a);
	do_ra_rb(b);
}

void	do_rra_rrb(t_deque *deq)
{
	reverse_rotate_bonus(deq);
}

void	do_rrr(t_deque *a, t_deque *b)
{
	do_rra_rrb(a);
	do_rra_rrb(b);
}
