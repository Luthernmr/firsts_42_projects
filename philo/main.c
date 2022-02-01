/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:04:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/02/01 16:54:53 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*take_fork(void *data)
{
	int	philo;

	philo = (int)data;
	printf("philo %d prend une fourchette\n", philo);
	return (NULL);
}

void	philo_routine()
{
	
}

int	main(int argc, char **argv)
{
	int			i;
	int			res;
	int			nb;
	t_setup		setup;

	res = 0;
	i = 0;
	if (argc != 2)
		return (0);
	philo.nb_of_philo = ft_atoi(argv[1]));
	while (i < philo.nb_of_philo)
	{
		setup.philo[i] = pthread_create 
	}
	i = 0;
	while (i < philo.nb_of_philo)
	{
		pthread_join(philo.thread_philo, 0);
		i++;
	}
	//eat = pthread_create(fork, NULL, take_fork, "test");
	return (0);
}
