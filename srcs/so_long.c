/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:42:09 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/09 14:58:32 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

int	close_game(t_game *game)
{
	int	i;
	int	limit;

	free_tab(game->map->content);
	free(game->map);
	i = -1;
	limit = TEX_AMT;
	if (BONUS_MODE)
		limit += BONUS_TEX_AMT;
	while (++i < limit)
		mlx_destroy_image(game->mlx, game->textures[i].ptr);
	free(game->textures);
	mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->mlx);
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
