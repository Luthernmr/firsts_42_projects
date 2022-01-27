/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:49:16 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/27 14:05:18 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_fd(unsigned int n, int fd, char *base, int *count)
{
	unsigned int	size;
	unsigned int	num;

	size = 0;
	while (base[size])
		size++;
	num = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd, count);
		num = -n;
	}
	else
		num = n;
	if (num >= size)
	{
		ft_putnbr_base_fd(num / size, fd, base, count);
		ft_putchar_fd(*((num % size) + base), fd, count);
	}
	if (num < size)
	{
		ft_putchar_fd(*((num % size) + base), fd, count);
	}
}

char	*ft_putnbr_base_u_fd(unsigned long int n, int fd, char *base, int *count)
{
	unsigned long int	size;
	unsigned long int	num;
	char				*dest;
	int					i;

	size = 0;
	i = -1;
	while (base[size])
		size++;
	num = 0;
	if (n < 0)
	{
		dest[++i] = 0;
		num = -n;
	}
	else
		num = n;
	if (num >= size)
	{
		ft_putnbr_base_u_fd(num / size, fd, base, count);
		dest[i] = (*((num % size) + base), fd, count);
		i++;
	}
	if (num < size)
		dest[i++] = (*((num % size) + base), fd, count);
	return (dest);
}

void	ft_putnbr_fd(int n, int fd, int *count)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd, count);
		num = -n;
	}
	else
		num = n;
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd, count);
		ft_putchar_fd((num % 10) + 48, fd, count);
	}
	if (num < 10)
	{
		ft_putchar_fd((num % 10) + 48, fd, count);
	}
}

void	ft_putnbr_fd_u(unsigned int n, int fd, int *count)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd, count);
		num = -n;
	}
	else
		num = n;
	if (num >= 10)
	{
		ft_putnbr_fd_u(num / 10, fd, count);
		ft_putchar_fd((num % 10) + 48, fd, count);
	}
	if (num < 10)
	{
		ft_putchar_fd((num % 10) + 48, fd, count);
	}
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	int	i;

	if (s == NULL)
	{
		write(fd, "(null)", 6);
		*count += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd, count);
		i++;
	}
}
