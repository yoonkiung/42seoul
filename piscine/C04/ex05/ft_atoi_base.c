/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:46:20 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/23 13:06:42 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	is_base(char *base)
{
	int	num;
	int	i;
	int	j;

	num = 0;
	if (base == 0 || ft_strlen(base) <= 1)
		return (0);
	while (base[num])
	{
		if (is_space(base[num]) || base[num] == '+' || base[num] == '-')
			return (0);
		num++;
	}
	i = 0;
	while (i < num - 1)
	{
		j = i + 1;
		while (j < num)
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

int	match(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	g_i;
int	g_min;
int	g_j;
int	g_ans;

int	ft_atoi_base(char *str, char *base)
{
	g_i = 0;
	g_min = 1;
	g_ans = 0;
	if (!is_base(base))
		return (0);
	while (is_space(str[g_i]) || str[g_i] == '-' || str[g_i] == '+')
	{
		if (str[g_i] == '-' || str[g_i] == '+')
		{
			if (is_space(str[g_i + 1]))
				return (0);
			if (str[g_i] == '-')
				g_min *= -1;
		}
		g_i++;
	}
	g_j = g_i;
	while (match(str[g_j], base) != -1)
		g_j++;
	while (g_i < g_j && (match(str[g_i], base) != -1))
	{
		g_ans *= ft_strlen(base);
		g_ans += match(str[g_i++], base);
	}
	return (g_ans * g_min);
}
