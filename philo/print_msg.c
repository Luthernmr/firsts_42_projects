/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:17:44 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/15 17:53:06 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	if (philo->setup->someone_died == 0
		&& philo->setup->finish_eat != philo->setup->number_of_philosophers)
	{
		pthread_mutex_lock(&(philo->setup->mutex_message));
		printf("%lld %d is thinking\n", get_time(philo->setup)
			- philo->setup->time, philo->id);
		pthread_mutex_unlock(&(philo->setup->mutex_message));
	}
}

void	philo_sleep(t_philo *philo)
{
	if (philo->setup->someone_died == 0)
	{
		pthread_mutex_lock(&(philo->setup->mutex_message));
		printf("%lld %d is sleeping\n", get_time(philo->setup)
			- philo->setup->time, philo->id);
		pthread_mutex_unlock(&(philo->setup->mutex_message));
		usleep(philo->setup->time_to_sleep * 1000);
	}
}	

void	philo_take_fork(t_philo *philo)
{
	if (philo->setup->someone_died == 0)
	{
		pthread_mutex_lock(&(philo->setup->mutex_message));
		printf("%lld %d has taken a fork\n", get_time(philo->setup)
			- philo->setup->time, philo->id);
		pthread_mutex_unlock(&(philo->setup->mutex_message));
	}
}

void	philo_eat_msg(t_philo *philo)
{
	if (philo->setup->someone_died == 0)
	{
		pthread_mutex_lock(&(philo->setup->mutex_message));
		printf("%lld %d is eating\n", get_time(philo->setup)
			- philo->setup->time, philo->id);
		pthread_mutex_unlock(&(philo->setup->mutex_message));
		usleep(philo->setup->time_to_eat * 1000);
	}
}

void	philo_die_msg(t_philo *philo)
{
	if (philo->setup->someone_died == 1)
	{
		pthread_mutex_lock(&(philo->setup->mutex_message));
		printf("%lld %d died\n", get_time(philo->setup)
			- philo->setup->time, philo->id);
		pthread_mutex_unlock(&(philo->setup->mutex_message));
	}
}
