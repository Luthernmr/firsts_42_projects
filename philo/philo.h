/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:20:22 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/07 18:14:13 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include "libft/libft.h"
# include <stdio.h>
# include <time.h>

typedef struct s_philo
{
	int				id;
	int				eat;
	int				sleep;
	int				think;
	int				die;
	int				fork_right;
	int				fork_left;
	struct s_setup	*setup;
	pthread_t		thread_id;

}				t_philo;

typedef struct s_setup
{
	int				number_of_philosophers;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	int				someone_died;
	t_philo			*philo;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_eat;
}				t_setup;

#endif