/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:35:54 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/10 09:47:00 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*out;

	if (len > ft_strlen(s))
		out = malloc(ft_strlen(s) + 1);
	else
		out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < len && start <= ft_strlen(s))
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

static int	ft_issep(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static int	ft_countwords(char const *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[0] == sep)
		i++;
	while (s[++i])
	{
		if (s[0] != sep && s[1] == sep)
			count++;
		if (i > 0 && !ft_issep(s[i], sep) && ft_issep(s[i - 1], sep))
			count++;
	}
	return (count);
}

static char	**ft_freetabtab(char **tabtab, int curr)
{
	curr--;
	while (curr >= 0)
	{
		free(tabtab[curr]);
		curr--;
	}
	free(tabtab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		start;
	int		i;
	int		j;

	strs = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (ft_freetabtab(strs, 0));
	i = -1;
	j = 0;
	start = 0;
	if (s[0] == c)
		start++;
	while (s[++i])
	{
		if (i > 0 && !ft_issep(s[i], c) && ft_issep(s[i - 1], c))
			start = i;
		if (!ft_issep(s[i], c) && ft_issep(s[i + 1], c))
		{
			strs[j] = ft_substr(s, start, i - start + 1);
			if (strs[j++] == NULL)
				return (ft_freetabtab(strs, j));
		}
	}
	return (strs[j] = NULL, strs);
}
