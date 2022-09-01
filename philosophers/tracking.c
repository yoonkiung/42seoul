/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:49:55 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/20 14:49:56 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	solo(int die_time)
{
	printf("0	1	has taken a fork\n");
	sleeping(die_time);
	return (printf("%d	1	died\n", die_time));
}

void	track(t_data *data)
{
	int	i;

	i = 0;
	while (data->all_ate == 0)
	{
		pthread_mutex_lock(&data->life);
		data->ms_current = get_time() - data->time->start;
		if (data->ms_current >= data->philos[i].ms_to_die)
		{
			data->first_dead = i + 1;
			printf("%lld	%d	is dead\n", data->ms_current, data->first_dead);
			pthread_mutex_unlock(&data->life);
			break ;
		}
		data->all_ate = eat_all(data);
		i = (i + 1) % data->nb_philos;
		pthread_mutex_unlock(&data->life);
		usleep(2500);
	}
}

int	eat_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->time->num_max_eat == 0)
		return (0);
	while (i < data->nb_philos)
	{
		if (data->philos[i].eat_count != data->time->num_max_eat)
			return (0);
		i++;
	}
	return (1);
}
