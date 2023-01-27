/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:30 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/26 20:14:28 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	zeroing_variables(t_vars *game)
{
	game->nb_exit = 0;
	game->nb_player = 0;
	game->nb_coins = 0;
	game->exit_verif = 0;
	game->pos_p_x2 = 0;
	game->pos_p_y2 = 0;
	game->pos_p_x = 0;
	game->pos_p_y = 0;
}

int	main(int argc, char **argv)
{
	t_vars	game;

	if (argc == 2)
	{
		zeroing_variables(&game);
		if (parsing(&game, argv[1]) == -1)
			exit(-1);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.x * 64, game.y * 64,
				"so_long");
		get_img(&game);
		put_img_in_win(&game);
		mlx_key_hook(game.win, key_binds, &game);
		mlx_hook(game.win, 17, 0, exit_win, &game);
		mlx_loop(game.mlx);
	}
	else
		printf("Error\nNeed 2nd argument\n");
	return (0);
}
