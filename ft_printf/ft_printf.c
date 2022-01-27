/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:00:32 by lnemor            #+#    #+#             */
/*   Updated: 2021/12/02 14:58:54 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	(*count) += write(fd, &c, 1);
}

void	ft_print_arg(va_list list, char c, int *count)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(list, int), 1, count);
	else if (c == 's')
		ft_putstr_fd(va_arg(list, char *), 1, count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd((va_arg(list, int)), 1, count);
	else if (c == 'u')
		ft_putnbr_fd_u((va_arg(list, unsigned int)), 1, count);
	else if (c == '%')
		ft_putchar_fd('%', 1, count);
	else if (c == 'x')
		ft_putnbr_base_fd((va_arg(list, unsigned int)), 1,
			"0123456789abcdef", count);
	else if (c == 'X')
		ft_putnbr_base_fd((va_arg(list, unsigned int)), 1,
			"0123456789ABCDEF", count);
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1, count);
		ft_putnbr_base_u_fd((va_arg(list, unsigned long int)), 1,
			"0123456789abcdef", count);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;
	int		count;

	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_print_arg(list, str[i + 1], &count);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1, &count);
		i++;
	}
	va_end(list);
	return (count);
}
