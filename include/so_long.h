/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:10:09 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/18 11:26:24 by tgriblin         ###   ########.fr       */
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

# define MOVE_UP 0
# define MOVE_RIGHT 1
# define MOVE_DOWN 2
# define MOVE_LEFT 3

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
int		load_map(t_map *map, char *path);
void	generate_map(t_game *game);

void	player_move(t_game *game, int dir);
int		refresh_player(t_game *game);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif