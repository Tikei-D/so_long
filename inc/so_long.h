/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:32:25 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/23 22:14:17 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/include/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		y;
	int		x;
	int		index_x;
	int		index_y;
	
	int		nb_exit;
	int		nb_player;
	int		nb_coins;
	void	*img_p;
	void	*img_exit1;
	void	*img_exit2;
	void	*img_coins;
	void	*img_walls;
	void	*img_bg;
	
	int		img_y;
	int		img_x;

	int		mv_count;

	int		pos_p_x;
	int		pos_p_y;
	int		pos_p_x2;
	int		pos_p_y2;
	char	**map_dup;
	int		exit_verif;
}t_vars;


//errors.c
int		errors_message(char *str);

// init_img.c && init_img2.c
int		check_img_file(char	*str);
void	check_img(void);
void	get_img(t_vars	*game);
void	img_select(t_vars	*game, char c);
void	put_img_in_win(t_vars *game);
void	img_select2(t_vars	*game, char c);

// moves.c
void	move_up(t_vars	*game);
void	move_down(t_vars	*game);
void	move_right(t_vars	*game);
void	move_left(t_vars	*game);
void	move_direction(int	keycode, t_vars	*game);

// hooks.c
int		key_binds(int keycode, t_vars *game);
int		exit_win(t_vars *game);

//events
void	win_game(t_vars *game);

// so_long.c
void	zeroing_variables(t_vars *game);

//flood_fill.c
void	map_dup(t_vars *game);
void	flood_fill(t_vars *game, int y, int x);
void	exit_check(t_vars *game, int y, int x);
int		flood_checks(t_vars *game);

//parsing.c & set_map.c
int		only_allowed_elements(t_vars *game);
int		check_ber_file(char *argv);
int		set_map(t_vars *game, char *argv);
int		is_rectangle(t_vars *game);
int		walls_good(t_vars *game);
int		elements_check(t_vars *game);
void	get_p_position(t_vars *game);
void	get_p_position_map_dup(t_vars *game);
int		parsing(t_vars	*game, char *argv);

#endif 