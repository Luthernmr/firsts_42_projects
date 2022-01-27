/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:04:20 by lnemor            #+#    #+#             */
/*   Updated: 2021/12/02 14:04:20 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putnbr_fd_u(unsigned int n, int fd, int *count);
int		ft_printf(const char *str, ...);
void	ft_putnbr_base_fd(unsigned int n, int fd, char *base, int *count);
void	ft_putnbr_base_u_fd(unsigned long int n, int fd, char *base,
			int *count);
void	ft_print_arg(va_list list, char c, int *count);

#endif