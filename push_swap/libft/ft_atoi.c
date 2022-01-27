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

#include "libft.h"

static void	return_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(0);
}

static void	check_alpha(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return_error();
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 1)
			return_error();
		i++;
	}
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
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		res = res * 10 + str[i] - '0';
		if (res > 2147483647 && sign == 1)
			return_error();
		if (res > 2147483648 && sign == -1)
			return_error();
		i++;
	}
	return (sign * res);
}
