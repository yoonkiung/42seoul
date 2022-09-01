/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:54:12 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/05 00:58:49 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_deque	deq_a;
	t_deque	deq_b;
	char	*instruction;

	if (!input(ac, av, &deq_a, &deq_b))
		return (0);
	if (!is_all_diff(&deq_a))
		when_error(&deq_a, &deq_b);
	instruction = get_next_line(1);
	if (!instruction)
		return (0);
	while (instruction)
	{
		if (!check_instruction(instruction))
		{
			when_error(&deq_a, &deq_b);
			free(instruction);
			return (0);
		}
		launch(&deq_a, &deq_b, instruction);
		instruction = get_next_line(1);
	}
	is_sorted_and_print(&deq_a, &deq_b);
	free(instruction);
	return (0);
}

void	launch(t_deque *a, t_deque *b, char *str)
{
	if (ft_strncmp(str, "sa\n", 10) != 0)
		do_sa_sb(a);
	if (ft_strncmp(str, "sb\n", 10) != 0)
		do_sa_sb(b);
	if (ft_strncmp(str, "ss\n", 10) != 0)
		do_ss(a, b);
	if (ft_strncmp(str, "pa\n", 10) != 0)
		do_pa(a, b);
	if (ft_strncmp(str, "pb\n", 10) != 0)
		do_pb(a, b);
	if (ft_strncmp(str, "ra\n", 10) != 0)
		do_ra_rb(a);
	if (ft_strncmp(str, "rb\n", 10) != 0)
		do_ra_rb(b);
	if (ft_strncmp(str, "rrr\n", 10) != 0)
		do_rrr(a, b);
}

int	check_instruction(char *str)
{
	if (ft_strncmp(str, "sa\n", 10) != 0 || ft_strncmp(str, "sb\n", 10) != 0
		|| ft_strncmp(str, "ss\n", 10) != 0 || ft_strncmp(str, "pa\n", 10) != 0
		|| ft_strncmp(str, "pb\n", 10) != 0 || ft_strncmp(str, "ra\n", 10) != 0
		|| ft_strncmp(str, "rb\n", 10) != 0 || ft_strncmp(str, "rr\n", 10) != 0
		|| ft_strncmp(str, "rra\n", 10) != 0 || ft_strncmp(str, "rrb\n", 10) != 0
		|| ft_strncmp(str, "rrr\n", 10) != 0)
		return (1);
	return (0);
}

void	is_sorted_and_print(t_deque *a, t_deque *b)
{
	if (!dequeisempty(b))
	{
		printf("1\n");
		ft_putstr_fd("KO\n", 1);
		dqfreeall(a);
		dqfreeall(b);
		return ;
	}
	if (already_sorted(a, size(a), 1))
	{
		printf("2\n");
		ft_putstr_fd("OK\n", 1);
		dqfreeall(a);
		dqfreeall(b);
		return ;
	}
	dqfreeall(a);
	dqfreeall(b);
	ft_putstr_fd("KO\n", 1);
}
