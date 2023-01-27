/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:01:59 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/24 00:07:04 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//checks that the file is .ber
int	check_ber_file(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] != 'r')
		return (errors_message("Not .ber file"));
	if (argv[i - 2] != 'e')
		return (errors_message("Not .ber file"));
	if (argv[i -3] != 'b')
		return (errors_message("Not .ber file"));
	if (argv[i - 4] != '.')
		return (errors_message("Not .ber file"));
	return (0);
}

//checks if map is rectangular
int	is_rectangle(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[0][i] != '\n')
		i++;
	while (game->map[game->y - 1][j] != '\0')
		j++;
	if (i != j)
		return (errors_message("Not Rectangle"));
	game->x = i;
	i = 0;
	while (++i <= game->y - 2)
	{
		j = 0;
		while (game->map[i][j] != '\n')
		{
			if (j++ > game->x)
				return (errors_message("Not Rectangle"));
		}
		if (j < game->x)
			return (errors_message("Not Rectangle"));
	}
	return (0);
}

//checks that map is surrounded by '1' 
int	walls_good(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->x)
	{
		if (game->map[0][i] != '1')
			return (errors_message("Map not sealed"));
		if (game->map[game->y - 1][i] != '1')
			return (errors_message("Map not sealed"));
		i++;
	}
	i = 1;
	while (i < game->y - 1)
	{
		j = 0;
		while (j < game->x - 1)
		{
			if (game->map[i][0] != '1' || game->map[i][game->x - 1] != '1')
				return (errors_message("Map not sealed"));
			j++;
		}
		i++;
	}
	return (0);
}

//Checks if all elements are there, and if not return (-1)
int	elements_check(t_vars	*game)
{
	int	i;
	int	j;

	i = 1;
	while (i <= game->y - 2)
	{
		j = 1;
		while (j < game->x)
		{
			if (game->map[i][j] == 'P')
				game->nb_player++;
			if (game->map[i][j] == 'E')
				game->nb_exit++;
			if (game->map[i][j] == 'C')
				game->nb_coins++;
			j++;
		}
		i++;
	}
	if (game->nb_player != 1 || game->nb_exit != 1 || game->nb_coins < 1)
		return (errors_message("Some elements are missing"));
	return (0);
}

int	only_allowed_elements(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			if (game->map[i][j] == 'C')
				j++;
			else if (game->map[i][j] == '1')
				j++;
			else if (game->map[i][j] == '0')
				j++;
			else if (game->map[i][j] == 'P')
				j++;
			else if (game->map[i][j] == 'E')
				j++;
			else
				return (errors_message("Invalid element letter"));
		}
		i++;
	}
	return (0);
}
