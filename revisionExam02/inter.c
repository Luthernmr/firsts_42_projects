/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:49:28 by lnemor            #+#    #+#             */
/*   Updated: 2022/01/05 17:58:56 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_check_exist(char *str, char c, int i)
{
	int j;
	j = 0;

	while (j < i)
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return(0);
}
void ft_inter(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (ft_check_exist(s1, s1[i], i) == 0)
		{
			j = 0;
			while (s2[j])
			{
				if (s1[i] == s2[j])
				{
					ft_putchar(s1[i]);
					break;
				}
				j++;
			}
		}
		i++;
	}
}

int main(int ac, char **av)
{
	 if (ac == 3)
 		ft_inter(av[1], av[2]);
	ft_putchar('\n');
}
