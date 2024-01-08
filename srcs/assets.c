/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:09:56 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/08 10:53:20 by tgriblin         ###   ########.fr       */
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

int	load_assets(t_game *g)
{
	g->textures = malloc(TEXTURE_AMT * sizeof(t_sprite));
	g->textures[TEX_GROUND] = load_sprite(g, "assets/ground.xpm");
	g->textures[TEX_WALL] = load_sprite(g, "assets/wall.xpm");
	g->textures[TEX_BOUND] = load_sprite(g, "assets/wall.xpm");
	g->textures[TEX_COLLECT_0] = load_sprite(g, "assets/collectible_0.xpm");
	g->textures[TEX_COLLECT_1] = load_sprite(g, "assets/collectible_1.xpm");
	g->textures[TEX_COLLECT_2] = load_sprite(g, "assets/collectible_2.xpm");
	g->textures[TEX_COLLECT_3] = load_sprite(g, "assets/collectible_3.xpm");
	g->textures[TEX_COLLECT_4] = load_sprite(g, "assets/collectible_4.xpm");
	g->textures[TEX_COLLECT_5] = load_sprite(g, "assets/collectible_5.xpm");
	g->textures[TEX_EXIT] = load_sprite(g, "assets/exit.xpm");
	g->textures[TEX_PLAYER] = load_sprite(g, "assets/player.xpm");
	return (1);
}
