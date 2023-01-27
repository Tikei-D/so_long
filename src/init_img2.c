/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:29:54 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/26 20:14:56 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Puts the selected file on the window.
void	img_select(t_vars	*game, char c)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_p,
			game->index_x * 64, game->index_y * 64);
	}
	else if (c == 'E')
	{
		if (game->nb_coins == 0)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit2,
				game->index_x * 64, game->index_y * 64);
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit1,
				game->index_x * 64, game->index_y * 64);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_coins,
			game->index_x * 64, game->index_y * 64);
	}
}

void	img_select2(t_vars	*game, char c)
{
	img_select(game, c);
	if (c == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_walls,
			game->index_x * 64, game->index_y * 64);
	}
	else if (c == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_bg,
			game->index_x * 64, game->index_y * 64);
	}
}

void	put_img_in_win(t_vars *game)
{
	game->index_y = 0;
	while (game->index_y < game->y)
	{
		game->index_x = 0;
		while (game->map[game->index_y][game->index_x] != '\n')
		{
			if (game->map[game->index_y][game->index_x] == 'C')
				img_select2(game, 'C');
			else if (game->map[game->index_y][game->index_x] == 'P')
				img_select2(game, 'P');
			else if (game->map[game->index_y][game->index_x] == '0')
				img_select2(game, '0');
			else if (game->map[game->index_y][game->index_x] == '1')
				img_select2(game, '1');
			else if (game->map[game->index_y][game->index_x] == 'E')
				img_select2(game, 'E');
			game->index_x++;
		}
		game->index_y++;
	}
}
