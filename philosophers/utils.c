/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:34:51 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/14 17:34:52 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	sleeping(long long die_time)
{
	long long	current;

	current = get_time();
	while ((get_time() - current) < die_time)
		usleep(128);
}

int	print_err(char *str)
{
	printf("%s\n", str);
	return (0);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	i;
	long long	min;
	long long	ans;

	ans = 0;
	min = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans *= 10;
		ans += str[i++] - '0';
		if (ans * min > 2147483647)
			return (-1);
		if (ans * min < -2147483648)
			return (0);
	}
	ans *= min;
	return ((int)ans);
}
