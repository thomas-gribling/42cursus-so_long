/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:17:11 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/09 10:55:30 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gnl.h"
#include "../include/so_long.h"

static int	get_map_height(t_map *map, char *path)
{
	char	*line;
	int		f;

	f = open(path, O_RDONLY);
	if (f < 0)
		return (-1);
	line = get_next_line(f);
	map->height = 0;
	while (line)
	{
		free(line);
		line = get_next_line(f);
		map->height++;
	}
	close(f);
	return (map->height);
}

static int	check_char(char c, int len, int i)
{
	if (c != '0' && c != '1' && c != 'C')
	{
		if (c != 'E' && c != 'P')
		{
			if (c == '\n')
			{
				if (i != len - 1)
					return (0);
			}
			else
				return (0);
		}
	}
	return (1);
}

static int	check_line(char	*line, int map_width)
{
	int	len;
	int	i;

	if (!line)
		return (1);
	len = ft_strlen(line);
	i = -1;
	while (line[++i])
		if (!check_char(line[i], len, i))
			return (0);
	if (len == map_width && line[len - 1] != '\n')
		return (1);
	if (len - 1 == map_width && line[len - 1] == '\n')
		return (1);
	return (0);
}

int	read_map(t_map *map, char *path)
{
	char	*line;
	int		state;
	int		i;
	int		f;

	if (get_map_height(map, path) <= 0)
		return (0);
	f = open(path, O_RDONLY);
	state = 1;
	line = get_next_line(f);
	map->width = ft_strlen(line);
	if (map->height > 1)
		map->width--;
	map->content = malloc((map->height + 1) * sizeof(char *));
	map->content[0] = ft_strdup(line);
	i = 1;
	while (line)
	{
		free(line);
		line = get_next_line(f);
		if (!check_line(line, map->width))
			state = 0;
		map->content[i++] = ft_strdup(line);
	}
	return (close(f), state);
}

int	check_bounds(t_map *map)
{
	int	i;
	int	s;

	s = map->height - 1;
	i = -1;
	while (map->content[0][++i] && map->content[0][i] != '\n')
		if (map->content[0][i] != '1')
			return (0);
	i = 0;
	while (map->content[++i + 1])
	{
		if (map->content[i][0] != '1')
			return (0);
		if (map->content[i][map->width - 1] != '1')
			return (0);
	}
	i = -1;
	while (map->content[s][++i] && map->content[s][i] != '\n')
		if (map->content[s][i] != '1')
			return (0);
	return (1);
}
