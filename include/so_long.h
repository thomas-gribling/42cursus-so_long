/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:10:09 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/15 16:02:18 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# define GAME_TITLE "so_long"
# define TILE_SIZE 75

# define KEY_ESCAPE 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

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
	t_sprite	*textures;
}				t_game;

typedef struct s_map
{
	char		*name;
	char		**content;
	int			width;
	int			height;
}				t_map;

void	generate_map(t_game *game, t_map map);

#endif