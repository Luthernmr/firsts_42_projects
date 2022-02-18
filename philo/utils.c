/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:49:42 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/18 14:41:47 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_setup *setup)
{
	long long	t;

	gettimeofday(&setup->current_time, NULL);
	t = setup->current_time.tv_sec * 1000 + setup->current_time.tv_usec / 1000;
	return (t);
}

void	usleep_custom(t_setup *setup, long long time)
{
	long long	i;

	i = get_time(setup);
	while (!(check_value(setup, &setup->mutex_die, 'd') == 1))
	{
		if ((get_time(setup) - i) >= time)
			break ;
		usleep(50);
	}
}

int	check_value(t_setup *setup, pthread_mutex_t *mutex, char c)
{
	int	temp;

	temp = 0;
	pthread_mutex_lock(mutex);
	if (c == 'd')
		temp = setup->someone_died;
	else if (c == 'e')
		temp = setup->finish_eat;
	pthread_mutex_unlock(mutex);
	return (temp);
}

int	check_value_2(t_philo *philo, pthread_mutex_t *mutex, char c)
{
	int	temp;

	temp = 0;
	pthread_mutex_lock(mutex);
	if (c == 'l')
		temp = philo->time_last_meal;
	pthread_mutex_unlock(mutex);
	return (temp);
}
