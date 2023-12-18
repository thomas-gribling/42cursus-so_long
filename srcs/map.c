/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:07:22 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/18 16:18:09 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

int	get_wall_tex(t_game *game, int x, int y)
{
	int	max_x;
	int	max_y;

	max_x = game->map->width - TILE_SIZE;
	max_y = game->map->height - TILE_SIZE;
	if (y == 0 && x == 0)
		return (TEX_BOUND_0);
	if (y == 0 && x > 0 && x < max_x)
		return (TEX_BOUND_1);
	if (y == 0 && x == max_x)
		return (TEX_BOUND_2);
	if (y > 0 && y < max_y && x == max_x)
		return (TEX_BOUND_3);
	if (y == max_y && x == max_x)
		return (TEX_BOUND_4);
	if (y == max_y && x > 0 && x < max_x)
		return (TEX_BOUND_5);
	if (y == max_y && x == 0)
		return (TEX_BOUND_6);
	if (y > 0 && y < max_y && x == 0)
		return (TEX_BOUND_7);
	return (TEX_WALL);
}

void	place_tile(t_game *game, char c, int x, int y)
{
	t_sprite	t;	

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	if (c == '0' || c == 'C' || c == 'P')
	{
		t = game->textures[0];
		mlx_put_image_to_window(game->mlx, game->win, t.ptr, x, y);
	}
	if (c == '1')
		t = game->textures[get_wall_tex(game, x, y)];
	else if (c == 'C')
		t = game->textures[TEX_COLLECT];
	else if (c == 'E')
		t = game->textures[TEX_EXIT];
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
			place_tile(game, game->map->content[y][x], x, y);
	}
}

int	load_map(t_game *game, char *path)
{
	int	x;
	int	y;

	if (!read_map(game->map, path))
		return (0);
	if (!check_bounds(game->map))
		return (0);
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
				break ;
			}
		}
	}
	return (1);
}
