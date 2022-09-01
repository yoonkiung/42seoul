/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:42:50 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/22 14:48:32 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_board[10];
int	g_count;

int	abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	check(int locate)
{
	int	i;

	i = 0;
	while (i < locate)
	{
		if (g_board[locate] == g_board[i]
			|| locate - i == abs(g_board[locate] - g_board[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print(int *board, int size)
{
	 int	i;
	char	c;

	i = 0;
	while (i < size)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

void	queen_recursive(int locate)
{
	int	i;

	i = 0;
	if (locate == 10)
	{
		g_count++;
		print(g_board, 10);
		write(1, "\n", 1);
		return ;
	}
	while (i < 10)
	{
		g_board[locate] = i;
		if (check(locate))
			queen_recursive(locate + 1);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	g_count = 0;
	queen_recursive(0);
	return (g_count);
}
