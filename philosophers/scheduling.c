/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:13:38 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/19 22:13:40 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_state(philo, "is thinking");
}

void	bad(t_philo *philo)
{
	print_state(philo, "is sleeping");
	sleeping(philo->time->sleep_time);
}

void	eat(t_philo *philo)
{
	print_state(philo, "is eating");
	sleeping(philo->time->eat_time);
	pthread_mutex_unlock(&philo->data->forks[philo->i_fork1]);
	pthread_mutex_unlock(&philo->data->forks[philo->i_fork2]);
}

void	get_fork(t_philo *philo)
{
	if (philo->num % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->i_fork1]);
		pthread_mutex_lock(&philo->data->forks[philo->i_fork2]);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->i_fork2]);
		pthread_mutex_lock(&philo->data->forks[philo->i_fork1]);
	}
	print_state(philo, "has taken a fork");
	print_state(philo, "has taken a fork");
}

void	loop(void *param)
{
	t_philo	*philo;

	philo = param;
	if (philo->num % 2 == 0)
		sleeping(philo->time->eat_time / 2);
	while (1)
	{
		pthread_mutex_lock(&philo->data->life);
		if (philo->data->first_dead)
		{
			pthread_mutex_unlock(&philo->data->life);
			return ;
		}
		pthread_mutex_unlock(&philo->data->life);
		if (philo->time->num_max_eat \
			&& philo->time->num_max_eat == philo->eat_count)
			return ;
		get_fork(philo);
		eat(philo);
		bad(philo);
		think(philo);
	}
}
