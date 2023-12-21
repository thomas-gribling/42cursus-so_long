/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:50:55 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/21 09:40:34 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	dest = malloc(i + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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

void	put_moves(int n)
{
	write(1, "Total moves: ", 13);
	ft_putunsigned(n);
	ft_putchar('\n');
}
