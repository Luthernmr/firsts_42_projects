/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:20:22 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/18 16:27:38 by lnemor           ###   ########lyon.fr   */
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
	long long		nb_must_eat;
	long long		finish_eat;
	int				someone_died;
	t_philo			philo[500];
	pthread_mutex_t	mutex_fork[500];
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	mutex_message;
}				t_setup;

void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_take_fork(t_philo *philo);
void	philo_eat_msg(t_philo *philo);
void	philo_die_msg(t_philo *philo);
long	get_time(t_setup *setup);
int		init_mutex(t_setup *setup);
int		init(t_setup *setup, char **argv);
int		check_value(t_setup *setup, pthread_mutex_t *mutex, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isspace(char c);
void	usleep_custom(t_setup *setup, long long time);
void	*routine_philo(void *phi);
void	check_philo_die(t_setup *setup);
int		check_value_2(t_philo *philo, pthread_mutex_t *mutex, char c);

#endif