/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:07:22 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/18 10:09:31 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/get_next_line.h"
#include "../include/so_long.h"

void	place_tile(t_game *game, char c, int x, int y)
{
	t_sprite	t;	

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	t = game->textures[0];
	mlx_put_image_to_window(game->mlx, game->win, t.ptr, x, y);
	if (c == '1')
		t = game->textures[1];
	else if (c == 'C')
		t = game->textures[2];
	else if (c == 'E')
		t = game->textures[3];
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->win, t.ptr, x, y);
}

void	generate_map(t_game *game, t_map map)
{
	int	x;
	int	y;

	y = -1;
	while (map.content[++y])
	{
		x = -1;
		while (map.content[y][++x])
			place_tile(game, map.content[y][x], x, y);
	}
}

int	get_map_height(char *path)
{
	char	*line;
	int		height;
	int		f;

	f = open(path, O_RDONLY);
	line = get_next_line(f);
	height = 0;
	while (line)
	{
		free(line);
		line = get_next_line(f);
		height++;
	}
	close(f);
	return (height);
}

int	check_line(char	*line, int map_width)
{
	int	len;
	int	i;

	if (!line)
		return (1);
	len = ft_strlen(line);
	i = -1;
	while (line[++i])
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C')
			if (line[i] != 'E' && line[i] != 'P')
				if (line[i] == '\n')
				{
					if (i != len - 1)
						return (0);
				}
				else
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

	map->height = get_map_height(path);
	f = open(path, O_RDONLY);
	state = 1;
	line = get_next_line(f);
	if (!line || !map->height)
		return (close(f), 0);
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
		map->content[i] = ft_strdup(line);
		i++;
	}
	close(f);
	return (state);
}

int	load_map(t_map *map, char *path)
{
	if (!read_map(map, path))
		return (0);
	map->width *= TILE_SIZE;
	map->height *= TILE_SIZE;
}
