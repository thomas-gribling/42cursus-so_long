/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:07:22 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/15 15:54:14 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

void	place_tile(t_game *game, char c, int x, int y)
{
	t_sprite	t;	

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	if (c == '0')
		t = game->textures[0];
	else if (c == '1')
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
