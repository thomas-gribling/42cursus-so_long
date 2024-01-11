/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:19:09 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/11 11:03:27 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

static void	free_m(t_map *map, int b)
{
	if (b)
		free_tab(map->content);
	free(map->path);
	free(map);
}

static void	arguments_errors(int ac)
{
	if (ac < 2)
		ft_puterror("Not enough parameters\n");
	if (ac > 2)
		ft_puterror("Too much parameters\n");
}

int	main(int ac, char **av)
{
	t_game		g;

	arguments_errors(ac);
	if (ac != 2)
		return (ft_puterror("Expecting: ./so_long <map>\n"), 1);
	g.map = malloc(sizeof(t_map));
	g.map->debug_count = 0;
	g.map->path = ft_strdup(av[1]);
	g.is_on_alt = 0;
	if (!check_map_format(av[1]))
		return (free_m(g.map, 0), ft_puterror("Expecting a \".ber\"\n"), 1);
	if (!load_map(&g, av[1]))
		return (free_m(g.map, 1), ft_puterror("Error\n"), 1);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.map->width, g.map->height, GAME_TITLE);
	load_assets(&g);
	generate_map(&g);
	g.moves = 0;
	init_move(&g, 0, 0);
	if (BONUS_MODE)
		init_bonus(&g);
	mlx_hook(g.win, 2, 1L << 0, key_pressed, &g);
	mlx_hook(g.win, 17, 0L, close_game, &g);
	mlx_loop(g.mlx);
	return (0);
}
