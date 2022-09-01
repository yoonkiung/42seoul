/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 01:21:13 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/23 13:04:30 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	power(int n, int exp)
{
	int	i;

	i = 0;
	if (exp == 0)
		return (1);
	while (i < exp - 1)
	{
		n *= 10;
		i++;
	}
	return (n);
}

void	cal_len_min(int *len, int *min, char *str)
{
	int	i;
	int	to_len;
	int	to_min;

	i = 0;
	to_len = 0;
	to_min = 0;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			to_min++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		to_len++;
		i++;
	}
	*len = to_len;
	if (to_min % 2 == 1)
		*min = -1;
	else
		*min = 1;
}

int	to_int(char n, int exp)
{
	int	ans;

	ans = (n - '0') * power(10, exp);
	return (ans);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	len;
	int	min;
	int	i;
	int	ans;

	i = 0;
	ans = 0;
	cal_len_min(&len, &min, str);
	len--;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] != '-' && str[i] != '+' && !is_space(str[i]))
			return (0);
		if ((str[i] == '-' || str[i] == '+') && is_space(str[i + 1]))
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ans += to_int(str[i++], len--);
	return (ans * min);
}
