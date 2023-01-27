/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:33:26 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/23 12:44:41 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_vars	*game)
{
	if (game->map[game->pos_p_y - 1][game->pos_p_x] != '1')
	{	
		if (game->map[game->pos_p_y - 1][game->pos_p_x] == 'E'
				&& game->nb_coins == 0)
			win_game(game);
		if (game->map[game->pos_p_y - 1][game->pos_p_x] == 'E'
				&& game->nb_coins != 0)
			return ;
		if (game->map[game->pos_p_y - 1][game->pos_p_x] == 'C')
			game->nb_coins--;
		game->map[game->pos_p_y - 1][game->pos_p_x] = 'P';
		game->map[game->pos_p_y][game->pos_p_x] = '0';
		game->mv_count++;
	}
	printf("Nb of moves = %d\n", game->mv_count);
}

void	move_down(t_vars	*game)
{
	if (game->map[game->pos_p_y + 1][game->pos_p_x] != '1')
	{	
		if (game->map[game->pos_p_y + 1][game->pos_p_x] == 'E'
				&& game->nb_coins == 0)
			win_game(game);
		if (game->map[game->pos_p_y + 1][game->pos_p_x] == 'E'
				&& game->nb_coins != 0)
			return ;
		if (game->map[game->pos_p_y + 1][game->pos_p_x] == 'C')
			game->nb_coins--;
		game->map[game->pos_p_y + 1][game->pos_p_x] = 'P';
		game->map[game->pos_p_y][game->pos_p_x] = '0';
		game->mv_count++;
	}
	printf("Nb of moves = %d\n", game->mv_count);
}

void	move_right(t_vars	*game)
{
	if (game->map[game->pos_p_y][game->pos_p_x + 1] != '1')
	{	
		if (game->map[game->pos_p_y][game->pos_p_x + 1] == 'E'
				&& game->nb_coins == 0)
			win_game(game);
		if (game->map[game->pos_p_y][game->pos_p_x + 1] == 'E'
				&& game->nb_coins != 0)
			return ;
		if (game->map[game->pos_p_y][game->pos_p_x + 1] == 'C')
			game->nb_coins--;
		game->map[game->pos_p_y][game->pos_p_x + 1] = 'P';
		game->map[game->pos_p_y][game->pos_p_x] = '0';
		game->mv_count++;
	}
	printf("Nb of moves = %d\n", game->mv_count);
}

void	move_left(t_vars	*game)
{
	if (game->map[game->pos_p_y][game->pos_p_x - 1] != '1')
	{	
		if (game->map[game->pos_p_y][game->pos_p_x - 1] == 'E'
				&& game->nb_coins == 0)
			win_game(game);
		if (game->map[game->pos_p_y][game->pos_p_x - 1] == 'E'
				&& game->nb_coins != 0)
			return ;
		if (game->map[game->pos_p_y][game->pos_p_x - 1] == 'C')
			game->nb_coins--;
		game->map[game->pos_p_y][game->pos_p_x - 1] = 'P';
		game->map[game->pos_p_y][game->pos_p_x] = '0';
		game->mv_count++;
	}
	printf("Nb of moves = %d\n", game->mv_count);
}

void	move_direction(int keycode, t_vars *game)
{
	if (keycode == 13 || keycode == 126)
	{
		get_p_position(game);
		move_up(game);
		put_img_in_win(game);
	}
	if (keycode == 1 || keycode == 125)
	{
		get_p_position(game);
		move_down(game);
		put_img_in_win(game);
	}
	if (keycode == 0 || keycode == 123)
	{
		get_p_position(game);
		move_left(game);
		put_img_in_win(game);
	}
	if (keycode == 2 || keycode == 124)
	{
		get_p_position(game);
		move_right(game);
		put_img_in_win(game);
	}
}
