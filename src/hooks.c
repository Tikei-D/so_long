/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:13 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/22 21:31:01 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_win(t_vars *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	key_binds(int keycode, t_vars *game)
{
	if (keycode == 53)
		exit_win(game);
	if (keycode == 13 || keycode == 126)
		move_direction(keycode, game);
	if (keycode == 1 || keycode == 125)
		move_direction(keycode, game);
	if (keycode == 0 || keycode == 123)
		move_direction(keycode, game);
	if (keycode == 2 || keycode == 124)
		move_direction(keycode, game);
	return (0);
}
