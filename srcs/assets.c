/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:09:56 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/10 10:36:12 by tgriblin         ###   ########.fr       */
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

	sprite = create_sprite(g->mlx, path, TILE_SIZE, TILE_SIZE);
	return (sprite);
}

void	load_assets_bonus(t_game *g)
{
	g->textures[TEX_ZERO] = load_sprite(g, "assets/digits/0.xpm");
	g->textures[TEX_ONE] = load_sprite(g, "assets/digits/1.xpm");
	g->textures[TEX_TWO] = load_sprite(g, "assets/digits/2.xpm");
	g->textures[TEX_THREE] = load_sprite(g, "assets/digits/3.xpm");
	g->textures[TEX_FOUR] = load_sprite(g, "assets/digits/4.xpm");
	g->textures[TEX_FIVE] = load_sprite(g, "assets/digits/5.xpm");
	g->textures[TEX_SIX] = load_sprite(g, "assets/digits/6.xpm");
	g->textures[TEX_SEVEN] = load_sprite(g, "assets/digits/7.xpm");
	g->textures[TEX_EIGHT] = load_sprite(g, "assets/digits/8.xpm");
	g->textures[TEX_NINE] = load_sprite(g, "assets/digits/9.xpm");
	g->textures[TEX_ENEMY_0] = load_sprite(g, "assets/enemies/enemy_0.xpm");
}

int	load_assets(t_game *g)
{
	if (BONUS_MODE)
		g->textures = malloc((TEX_AMT + BONUS_TEX_AMT) * sizeof(t_sprite));
	else
		g->textures = malloc(TEX_AMT * sizeof(t_sprite));
	g->textures[TEX_GROUND] = load_sprite(g, "assets/ground.xpm");
	g->textures[TEX_WALL] = load_sprite(g, "assets/wall.xpm");
	g->textures[TEX_BOUND] = load_sprite(g, "assets/bound.xpm");
	g->textures[TEX_COLLECT_0] = load_sprite(g, "assets/collectible_0.xpm");
	g->textures[TEX_COLLECT_1] = load_sprite(g, "assets/collectible_1.xpm");
	g->textures[TEX_COLLECT_2] = load_sprite(g, "assets/collectible_2.xpm");
	g->textures[TEX_COLLECT_3] = load_sprite(g, "assets/collectible_3.xpm");
	g->textures[TEX_COLLECT_4] = load_sprite(g, "assets/collectible_4.xpm");
	g->textures[TEX_COLLECT_5] = load_sprite(g, "assets/collectible_5.xpm");
	g->textures[TEX_EXIT] = load_sprite(g, "assets/exit.xpm");
	g->textures[TEX_PLAYER] = load_sprite(g, "assets/player.xpm");
	if (BONUS_MODE)
		load_assets_bonus(g);
	return (1);
}
