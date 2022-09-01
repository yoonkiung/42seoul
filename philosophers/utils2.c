/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:16:42 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/20 14:16:43 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_state(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->life);
	philo->ms_current = get_time() - philo->time->start;
	if (!(philo->data->first_dead || philo->data->all_ate))
	{
		printf("%lld	%d	%s\n", philo->ms_current, philo->num, message);
		if (ft_strncmp(message, "is eating", 100) == 0)
		{
			philo->ms_to_die = philo->ms_current + philo->ms_to_die;
			philo->eat_count += 1;
		}
	}
	pthread_mutex_unlock(&philo->data->life);
}

void	destroy_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philos[i].thread, NULL);
	i = -1;
	while (++i < data->nb_philos)
	{
		if (data->forks && &data->forks[i])
			pthread_mutex_destroy(&data->forks[i]);
	}
	pthread_mutex_destroy(&data->life);
}

void	free_all(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}
