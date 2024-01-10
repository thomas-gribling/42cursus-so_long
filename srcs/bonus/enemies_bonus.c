/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:16:24 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/10 10:54:33 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../include/gnl.h"
#include "../../mlx/mlx.h"

static void	copy_enemies(t_enemy **old, t_enemy **new)
{
	int	i;

	i = -1;
	while (old[++i])
	{
		new[i] = malloc(sizeof(t_enemy));
		new[i]->id = old[i]->id;
		new[i]->x = old[i]->x;
		new[i]->y = old[i]->y;
		new[i]->moves = ft_strdup(old[i]->moves);
	}
}

static t_enemy	**add_enemy(t_enemy **old, char *line)
{
	t_enemy	**new;
	char	**parse;
	int		i;
	
	parse = ft_split(line, ',');
	i = 0;
	if (old[0])
		while (old[i])
			i++;
	new = malloc((i + 3) * sizeof(t_enemy*));
	if (old[0])
		copy_enemies(old, new);
	new[i] = malloc(sizeof(t_enemy));
	new[i]->id = ft_atoi(parse[0]);
	new[i]->x = ft_atoi(parse[1]);
	new[i]->y = ft_atoi(parse[2]);
	new[i]->moves = ft_strdup(parse[3]);
	new[i + 1] = NULL;
	free_tab(parse);
	free_enemies(old);
	return (new);
}

t_enemy	**get_enemies(char *map)
{
	t_enemy	**enemies;
	char	*path;
	char	*line;
	int		f;
	
	path = ft_strdup(map);
	path = ft_strjoin(path, ".e");
	f = open(path, O_RDONLY);
	free(path);
	if (f < 0)
		return (NULL);
	enemies = malloc(sizeof(t_enemy*));
	enemies[0] = NULL;
	line = get_next_line(f);
	while (line)
	{
		enemies = add_enemy(enemies, line);
		free(line);
		line = get_next_line(f);
	}
	return (enemies);
}

void	generate_enemies(t_game *g)
{
	t_sprite	t;
	int			i;
	int			x;
	int			y;
	
	if (!g->map->e)
		return ;
	i = -1;
	while (g->map->e[++i])
	{
		x = g->map->e[i]->x * TILE_SIZE;
		y = g->map->e[i]->y * TILE_SIZE;
		t = g->textures[TEX_ENEMY_0 + g->map->e[i]->id];
		if (g->map->content[y / TILE_SIZE][x / TILE_SIZE] == '0')
			mlx_put_image_to_window(g->mlx, g->win, t.ptr, x, y);
	}
}
