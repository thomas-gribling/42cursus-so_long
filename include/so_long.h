/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:10:09 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/18 16:19:02 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define GAME_TITLE "so_long"
# define TILE_SIZE 75

# define KEY_ESCAPE 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define TEXTURE_AMT 13
# define TEX_GROUND 0
# define TEX_WALL 1
# define TEX_COLLECT 2
# define TEX_EXIT 3
# define TEX_PLAYER 4
# define TEX_BOUND_0 5
# define TEX_BOUND_1 6
# define TEX_BOUND_2 7
# define TEX_BOUND_3 8
# define TEX_BOUND_4 9
# define TEX_BOUND_5 10
# define TEX_BOUND_6 11
# define TEX_BOUND_7 12

typedef struct s_map
{
	char		*name;
	char		**content;
	int			width;
	int			height;
}				t_map;

typedef struct s_sprite
{
	void		*ptr;
	char		*path;
	int			width;
	int			height;
}				t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			p_pos[2];
	t_map		*map;
	t_sprite	*textures;
}				t_game;

int		read_map(t_map *map, char *path);
int		check_bounds(t_map *map);
int		load_map(t_game *game, char *path);
void	generate_map(t_game *game);

void	player_move(t_game *game, int dir);
void	init_move(t_game *game);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif