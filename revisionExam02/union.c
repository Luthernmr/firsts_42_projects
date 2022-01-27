/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:26:41 by lnemor            #+#    #+#             */
/*   Updated: 2021/12/09 13:01:21 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check(char *str, char c, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if(str[j] == c)
			return(1);
		j++;
	}
	return(0);


}
void ft_union(char *s1,char  *s2)
{
	int i;
	int j;

	j = 0;	
	i = 0;

	while (s1[i])
	{
		if (check(s1, s1[i], i) == 0)
			write(1 , &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (check(s1, s2[j], i) == 0 && check(s2, s2[j], j) == 0)
			write(1 , &s2[j], 1);
		j++;
	}
}


int main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return(0);
}
