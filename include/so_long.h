/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:10:09 by tgriblin          #+#    #+#             */
/*   Updated: 2024/01/11 19:09:12 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define GAME_TITLE "so_long - \"Link's Holidays\""
# define TILE_SIZE 76

# define KEY_ESCAPE 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define TEX_AMT 11
# define TEX_GROUND 0
# define TEX_WALL 1
# define TEX_BOUND 2
# define TEX_COLLECT_0 3
# define TEX_COLLECT_1 4
# define TEX_COLLECT_2 5
# define TEX_COLLECT_3 6
# define TEX_COLLECT_4 7
# define TEX_COLLECT_5 8
# define TEX_EXIT 9
# define TEX_PLAYER 10

# define BONUS_TEX_AMT 35
# define TEX_PLAYER_L 11
# define TEX_PLAYER_U 12
# define TEX_PLAYER_R 13
# define TEX_ZERO 14
# define TEX_ONE 15
# define TEX_TWO 16
# define TEX_THREE 17
# define TEX_FOUR 18
# define TEX_FIVE 19
# define TEX_SIX 20
# define TEX_SEVEN 21
# define TEX_EIGHT 22
# define TEX_NINE 23
# define TEX_ENEMY_0_D 24
# define TEX_ENEMY_0_L 25
# define TEX_ENEMY_0_R 26
# define TEX_ENEMY_0_U 27
# define TEX_ENEMY_1_D 28
# define TEX_ENEMY_1_L 29
# define TEX_ENEMY_1_R 30
# define TEX_ENEMY_1_U 31
# define TEX_ENEMY_2_D 32
# define TEX_ENEMY_2_L 33
# define TEX_ENEMY_2_R 34
# define TEX_ENEMY_2_U 35
# define TEX_ENEMY_3_D 36
# define TEX_ENEMY_3_L 37
# define TEX_ENEMY_3_R 38
# define TEX_ENEMY_3_U 39
# define TEX_TILE_LOSE 40
# define TEX_TILE_WIN 41
# define TEX_LOSE_SMALL 42
# define TEX_WIN_SMALL 43
# define TEX_LOSE_MEDIUM 44
# define TEX_WIN_MEDIUM 45

# ifndef BONUS_MODE
#  define BONUS_MODE 0
# endif

typedef struct s_enemy
{
	int			id;
	int			x;
	int			y;
	char		*moves;
	int			curr_move;
	int			player_rep;
	int			ini[2];
}				t_enemy;

typedef struct s_map
{
	char		*path;
	char		**content;
	int			width;
	int			height;
	int			debug_count;
	t_enemy		**e;
}				t_map;

typedef struct s_sprite
{
	void		*ptr;
	int			width;
	int			height;
}				t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			p_pos[2];
	int			items;
	int			moves;
	t_map		*map;
	t_sprite	*tex;
	int			is_on_alt;
}				t_game;

int		close_game(t_game *game);
int		key_pressed(int keycode, t_game *game);

int		load_assets(t_game *g);

int		check_map_format(char *s);
int		read_map(t_map *map, char *path);
int		check_bounds(t_map *map);
int		load_map(t_game *game, char *path);
void	generate_map(t_game *game);

void	player_move(t_game *game, int dir);
void	init_move(t_game *game, int x_c, int y_c);
void	put_msg(int n, int end);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
void	free_tab(char **tab);
char	**tab_dup(char **tab, int start);
void	ft_puterror(char *str);

// BONUS
void	init_bonus(t_game *g);
void	display_count(t_game *g);
t_enemy	**get_enemies(char *map);
void	generate_enemies(t_game *g);
void	move_enemies(t_game *g);
void	update_enemies(t_game *g, int part, int *ini_p);
void	free_enemies(t_enemy **enemies);

int		is_player_replacing(t_game *g, int tester);
int		should_player_die(t_game *g, int *ini_p);
void	init_screen(t_game *g, int win);

char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);

#endif