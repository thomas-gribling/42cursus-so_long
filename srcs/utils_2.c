/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:37:26 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/09 09:39:49 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	**tab_dup(char **tab, int start)
{
	char	**out;
	int		i;

	i = 0;
	while (tab[start + i])
		i++;
	out = malloc((i + 1) * sizeof(char *));
	i = start - 1;
	while (tab[++i])
		out[i - start] = ft_strdup(tab[i]);
	out[i - start] = NULL;
	return (out);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putunsigned(unsigned int n)
{
	if (n > 9)
		ft_putunsigned(n / 10);
	ft_putchar(n % 10 + '0');
}

void	put_msg(int n, int end)
{
	if (end)
	{
		write(1, "GG! You won in ", 15);
		ft_putunsigned(n);
		write(1, " moves!\n", 8);
	}
	else
	{
		write(1, "Total moves: ", 13);
		ft_putunsigned(n);
		ft_putchar('\n');
	}
}
