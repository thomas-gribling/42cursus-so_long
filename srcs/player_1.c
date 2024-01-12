/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:47:02 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/12 15:07:41 by tgriblin         ###   ########.fr       */
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
		if (BONUS_MODE)
			change_exit(game);
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

static int	player_tex(int x_c, int y_c)
{
	if (x_c == 1 && BONUS_MODE)
		return (TEX_PLAYER_R);
	if (x_c == -1 && BONUS_MODE)
		return (TEX_PLAYER_L);
	if (y_c == -1 && BONUS_MODE)
		return (TEX_PLAYER_U);
	return (TEX_PLAYER);
}

static void	do_move(t_game *g, int *ini, int x_c, int y_c)
{
	void	*tmp;
	int		x;
	int		y;

	x = g->p_pos[0] * TILE_SIZE;
	y = g->p_pos[1] * TILE_SIZE;
	if (!BONUS_MODE || !g->is_on_alt)
	{
		tmp = g->tex[player_tex(x_c, y_c)].ptr;
		mlx_put_image_to_window(g->mlx, g->win, tmp, x, y);
	}
	if (x_c != 0 || y_c != 0)
	{
		tmp = g->tex[TEX_GROUND].ptr;
		if (!BONUS_MODE || (!is_player_replacing(g, 1) && !g->is_on_alt))
			mlx_put_image_to_window(g->mlx, g->win, tmp, ini[0], ini[1]);
		g->moves++;
		if (!BONUS_MODE)
			put_msg(g->moves, 0);
	}
}

void	init_move(t_game *g, int x_c, int y_c)
{
	int		x;
	int		y;
	int		ini[2];

	if (BONUS_MODE && g->is_on_alt)
		return ;
	ini[0] = g->p_pos[0] * TILE_SIZE;
	ini[1] = g->p_pos[1] * TILE_SIZE;
	g->p_pos[0] += x_c;
	g->p_pos[1] += y_c;
	x = g->p_pos[0] * TILE_SIZE;
	y = g->p_pos[1] * TILE_SIZE;
	if (!check_tile(g, x / TILE_SIZE, y / TILE_SIZE))
		return ;
	do_move(g, ini, x_c, y_c);
}
