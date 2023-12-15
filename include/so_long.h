/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:10:09 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/15 11:51:33 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# define GAME_TITLE "so_long"

# define KEY_ESCAPE 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_game
{
	void		*mlx;
	void		*win;
}				t_game;

#endif