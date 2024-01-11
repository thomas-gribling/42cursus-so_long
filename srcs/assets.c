/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:09:56 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/11 11:00:59 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

static t_sprite	create_sprite(void *mlx_ptr, char *path, int width, int height)
{
	t_sprite	s;

	s.width = width;
	s.height = height;
	s.ptr = mlx_xpm_file_to_image(mlx_ptr, path, &s.width, &s.height);
	return (s);
}

static t_sprite	load_sprite(t_game *g, char *path)
{
	t_sprite	sprite;
	int			w;
	int			h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	if (!ft_strcmp(path, "assets/screens/ls.xpm")
		|| !ft_strcmp(path, "assets/screens/ws.xpm"))
	{
		w = 228;
		h = 76;
	}
	if (!ft_strcmp(path, "assets/screens/lm.xpm")
		|| !ft_strcmp(path, "assets/screens/wm.xpm"))
	{
		w = 760;
		h = 253;
	}
	sprite = create_sprite(g->mlx, path, w, h);
	return (sprite);
}

void	load_assets_bonus(t_game *g)
{
	g->tex[TEX_ZERO] = load_sprite(g, "assets/digits/0.xpm");
	g->tex[TEX_ONE] = load_sprite(g, "assets/digits/1.xpm");
	g->tex[TEX_TWO] = load_sprite(g, "assets/digits/2.xpm");
	g->tex[TEX_THREE] = load_sprite(g, "assets/digits/3.xpm");
	g->tex[TEX_FOUR] = load_sprite(g, "assets/digits/4.xpm");
	g->tex[TEX_FIVE] = load_sprite(g, "assets/digits/5.xpm");
	g->tex[TEX_SIX] = load_sprite(g, "assets/digits/6.xpm");
	g->tex[TEX_SEVEN] = load_sprite(g, "assets/digits/7.xpm");
	g->tex[TEX_EIGHT] = load_sprite(g, "assets/digits/8.xpm");
	g->tex[TEX_NINE] = load_sprite(g, "assets/digits/9.xpm");
	g->tex[TEX_ENEMY_0] = load_sprite(g, "assets/enemies/enemy_0.xpm");
	g->tex[TEX_TILE_LOSE] = load_sprite(g, "assets/screens/bg_lose.xpm");
	g->tex[TEX_TILE_WIN] = load_sprite(g, "assets/screens/bg_win.xpm");
	g->tex[TEX_LOSE_SMALL] = load_sprite(g, "assets/screens/ls.xpm");
	g->tex[TEX_WIN_SMALL] = load_sprite(g, "assets/screens/ws.xpm");
	g->tex[TEX_LOSE_MEDIUM] = load_sprite(g, "assets/screens/lm.xpm");
	g->tex[TEX_WIN_MEDIUM] = load_sprite(g, "assets/screens/wm.xpm");
}

int	load_assets(t_game *g)
{
	if (BONUS_MODE)
		g->tex = malloc((TEX_AMT + BONUS_TEX_AMT) * sizeof(t_sprite));
	else
		g->tex = malloc(TEX_AMT * sizeof(t_sprite));
	g->tex[TEX_GROUND] = load_sprite(g, "assets/ground.xpm");
	g->tex[TEX_WALL] = load_sprite(g, "assets/wall.xpm");
	g->tex[TEX_BOUND] = load_sprite(g, "assets/bound.xpm");
	g->tex[TEX_COLLECT_0] = load_sprite(g, "assets/collectible_0.xpm");
	g->tex[TEX_COLLECT_1] = load_sprite(g, "assets/collectible_1.xpm");
	g->tex[TEX_COLLECT_2] = load_sprite(g, "assets/collectible_2.xpm");
	g->tex[TEX_COLLECT_3] = load_sprite(g, "assets/collectible_3.xpm");
	g->tex[TEX_COLLECT_4] = load_sprite(g, "assets/collectible_4.xpm");
	g->tex[TEX_COLLECT_5] = load_sprite(g, "assets/collectible_5.xpm");
	g->tex[TEX_EXIT] = load_sprite(g, "assets/exit.xpm");
	g->tex[TEX_PLAYER] = load_sprite(g, "assets/player.xpm");
	if (BONUS_MODE)
		load_assets_bonus(g);
	return (1);
}
