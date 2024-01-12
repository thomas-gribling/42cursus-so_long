/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:18 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/12 14:58:18 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../mlx/mlx.h"

void	display_count(t_game *g)
{
	int			x;
	int			y;
	int			i;
	char		*moves;
	t_sprite	t;

	i = -1;
	x = 8;
	y = 8;
	moves = ft_itoa(g->moves);
	while (++i < (int)ft_strlen(moves))
	{
		t = g->tex[TEX_ZERO + (moves[i] - 48)];
		mlx_put_image_to_window(g->mlx, g->win, t.ptr, x, y);
		x += 34;
	}
	free(moves);
}

void	free_enemies(t_enemy **enemies)
{
	int	i;

	i = -1;
	if (!enemies)
		return ;
	while (enemies[++i])
	{
		free(enemies[i]->moves);
		free(enemies[i]);
	}
	free(enemies);
}

void	init_bonus(t_game *g)
{
	display_count(g);
	g->map->e = get_enemies(g->map->path);
	generate_enemies(g);
}

void	change_exit(t_game *g)
{
	t_sprite	t;

	if (g->items)
		return ;
	t = g->tex[TEX_EXIT_OPEN];
	mlx_put_image_to_window(g->mlx, g->win, t.ptr, g->e_pos[0], g->e_pos[1]);
}
