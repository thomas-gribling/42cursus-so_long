/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:47:02 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/19 13:50:30 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

static void	check_tile(t_game *game, int x, int y)
{
	if (game->map->content[y][x] == 'C')
	{
		game->map->content[y][x] = '0';
		game->items--;
		printf("coins remaining: %d\n", game->items);
	}
	else if (game->map->content[y][x] == 'E')
		close_game(game);
}

// optimize this tomorrow
static int	can_move(t_game *game, int x, int y)
{
	char	c;
	
	c = game->map->content[y][x];
	if (c == '1')
		return (0);
	if (c == 'E' && game->items > 0)
		return (0);
	return (1);
}

void	init_move(t_game *game)
{
	int		x;
	int		y;
	
	x = game->p_pos[0] * TILE_SIZE;
	y = game->p_pos[1] * TILE_SIZE;
	mlx_clear_window(game->mlx, game->win);
	check_tile(game, x / TILE_SIZE, y / TILE_SIZE);
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
		if (can_move(game, p_x, p_y - 1))
			game->p_pos[1]--;
	if (keycode == KEY_D)
		if (can_move(game, p_x + 1, p_y))
			game->p_pos[0]++;
	if (keycode == KEY_S)
		if (can_move(game, p_x, p_y + 1))
			game->p_pos[1]++;
	if (keycode == KEY_A)
		if(can_move(game, p_x - 1, p_y))
			game->p_pos[0]--;
	init_move(game);
}
