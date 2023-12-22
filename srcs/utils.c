/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:50:55 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/22 10:46:00 by tgriblin         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	if (s1)
		free(s1);
	return (s3);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
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
