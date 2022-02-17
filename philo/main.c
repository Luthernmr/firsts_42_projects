/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:04:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/17 17:59:19 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usleep_custom(int time)
{
	usleep(time);
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

int	philo_eat(t_philo *philo)
{
	t_setup	*setup;

	setup = philo->setup;
	pthread_mutex_lock(&(setup->mutex_fork[philo->fork_left]));
	philo_take_fork(philo);
	if (philo->fork_left == philo->fork_right)
	{
		usleep_custom(setup->time_to_die);
		setup->someone_died = 1;
		philo_die_msg(philo);
		return (1);
	}
	pthread_mutex_lock(&(setup->mutex_fork[philo->fork_right]));
	philo_take_fork(philo);
	pthread_mutex_lock(&(setup->mutex_eat));
	philo->eat += 1;
	pthread_mutex_lock(&(setup->mutex_last_meal));
	philo->time_last_meal = get_time(setup) - setup->time;
	pthread_mutex_unlock(&(setup->mutex_last_meal));
	if (philo->eat == setup->nb_must_eat)
		setup->finish_eat += 1;
	pthread_mutex_unlock(&(setup->mutex_eat));
	philo_eat_msg(philo);
	pthread_mutex_unlock(&(setup->mutex_fork[philo->fork_left]));
	pthread_mutex_unlock(&(setup->mutex_fork[philo->fork_right]));
	return (0);
}

void	check_philo_die(t_setup *setup)
{
	int	i;

	i = 0;
	while (!(check_value(setup, &setup->mutex_die, 'd') == 1)
		&& !(check_value(setup, &setup->mutex_eat, 'e')
			== setup->number_of_philosophers))
	{
		i = 0;
		while (i < setup->number_of_philosophers)
		{
			if ((get_time(setup) - setup->time)
				- check_value_2(&setup->philo[i],
					&setup->mutex_last_meal, 'l') > setup->time_to_die)
			{
				pthread_mutex_lock(&(setup->mutex_die));
				setup->someone_died = 1;
				pthread_mutex_unlock(&(setup->mutex_die));
				philo_die_msg(&setup->philo[i]);
				break ;
			}
			if (check_value(setup, &setup->mutex_eat, 'e')
				== setup->number_of_philosophers)
				break ;
			i++;
		}
	}
}

void	*routine_philo(void *phi)
{
	t_philo			*philo;
	t_setup			*setup;	
	int				i;

	i = 0;
	philo = (t_philo *)phi;
	setup = philo->setup;
	if (philo->id % 2 == 0)
	{
		usleep_custom(1000);
		//philo_think(philo);
	}
	while (!(check_value(setup, &setup->mutex_die, 'd') == 1)
		&& !(check_value(setup, &setup->mutex_eat, 'e')
			== setup->number_of_philosophers))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int			i;
	t_setup		setup;

	if (argc < 5 || argc > 6)
		return (0);
	if (init(&setup, argv) == -1)
		return (0);
	i = 0;
	while (i < setup.number_of_philosophers)
	{
		pthread_create(&(setup.philo[i].thread_id), NULL,
			&routine_philo, &(setup.philo[i]));
		i++;
	}
	i = 0;
	check_philo_die(&setup);
	while (i < setup.number_of_philosophers)
		pthread_join(setup.philo[i++].thread_id, NULL);
	i = 0;
	while (i < setup.number_of_philosophers)
		pthread_mutex_destroy(&(setup.mutex_fork[i++]));
	return (0);
}
