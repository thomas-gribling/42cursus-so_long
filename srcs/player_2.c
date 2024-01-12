/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:05:43 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/12 15:07:36 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	can_move(t_game *game, int x, int y)
{
	char	c;

	c = game->map->content[y][x];
	if (c == '1')
		return (0);
	if (c == 'E' && game->items > 0)
		return (0);
	return (1);
}

static void	fill_tab(int *tab, int a, int b)
{
	tab[0] = a;
	tab[1] = b;
}

void	player_move(t_game *game, int keycode)
{
	int	ini_p[2];
	int	new_p[2];

	fill_tab(ini_p, game->p_pos[0], game->p_pos[1]);
	fill_tab(new_p, ini_p[0], ini_p[1]);
	if (keycode == KEY_W)
		if (can_move(game, ini_p[0], ini_p[1] - 1))
			fill_tab(new_p, ini_p[0], ini_p[1] - 1);
	if (keycode == KEY_D)
		if (can_move(game, ini_p[0] + 1, ini_p[1]))
			fill_tab(new_p, ini_p[0] + 1, ini_p[1]);
	if (keycode == KEY_S)
		if (can_move(game, ini_p[0], ini_p[1] + 1))
			fill_tab(new_p, ini_p[0], ini_p[1] + 1);
	if (keycode == KEY_A)
		if (can_move(game, ini_p[0] - 1, ini_p[1]))
			fill_tab(new_p, ini_p[0] - 1, ini_p[1]);
	if (BONUS_MODE && !game->is_on_alt)
		update_enemies(game, ini_p, new_p);
	if (new_p[0] != ini_p[0] || new_p[1] != ini_p[1])
		init_move(game, new_p[0] - ini_p[0], new_p[1] - ini_p[1]);
	if (BONUS_MODE && !game->is_on_alt)
		display_count(game);
}
