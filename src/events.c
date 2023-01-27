/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:44:09 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/23 12:20:17 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	win_game(t_vars *game)
{
	printf("CONGRATS YOU HAVE A BABY\n");
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}
