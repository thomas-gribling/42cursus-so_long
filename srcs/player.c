/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:47:02 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/11 18:59:10 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

static int	check_tile(t_game *game, int x, int y)
{
	if (game->map->content[y][x] == 'C')
	{
		game->map->content[y][x] = '0';
		game->items--;
	}
	else if (game->map->content[y][x] == 'E')
	{
		game->moves++;
		if (BONUS_MODE)
			init_screen(game, 1);
		else
		{
			put_msg(game->moves, 1);
			close_game(game);
			return (0);
		}
	}
	return (1);
}

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

int	player_tex(int x_c, int y_c)
{
	if (x_c == 1 && BONUS_MODE)
		return (TEX_PLAYER_R);
	if (x_c == -1 && BONUS_MODE)
		return (TEX_PLAYER_L);
	if (y_c == -1 && BONUS_MODE)
		return (TEX_PLAYER_U);
	return (TEX_PLAYER);
}

// maybe find a more optimized way
void	init_move(t_game *g, int x_c, int y_c)
{
	int		x;
	int		y;
	int		ini[2];
	void	*tmp;

	if (BONUS_MODE && g->is_on_alt)
		return ;
	if (BONUS_MODE)
		update_enemies(g, 1, NULL);
	ini[0] = g->p_pos[0] * TILE_SIZE;
	ini[1] = g->p_pos[1] * TILE_SIZE;
	g->p_pos[0] += x_c;
	g->p_pos[1] += y_c;
	x = g->p_pos[0] * TILE_SIZE;
	y = g->p_pos[1] * TILE_SIZE;
	if (!check_tile(g, x / TILE_SIZE, y / TILE_SIZE))
		return ;
	if (!BONUS_MODE || !g->is_on_alt)
		mlx_put_image_to_window(g->mlx, g->win, g->tex[player_tex(x_c, y_c)].ptr, x, y);
	if (x_c != 0 || y_c != 0)
	{
		tmp = g->tex[TEX_GROUND].ptr;
		if (!BONUS_MODE || (!is_player_replacing(g, 1) && !g->is_on_alt))
			mlx_put_image_to_window(g->mlx, g->win, tmp, ini[0], ini[1]);
		g->moves++;
		if (!BONUS_MODE)
			put_msg(g->moves, 0);
		else
			update_enemies(g, 2, ini);
	}
}

void	player_move(t_game *game, int keycode)
{
	int	p_x;
	int	p_y;

	p_x = game->p_pos[0];
	p_y = game->p_pos[1];
	if (keycode == KEY_W)
		if (can_move(game, p_x, p_y - 1))
			init_move(game, 0, -1);
	if (keycode == KEY_D)
		if (can_move(game, p_x + 1, p_y))
			init_move(game, 1, 0);
	if (keycode == KEY_S)
		if (can_move(game, p_x, p_y + 1))
			init_move(game, 0, 1);
	if (keycode == KEY_A)
		if (can_move(game, p_x - 1, p_y))
			init_move(game, -1, 0);
	if (BONUS_MODE && !game->is_on_alt)
		display_count(game);
}
