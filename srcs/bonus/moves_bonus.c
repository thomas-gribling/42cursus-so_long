/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:18 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/09 14:58:57 by tgriblin         ###   ########.fr       */
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
		t = g->textures[TEX_ZERO + (moves[i] - 48)];
		mlx_put_image_to_window(g->mlx, g->win, t.ptr, x, y);
		x += 34;
	}
	free(moves);
}
