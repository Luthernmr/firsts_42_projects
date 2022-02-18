/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:04:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/18 16:32:19 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_setup *setup)
{
	int	i;

	i = 0;
	while (i < setup->number_of_philosophers)
		pthread_mutex_destroy(&(setup->mutex_fork[i++]));
	i = 0;
	pthread_mutex_destroy(&(setup->mutex_message));
	pthread_mutex_destroy(&(setup->mutex_eat));
	pthread_mutex_destroy(&(setup->mutex_last_meal));
	pthread_mutex_destroy(&(setup->mutex_die));
}

int	main(int argc, char **argv)
{
	int			i;
	t_setup		setup;

	if (argc < 5 || argc > 6)
		return (0);
	if (init(&setup, argv) == -1)
		return (-1);
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
	destroy_mutex(&setup);
	return (0);
}
