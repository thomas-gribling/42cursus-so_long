/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:19:09 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/08 14:30:11 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

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
