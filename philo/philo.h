/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:20:22 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/04 15:26:20 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct t_philo
{
	size_t			id;
	int				eat;
	int				sleep;
	int				die;
	pthread_mutex_t	mutex_fork_right;
	pthread_mutex_t	mutex_fork_left;
	pthread_t		thread_id;

}				t_philo;

typedef struct t_setup
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	t_philo			*philo;
	pthread_mutex_t	mutex_fork;
}				t_setup;

#endif