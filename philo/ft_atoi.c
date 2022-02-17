/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:36:04 by lnemor            #+#    #+#             */
/*   Updated: 2021/11/08 15:37:40 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_alpha(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	check_alpha((char *)str);
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		res = res * 10 + str[i] - '0';
		if (res > 2147483647 && sign == 1)
			return (-1);
		if (res > 2147483648 && sign == -1)
			return (-1);
		i++;
	}
	if (sign * res <= 0)
		return (-1);
	return (sign * res);
}
