/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:42:09 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/21 09:47:28 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

int	close_game(t_game *game)
{
	int	i;
	
	mlx_clear_window(game->mlx, game->win);
	i = -1;
	while (++i < TEXTURE_AMT)
		mlx_destroy_image(game->mlx, game->textures[i].ptr);
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
	load_assets(&g);
	g.win = mlx_new_window(g.mlx, g.map->width, g.map->height, GAME_TITLE);
	generate_map(&g);
	init_move(&g, 0, 0);
	g.moves = 0;
	mlx_hook(g.win, 2, 1L << 0, key_pressed, &g);
	mlx_hook(g.win, 17, 0L, close_game, &g);
	mlx_loop(g.mlx);
	return (0);
}
