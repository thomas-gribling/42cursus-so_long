/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:07:22 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/16 09:12:50 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"
#include <math.h>

int	get_wall_tex(t_game *game, int x, int y)
{
	int	max_x;
	int	max_y;

	max_x = game->map->width - TILE_SIZE;
	max_y = game->map->height - TILE_SIZE;
	if (y == 0 || x == 0 || y == max_y || x == max_x)
		return (TEX_BOUND);
	return (TEX_WALL);
}

void	place_tile(t_game *game, char c, int x, int y)
{
	t_sprite	t;
	int			tex;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	if (c == '0')
	{
		t = game->tex[0];
		mlx_put_image_to_window(game->mlx, game->win, t.ptr, x, y);
	}
	if (c == '1')
		t = game->tex[get_wall_tex(game, x, y)];
	else if (c == 'C')
	{
		tex = rand() % (TEX_COLLECT_5 - TEX_COLLECT_0 + 1) + TEX_COLLECT_0;
		t = game->tex[tex];
	}
	else if (c == 'E')
		t = game->tex[TEX_EXIT + (TEX_EXIT_CLOSED - TEX_EXIT) * BONUS_MODE];
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->win, t.ptr, x, y);
}

void	generate_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map->content[++y])
	{
		x = -1;
		while (game->map->content[y][++x])
		{
			if (BONUS_MODE && game->map->content[y][x] == 'E')
			{
				game->e_pos[0] = x * TILE_SIZE;
				game->e_pos[1] = y * TILE_SIZE;
			}
			place_tile(game, game->map->content[y][x], x, y);
		}
	}
}
