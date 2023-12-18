/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:42:09 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/18 16:28:59 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	return (0);
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_ESCAPE)
		close_game(game);
	if (keycode == KEY_W || keycode == KEY_A)
		player_move(game, keycode);
	if (keycode == KEY_S || keycode == KEY_D)
		player_move(game, keycode);
	return (0);
}

t_sprite	create_sprite(void *mlx_ptr, char *path, int width, int height)
{
	t_sprite	s;

	s.path = path;
	s.width = width;
	s.height = height;
	s.ptr = mlx_xpm_file_to_image(mlx_ptr, path, &s.width, &s.height);
	/*if (!s.ptr)
		printf("Fail: \"%s\"!\n", s.path);
	else
		printf("Loaded: \"%s\" (%p)\n", s.path, s.ptr);*/
	return (s);
}

int	main(int ac, char **av)
{
	t_game		g;

	if (ac != 2)
		return(write(2, "Error\n", 6), 1);
	g.map = malloc(sizeof(t_map));
	if (!load_map(&g, av[1]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.map->width, g.map->height, GAME_TITLE);
	g.textures = malloc(TEXTURE_AMT * sizeof(t_sprite));
	g.textures[TEX_GROUND] = create_sprite(g.mlx, "assets/ground.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_WALL] = create_sprite(g.mlx, "assets/wall.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_COLLECT] = create_sprite(g.mlx, "assets/collectible.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_EXIT] = create_sprite(g.mlx, "assets/exit.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_PLAYER] = create_sprite(g.mlx, "assets/player.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_BOUND_0] = create_sprite(g.mlx, "assets/bound_0.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_BOUND_1] = create_sprite(g.mlx, "assets/bound_1.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_BOUND_2] = create_sprite(g.mlx, "assets/bound_2.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_BOUND_3] = create_sprite(g.mlx, "assets/bound_3.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_BOUND_4] = create_sprite(g.mlx, "assets/bound_4.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_BOUND_5] = create_sprite(g.mlx, "assets/bound_5.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_BOUND_6] = create_sprite(g.mlx, "assets/bound_6.xpm", TILE_SIZE, TILE_SIZE);
	g.textures[TEX_BOUND_7] = create_sprite(g.mlx, "assets/bound_7.xpm", TILE_SIZE, TILE_SIZE);
	generate_map(&g);
	init_move(&g);
	mlx_hook(g.win, 2, 1L << 0, key_pressed, &g);
	mlx_hook(g.win, 17, 0L, close_game, &g);
	mlx_loop(g.mlx);
	return (0);
}
