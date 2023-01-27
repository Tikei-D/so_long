/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:06:46 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/23 22:05:23 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_dup(t_vars *game)
{
	int	i;

	i = 0;
	game->map_dup = malloc(sizeof(char *) * game->y + 1);
	while (i < game->y)
	{
		game->map_dup[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->map_dup[i] = NULL;
	flood_fill(game, game->pos_p_y2, game->pos_p_x2);
	flood_checks(game);
	free(game->map_dup);
}

void	flood_fill(t_vars *game, int y, int x)
{
	game->map_dup[y][x] = 'A';
	exit_check(game, y, x);
	if (game->map_dup[y][x + 1] == '0' || game->map_dup[y][x + 1] == 'C')
	{
		game->map_dup[y][x + 1] = 'A';
		flood_fill(game, y, x + 1);
	}
	if (game->map_dup[y][x - 1] == '0' || game->map_dup[y][x - 1] == 'C')
	{
		game->map_dup[y][x - 1] = 'A';
		flood_fill(game, y, x - 1);
	}
	if (game->map_dup[y + 1][x] == '0' || game->map_dup[y + 1][x] == 'C')
	{
		game->map_dup[y + 1][x] = 'A';
		flood_fill(game, y + 1, x);
	}
	if (game->map_dup[y - 1][x] == '0' || game->map_dup[y - 1][x] == 'C')
	{
		game->map_dup[y - 1][x] = 'A';
		flood_fill(game, y - 1, x);
	}
}

void	exit_check(t_vars *game, int y, int x)
{
	if (game->map_dup[y][x + 1] == 'E')
		game->exit_verif++;
	if (game->map_dup[y][x - 1] == 'E')
		game->exit_verif++;
	if (game->map_dup[y + 1][x] == 'E')
		game->exit_verif++;
	if (game->map_dup[y - 1][x] == 'E')
		game->exit_verif++;
}

int	flood_checks(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_dup[i])
	{
		j = 0;
		while (game->map_dup[i][j])
		{
			if (game->map_dup[i][j] == 'C')
			{
				errors_message("Path is not valid");
				exit(0);
			}
			j++;
		}
		i++;
	}
	if (game->exit_verif == 0)
	{
		errors_message("Path is not valid");
		exit(0);
	}
	return (0);
}
