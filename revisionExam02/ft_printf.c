/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:07:56 by lnemor            #+#    #+#             */
/*   Updated: 2021/12/16 09:44:10 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c, int *count)
{
	(*count) += write(1, &c, 1);
}

void	ft_putstr(char *str, int *count)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
	{
		ft_putchar('-', count);
		num = -n;
	}
	else
		num = n;
	if (num >= 10)
	{
		ft_putnbr(num / 10, count);
		ft_putchar((num % 10) + 48, count);
	}
	if (num < 10)
	{
		ft_putchar((num % 10) + 48, count);
	}
}

void	ft_putnbr_base(unsigned int n, char *base, int *count)
{
	unsigned int num;
	unsigned int size;

	size = 0;
	while (base[size])
		size++;
	num = 0;
	printf("[%s]\n",  base);
	if (n < 0)
	{
		ft_putchar('-', count);
		num = -n;
	}
	else
		num = n;
	if (num >= size)
	{
		ft_putnbr_base((num / size), base, count);
		ft_putchar(*((num % size) + base), count);
	}
	if (num < size)
		ft_putchar(*((num % size) + base), count);
}

void	ft_print_arg(va_list list, char c, int *count)
{
	if (c == 's')
		ft_putstr(va_arg(list, char *), count);
	else if (c == 'd')
		ft_putnbr(va_arg(list, int), count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef", count);
}

int ft_printf(char *str, ...)
{
	int 	i;
	va_list	list;
	int 	count;

	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_print_arg(list, str[i + 1], &count);
			i++;
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(list);
	return(count);
}

int main()
{
	ft_printf("%d\n", ft_printf("%x\n", 25558));
	printf("%d\n", printf("%x\n", 25558));
}
