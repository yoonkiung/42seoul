/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:00:52 by kiyoon            #+#    #+#             */
/*   Updated: 2022/03/04 18:29:30 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "./libft/libft.h"
# include <limits.h>
# define TRUE 1

# define FALSE 0

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
}	t_deque;

int		is_all_digit(char *str);

int		isin_dec(char *str);

int		check_error(char *str);

int		input(int ac, char **av, t_deque *a, t_deque *b);

int		is_all_diff(t_deque *deq);

void	when_error(t_deque *a, t_deque *b);

int		input_normal_case(int ac, char **av, t_deque *deq);

int		input_ac_is_1(char **av, t_deque *deq);

int		put_deq(int ac, char **av, t_deque *deq);

void	insert_arr(int i, int len, int *arr, t_node *temp);

void	dequeinit(t_deque *pdeq);

int		dequeisempty(t_deque *pdeq);

int		dqaddfirst(t_deque *pdeq, int data);

int		dqaddlast(t_deque *pdeq, int data);

int		dqremovefirst(t_deque *pdeq);

int		dqremovelast(t_deque *pdeq);

int		dqgetfirst(t_deque *pdeq);

int		dqgetlast(t_deque *pdeq);

void	dqfreeall(t_deque *pdeq);

int		deq_len(t_deque *deq);

void	swap(t_deque *pdeq, char *str);

void	push(t_deque *a, t_deque *b, char *str, int *count);

void	link_to_b(t_deque *b, t_node *temp);

void	rotate(t_deque *deq, char *str, int	*count);

int		reverse_rotate(t_deque *deq, char *str);

int		reverse_rotate_double(t_deque *a, t_deque *b, char *str);

void	swap_bonus(t_deque *pdeq);

void	push_bonus(t_deque *a, t_deque *b);

void	rotate_bonus(t_deque *deq);

int		reverse_rotate_bonus(t_deque *deq);

int		reverse_rotate_double_bonus(t_deque *a, t_deque *b);

int		size(t_deque *pdeq);

int		choose_pivot(t_deque *deq, int len, int *big_pivot, int *small_pivot);

void	q_sort_a(t_deque *a, t_deque *b, int len);

void	q_sort_b(t_deque *a, t_deque *b, int len);

void	lenisthree_in_b(t_deque *a, t_deque *b);

void	push_iter(t_deque *from, t_deque *to, char *str, int count);

void	lenistwo(t_deque *a, char *str, int dep);

void	pushonlyleast(t_deque *a, t_deque *b);

void	lenisthree(t_deque *a, t_deque *b);

int		find_min_max(t_deque *a, int dep, int len);

void	lenisfive(t_deque *a, t_deque *b);

void	sort_five_last(t_deque *a, t_deque *b);

void	do_reverse(t_deque *a, t_deque *b, int ra, int rb);

void	init_variable(int *a, int *b, int *c);

void	do_instruct_a(t_deque *a, t_deque *b, int len);

void	do_instruct_b(t_deque *a, t_deque *b, int len);

int		is_all_big(t_deque *deq, int big_pivot, int len);

int		push_and_rotate_if_a(t_deque *a, t_deque *b, int *rb, int small_pivot);

int		push_and_rotate_if_b(t_deque *a, t_deque *b, int *ra, int big_pivot);

int		rotate_if_b(t_deque *b, int pb, int *rb, int small_pivot);

int		is_all_small(t_deque *deq, int small_pivot, int len);

void	pushonlymax(t_deque *a, t_deque *b);

void	lenisthree_reverse(t_deque *a, t_deque *b);

void	rotate_if_diff(t_deque *a, t_deque *b, int ra, int rb);

int		already_sorted(t_deque *deq, int len, int dep);

void	lenisthree_init(t_deque *a);

int		find_next_min(t_deque *deq, int len, int min);

void	swap_arr(int arr[], int a, int b);

int		partition(int arr[], int left, int right);

void	quicksort(int arr[], int left, int right);

int		check_instruction(char *str);

void	is_sorted_and_print(t_deque *a, t_deque *b);

void	launch(t_deque *a, t_deque *b, char *str);

void	do_pa(t_deque *a, t_deque *b);

void	do_pb(t_deque *a, t_deque *b);

void	do_sa_sb(t_deque *deq);

void	do_ss(t_deque *a, t_deque *b);

void	do_ra_rb(t_deque *deq);

void	do_rr(t_deque *a, t_deque *b);

void	do_rra_rrb(t_deque *deq);

void	do_rrr(t_deque *a, t_deque *b);

#endif
