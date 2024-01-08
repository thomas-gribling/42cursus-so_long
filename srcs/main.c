/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:42:09 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/08 09:12:24 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

int	close_game(t_game *game)
{
	int	i;

	//mlx_clear_window(game->mlx, game->win); // useless?
	free_tab(game->map->content);
	free(game->map);
	i = -1;
	while (++i < TEXTURE_AMT)
		mlx_destroy_image(game->mlx, game->textures[i].ptr);
	free(game->textures);
	mlx_destroy_window(game->mlx, game->win);
	//mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	//free(game->mlx); // removes leak but make errors
	exit(0);
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

int	check_map_format(char *s)
{
	int	l;

	l = ft_strlen(s);
	if (l < 4)
		return (0);
	if (s[l - 1] != 'r' || s[l - 2] != 'e' || s[l - 3] != 'b'
		|| s[l - 4] != '.')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game		g;

	if (ac < 2)
		ft_puterror("Not enough parameters\n");
	if (ac > 2)
		ft_puterror("Too much parameters\n");
	if (ac != 2)
		return (ft_puterror("Expecting: ./so_long <map>\n"), 1);
	g.map = malloc(sizeof(t_map));
	g.map->debug_count = 0;
	if (!check_map_format(av[1]))
		return (free(g.map), ft_puterror("Expecting a \".ber\" file\n"), 1);
	if (!load_map(&g, av[1]))
		return (ft_puterror("Error\n"), 1);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.map->width, g.map->height, GAME_TITLE);
	load_assets(&g);
	generate_map(&g);
	g.moves = 0;
	init_move(&g, 0, 0);
	mlx_hook(g.win, 2, 1L << 0, key_pressed, &g);
	mlx_hook(g.win, 17, 0L, close_game, &g);
	mlx_loop(g.mlx);
	return (0);
}
