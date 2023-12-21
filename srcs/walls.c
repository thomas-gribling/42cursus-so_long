/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:24:31 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/21 10:50:03 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*get_situation(t_game *g, int x, int y)
{
	char	*out;

	out = ft_strdup("00000000");
	if (y > 0 && x > 0 && g->map->content[y - 1][x - 1] == '1')
		out[0] = '1';
	if (y > 0 && g->map->content[y - 1][x] == '1')
		out[1] = '1';
	if (y > 0 && g->map->content[y - 1][x + 1] == '1')
		out[2] = '1';
	if (x > 0 && g->map->content[y][x - 1] == '1')
		out[3] = '1';
	if (g->map->content[y][x + 1] == '1')
		out[4] = '1';
	if (x > 0 && g->map->content[y + 1][x - 1] == '1')
		out[5] = '1';
	if (g->map->content[y + 1][x] == '1')
		out[6] = '1';
	if (g->map->content[y + 1][x + 1] == '1')
		out[7] = '1';
	return (out);
}

int	get_wall(t_game *g, int x, int y)
{
	char	*s;

	s = get_situation(g, x / TILE_SIZE, y / TILE_SIZE);
	return (0);
}
