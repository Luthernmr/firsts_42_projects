/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:04:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/04 16:54:07 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo[philo->id].mutex_fork_left);
	printf("philo %d prend une fourchette gauche\n", (int)philo[philo->id].id);
	pthread_mutex_lock(&philo[philo->id].mutex_fork_right);
	printf("philo %d prend une fourchette droite\n", (int)philo[philo->id].id);
	return (NULL);
}

void	*routine_philo(void *set)
{
	t_setup			*setup;

	setup = (t_setup *)set;
	take_fork(setup.philo[philo->id]);
	return (NULL);
}

//void	*do_eat(void *data)

int	main(int argc, char **argv)
{
	int			i;
	int			res;
	t_setup		setup;

	res = 0;
	i = 0;
	if (argc != 2)
		return (0);
	setup.number_of_philosophers = ft_atoi(argv[1]);
	setup.philo = malloc (sizeof(t_philo) * setup.number_of_philosophers);
	pthread_mutex_init(&setup.mutex_fork, NULL);
	while (i < setup.number_of_philosophers)
	{
		setup.philo[i].id = i + 1;
		setup.philo[i].eat = 0;
		setup.philo[i].sleep = 0;
		i++;
	}
	i = 0;
	while (i < setup.number_of_philosophers)
	{
		pthread_create(&(setup.philo[i].thread_id), NULL,
			&routine_philo,
			(void *)setup.philo);
		setup.philo[i].id = i + 1;
		usleep(200);
		i++;
	}

	//eat = pthread_create(fork, NULL, take_fork, "test");
	return (0);
}
