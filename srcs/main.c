/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:42:09 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/15 15:57:04 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"
#include <stdio.h>

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	//mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_ESCAPE)
		close_game(game);
	return (0);
}

int	button_pressed(int button, int x, int y, t_game *game)
{
	return (0);
}

t_sprite	create_sprite(void *mlx_ptr, char *path, int width, int height)
{
	t_sprite	s;

	s.path = path;
	s.width = width;
	s.height = height;
	s.ptr = mlx_xpm_file_to_image(mlx_ptr, path, &s.width, &s.height);
	if (!s.ptr)
		printf("Failed to create \"%s\"!\n", s.path);
	else
		printf("Successfully created \"%s\" at %p!\n", s.path, s.ptr);
	return (s);
}

int	main(void)
{
	t_game		game;
	t_map		map;
	int			i;

	// temporary map (will read from .ber)
	map.content = malloc(6 * sizeof(char *));
	map.content[0] = "1111111111";
	map.content[1] = "10C010C1C1";
	map.content[2] = "1010101101";
	map.content[3] = "1E100C0001";
	map.content[4] = "1111111111";
	map.content[5] = NULL;
	
	map.width = 10 * TILE_SIZE;
	map.height = 5 * TILE_SIZE;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map.width, map.height, GAME_TITLE);
	
	game.textures = malloc(4 * sizeof(t_sprite));
	game.textures[0] = create_sprite(game.mlx, "assets/ground.xpm", TILE_SIZE, TILE_SIZE);
	game.textures[1] = create_sprite(game.mlx, "assets/wall.xpm", TILE_SIZE, TILE_SIZE);
	game.textures[2] = create_sprite(game.mlx, "assets/collectible.xpm", TILE_SIZE, TILE_SIZE);
	game.textures[3] = create_sprite(game.mlx, "assets/exit.xpm", TILE_SIZE, TILE_SIZE);
	generate_map(&game, map);

	mlx_hook(game.win, 2, 1L<<0, key_pressed, &game);
	mlx_hook(game.win, 17, 0L, close_game, &game);
	mlx_loop(game.mlx);
}
