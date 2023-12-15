/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:42:09 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/15 11:43:54 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

void	exit_program(void)
{
	exit(1);
}

void	close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit_program();
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_ESCAPE)
		close(game);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, GAME_TITLE);
	mlx_hook(game.win, 2, 1L<<0, key_pressed, &game);
	mlx_loop(game.mlx);
}
