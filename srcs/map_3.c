/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:50:29 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/12 09:09:22 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_player_coordinates(t_game *game)
{
	int	x;
	int	y;

	game->map->width *= TILE_SIZE;
	game->map->height *= TILE_SIZE;
	y = -1;
	while (game->map->content[++y])
	{
		x = -1;
		while (game->map->content[y][++x])
		{
			if (game->map->content[y][x] == 'P')
			{
				game->p_pos[0] = x;
				game->p_pos[1] = y;
			}
		}
	}
}

int	count_chars(t_game *game)
{
	int	count[2];
	int	x;
	int	y;

	count[0] = 0;
	count[1] = 0;
	game->items = 0;
	y = -1;
	while (game->map->content[++y])
	{
		x = -1;
		while (game->map->content[y][++x])
		{
			if (game->map->content[y][x] == 'E')
				count[0]++;
			if (game->map->content[y][x] == 'P')
				count[1]++;
			if (game->map->content[y][x] == 'C')
				game->items++;
		}
	}
	if (count[0] != 1 || count[1] != 1 || game->items < 1)
		return (0);
	return (1);
}

void	check_path(t_game *g, char **tmp, int x, int y)
{
	if (tmp[y][x] == '1' || tmp[y][x] == '2')
		return ;
	if (tmp[y][x] == 'C' || tmp[y][x] == 'E')
		g->map->debug_count--;
	tmp[y][x] = '2';
	check_path(g, tmp, x - 1, y);
	check_path(g, tmp, x + 1, y);
	check_path(g, tmp, x, y - 1);
	check_path(g, tmp, x, y + 1);
}

int	load_map(t_game *game, char *path)
{
	char	**tmp;

	if (!read_map(game->map, path))
		return (-1);
	if (!check_bounds(game->map))
		return (0);
	get_player_coordinates(game);
	if (!count_chars(game))
		return (0);
	game->map->debug_count = game->items + 1;
	tmp = tab_dup(game->map->content, 0);
	check_path(game, tmp, game->p_pos[0], game->p_pos[1]);
	free_tab(tmp);
	if (game->map->debug_count)
		return (0);
	return (1);
}
