/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:36:43 by kiyoon            #+#    #+#             */
/*   Updated: 2022/07/14 16:36:44 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_arginfo
{
	long long	start;
	int			die_time;
	int			eat_time;
	int			sleep_time;
	int			num_max_eat;
}		t_arginfo;

typedef struct s_philo {
	int				num;
	int				eat_count;
	int				i_fork1;
	int				i_fork2;
	long long		ms_to_die;
	long long		ms_current;
	pthread_t		thread;
	t_arginfo		*time;
	struct s_data	*data;
}	t_philo;

typedef struct s_data {
	int				nb_philos;
	int				first_dead;
	int				all_ate;
	long long		ms_current;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	life;
	t_arginfo		*time;
}	t_data;

int			ft_atoi(const char *str);
int			is_space(char c);
int			print_err(char *str);
void		sleeping(long long die_time);
long long	get_time(void);
void		loop(void *param);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		print_state(t_philo *philo, char *message);
void		think(t_philo *philo);
void		bad(t_philo *philo);
void		eat(t_philo *philo);
void		get_fork(t_philo *philo);
int			mutex(t_data *data);
int			thread(t_data *data);
int			init_and_start(t_data *data);
int			main(int ac, char **av);
void		track(t_data *data);
int			eat_all(t_data *data);
void		destroy_all(t_data *data);
void		free_all(t_data *data);
int			solo(int die_time);

#endif
