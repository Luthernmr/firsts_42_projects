/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:20:22 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/11 13:01:29 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				eat;
	int				sleep;
	int				think;
	int				die;
	int				time_last_meal;
	int				fork_right;
	int				fork_left;
	struct s_setup	*setup;
	pthread_t		thread_id;

}				t_philo;

typedef struct s_setup
{
	int				number_of_philosophers;
	struct timeval	current_time;
	long long		time;
	long long		time_to_eat;
	long long		time_to_die;
	long long		time_to_sleep;
	long long		time_to_think;
	long long		time_must_eat;
	int				someone_died;
	t_philo			*philo;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_sleep;
	pthread_mutex_t	mutex_think;
	pthread_mutex_t	mutex_message;
}				t_setup;

void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_take_fork(t_philo *philo);
void	philo_eat_msg(t_philo *philo);
long	get_time(t_setup *setup);
void	init_mutex(t_setup *setup);
void	init(t_setup *setup, char **argv);
int		ft_atoi(const char *str);

#endif