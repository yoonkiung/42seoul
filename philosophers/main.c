/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:32:45 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/14 17:32:46 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_arginit(int ac, char **av, t_arginfo *time, t_data *data)
{
	if (!(ac == 5 || ac == 6))
		return (0);
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 || \
		ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (0);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (0);
	data->nb_philos = ft_atoi(av[1]);
	time->die_time = ft_atoi(av[2]);
	time->eat_time = ft_atoi(av[3]);
	time->sleep_time = ft_atoi(av[4]);
	data->first_dead = 0;
	if (ac == 6)
		time->num_max_eat = ft_atoi(av[5]);
	else
		time->num_max_eat = -1;
	data->time = time;
	return (1);
}

int	mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->life, NULL))
		return (0);
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL))
			return (0);
	}
	return (1);
}

int	thread(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->nb_philos)
	{
		philo = &data->philos[i];
		philo->num = i + 1;
		philo->eat_count = 0;
		philo->ms_to_die = data->time->die_time;
		philo->data = data;
		philo->i_fork1 = i;
		philo->i_fork2 = (i + 1) % data->nb_philos;
		philo->time = data->time;
		if (pthread_create(&philo->thread, NULL,
				(void *)&loop, (void *) philo) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_and_start(t_data *data)
{
	data->time->start = get_time();
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
		return (print_err("malloc error\n"));
	data->forks = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
	{
		free(data->philos);
		return (print_err("malloc error\n"));
	}
	memset(data->philos, 0, sizeof(t_philo) * data->nb_philos);
	if (!mutex(data))
		return (print_err("mutex error\n"));
	if (!thread(data))
		return (print_err("thread error\n"));
	return (1);
}

int	main(int ac, char **av)
{
	t_arginfo	time;
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	memset(&time, 0, sizeof(t_arginfo));
	if (!is_arginit(ac, av, &time, &data))
	{
		printf("Argument Error\n");
		return (1);
	}
	if (data.nb_philos == 1)
		return (solo(time.die_time));
	if (init_and_start(&data))
	{
		track(&data);
		if (eat_all(&data))
			printf("All philosophers have eaten!\n");
	}
	destroy_all(&data);
	free_all(&data);
	return (0);
}
