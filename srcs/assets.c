/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:09:56 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/19 14:23:23 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

static t_sprite	create_sprite(void *mlx_ptr, char *path, int width, int height)
{
	t_sprite	s;

	s.path = path;
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

int	load_assets(t_game *g)
{
	g->textures = malloc(TEXTURE_AMT * sizeof(t_sprite));
	g->textures[TEX_GROUND] = load_sprite(g, "assets/ground.xpm");
	g->textures[TEX_WALL] = load_sprite(g, "assets/wall.xpm");
	g->textures[TEX_COLLECT] = load_sprite(g, "assets/collectible.xpm");
	g->textures[TEX_EXIT] = load_sprite(g, "assets/exit.xpm");
	g->textures[TEX_PLAYER] = load_sprite(g, "assets/player.xpm");
	g->textures[TEX_BOUND_0] = load_sprite(g, "assets/bound_0.xpm");
	g->textures[TEX_BOUND_1] = load_sprite(g, "assets/bound_1.xpm");
	g->textures[TEX_BOUND_2] = load_sprite(g, "assets/bound_2.xpm");
	g->textures[TEX_BOUND_3] = load_sprite(g, "assets/bound_3.xpm");
	g->textures[TEX_BOUND_4] = load_sprite(g, "assets/bound_4.xpm");
	g->textures[TEX_BOUND_5] = load_sprite(g, "assets/bound_5.xpm");
	g->textures[TEX_BOUND_6] = load_sprite(g, "assets/bound_6.xpm");
	g->textures[TEX_BOUND_7] = load_sprite(g, "assets/bound_7.xpm");
	return (1);
}
