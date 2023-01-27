/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:11:30 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/24 00:07:10 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	set_map(t_vars *game, char *argv)
{
	int	fd;

	game->y = 0;
	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		return (-1);
	game->map = malloc(sizeof(char *) * 30);
	if (!game->map)
		return (-1);
	while (game->map)
	{
		game->map[game->y] = get_next_line(fd);
		if (game->map[game->y] == NULL)
			break ;
		game->y++;
	}
	close(fd);
	return (0);
}

void	get_p_position(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->pos_p_x = j;
				game->pos_p_y = i;
			}
			j++;
		}
		i++;
	}
}

void	get_p_position_map_dup(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->pos_p_x2 = j;
				game->pos_p_y2 = i;
			}
			j++;
		}
		i++;
	}
}

//general function that checks all conditions
int	parsing(t_vars	*game, char *argv)
{
	if (check_ber_file(argv) == -1)
		return (-1);
	if (set_map(game, argv) == -1)
		return (-1);
	if (game->y < 3)
		return (errors_message("Invalid Map"));
	if (is_rectangle(game) == -1 || walls_good(game) == -1
		|| elements_check(game) == -1 || only_allowed_elements(game) == -1)
		return (-1);
	get_p_position_map_dup(game);
	map_dup(game);
	return (0);
}
