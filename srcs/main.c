/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:42:09 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/18 10:10:59 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

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
		printf("Fail: \"%s\"!\n", s.path);
	else
		printf("Loaded: \"%s\" (%p)\n", s.path, s.ptr);
	return (s);
}

int	main(void)
{
	t_game		game;
	t_map		map;
	int			i;

	if (!load_map(&map, "maps/subject_2.ber"))
	{
		write(2, "Error\n", 6);
		return (1);
	}
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
	return (0);
}
