/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:04:04 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/16 09:16:36 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../mlx/mlx.h"

void	update_enemies(t_game *g, int *ini, int *new)
{
	t_sprite	t;
	int			x;
	int			y;
	int			i;

	if (!g->map->e)
		return ;
	i = -1;
	while (g->map->e[++i])
	{
		g->map->e[i]->player_rep = 0;
		x = g->map->e[i]->x * TILE_SIZE;
		y = g->map->e[i]->y * TILE_SIZE;
		t = g->tex[TEX_GROUND];
		mlx_put_image_to_window(g->mlx, g->win, t.ptr, x, y);
	}
	move_enemies(g);
	if (should_player_die(g, ini, new))
		init_screen(g, 0);
}

int	is_player_replacing(t_game *g, int tester)
{
	int	i;

	if (!tester)
	{
		i = -1;
		while (g->map->e[++i])
			if (g->map->e[i]->x == g->p_pos[0]
				&& g->map->e[i]->y == g->p_pos[1])
				return (1);
	}
	else if (tester)
	{
		if (!BONUS_MODE || !g->map->e)
			return (0);
		i = -1;
		while (g->map->e[++i])
			if (g->map->e[i]->player_rep)
				return (1);
	}
	return (0);
}

int	should_player_die(t_game *g, int *ini_p, int *new_p)
{
	int	pos_p[2];
	int	pos_e[2];
	int	ini_e[2];
	int	i;

	if (!g->map->e)
		return (0);
	pos_p[0] = new_p[0];
	pos_p[1] = new_p[1];
	i = -1;
	while (g->map->e[++i])
	{
		pos_e[0] = g->map->e[i]->x;
		pos_e[1] = g->map->e[i]->y;
		if (pos_p[0] == pos_e[0] && pos_p[1] == pos_e[1])
			return (1);
		ini_e[0] = g->map->e[i]->ini[0];
		ini_e[1] = g->map->e[i]->ini[1];
		if (pos_p[0] == ini_e[0] && pos_p[1] == ini_e[1])
			if (pos_e[0] == ini_p[0] && pos_e[1] == ini_p[1])
				return (1);
	}
	return (0);
}

void	alias_image(t_game *g, t_sprite t, int *p)
{
	int	ts;

	ts = TILE_SIZE;
	mlx_put_image_to_window(g->mlx, g->win, t.ptr, p[1] * ts, p[0] * ts);
}

void	init_screen(t_game *g, int win)
{
	t_sprite	t;
	t_sprite	t2;
	int			ts;
	int			p[2];
	int			size_mode;

	g->is_on_alt = 1;
	ts = TILE_SIZE;
	size_mode = !(g->map->width < 760 || g->map->height < 253);
	t = g->tex[TEX_TILE_LOSE + win];
	if (win)
		t2 = g->tex[TEX_WIN_SMALL + size_mode * 2];
	else
		t2 = g->tex[TEX_LOSE_SMALL + size_mode * 2];
	p[0] = -1;
	while (++p[0] * ts < g->map->height)
	{
		p[1] = -1;
		while (++p[1] * ts < g->map->width)
			alias_image(g, t, p);
	}
	p[1] = g->map->width / 2 - (228 + 532 * size_mode) / 2;
	p[0] = g->map->height / 2 - (76 + 177 * size_mode) / 2;
	mlx_put_image_to_window(g->mlx, g->win, t2.ptr, p[1], p[0]);
	display_count_win(g, win, size_mode);
}
