/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:47:02 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/18 15:57:32 by tgriblin         ###   ########.fr       */
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

void	init_move(t_game *game)
{
	void	*t;
	int		x;
	int		y;
	
	x = game->p_pos[0] * TILE_SIZE;
	y = game->p_pos[1] * TILE_SIZE;
	mlx_clear_window(game->mlx, game->win);
	generate_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->textures[TEX_PLAYER].ptr, x, y);
}

void	player_move(t_game *game, int keycode)
{
	int	p_x;
	int	p_y;

	p_x = game->p_pos[0];
	p_y = game->p_pos[1];
	if (keycode == KEY_W)
		if (can_move(game->map->content[p_y - 1][p_x]))
			game->p_pos[1]--;
	if (keycode == KEY_D)
		if (can_move(game->map->content[p_y][p_x + 1]))
			game->p_pos[0]++;
	if (keycode == KEY_S)
		if (can_move(game->map->content[p_y + 1][p_x]))
			game->p_pos[1]++;
	if (keycode == KEY_A)
		if(can_move(game->map->content[p_y][p_x - 1]))
			game->p_pos[0]--;
	init_move(game);
}
