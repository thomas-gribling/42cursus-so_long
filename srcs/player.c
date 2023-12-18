/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:47:02 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/18 11:29:28 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

static int	can_move(char c)
{
	if (c == '1' || c == 'E')
		return (0);
	return (1);
}

int	refresh_player(t_game *game)
{
	void	*t;
	int		x;
	int		y;
	
	t = game->textures[4].ptr;
	x = game->p_pos[0] * TILE_SIZE;
	y = game->p_pos[1] * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, t, x, y);
}

void	player_move(t_game *game, int dir)
{
	int	p_x;
	int	p_y;

	p_x = game->p_pos[0];
	p_y = game->p_pos[1];
	if (dir == MOVE_UP)
		if (can_move(game->map->content[p_y - 1][p_x]))
			game->p_pos[1]--;
	else if (dir == MOVE_RIGHT)
		if (can_move(game->map->content[p_y][p_x + 1]))
			game->p_pos[0]++;
	else if (dir == MOVE_DOWN)
		if (can_move(game->map->content[p_y + 1][p_x]))
			game->p_pos[0]++;
	else if (dir == MOVE_LEFT)
		if(can_move(game->map->content[p_y][p_x - 1]))
			game->p_pos[0]--;
}
