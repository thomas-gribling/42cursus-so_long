/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:13:20 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/12 15:13:58 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	increment_pos(t_game *g, int i, char c)
{
	if (c == 'R')
		g->map->e[i]->x++;
	if (c == 'D')
		g->map->e[i]->y++;
	if (c == 'L')
		g->map->e[i]->x--;
	if (c == 'U')
		g->map->e[i]->y--;
}

// prevent moving if wall/exit/collect
void	move_enemies(t_game *g)
{
	int			i;
	char		c;

	i = -1;
	while (g->map->e[++i])
	{
		g->map->e[i]->ini[0] = g->map->e[i]->x;
		g->map->e[i]->ini[1] = g->map->e[i]->y;
		c = g->map->e[i]->moves[g->map->e[i]->curr_move];
		if (c == '\n' || !c)
		{
			g->map->e[i]->curr_move = 0;
			c = g->map->e[i]->moves[g->map->e[i]->curr_move];
		}
		increment_pos(g, i, c);
		g->map->e[i]->curr_move++;
		if (is_player_replacing(g, 0))
			g->map->e[i]->player_rep = 1;
	}
	generate_enemies(g);
}
