/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:13:20 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/12 15:27:23 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	check_valid(t_game *g, int i, int x_c, int y_c)
{
	int	x;
	int	y;

	x = g->map->e[i]->x + x_c;
	y = g->map->e[i]->y + y_c;
	if (g->map->content[y][x] == '0')
		return (1);
	return (0);
}

static void	increment_pos(t_game *g, int i, char c)
{
	if (c == 'R' && check_valid(g, i, 1, 0))
		g->map->e[i]->x++;
	if (c == 'D' && check_valid(g, i, 0, 1))
		g->map->e[i]->y++;
	if (c == 'L' && check_valid(g, i, -1, 0))
		g->map->e[i]->x--;
	if (c == 'U' && check_valid(g, i, 0, -1))
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
