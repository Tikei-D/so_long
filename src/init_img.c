/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:47:45 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/23 13:09:40 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//opens file
int	check_img_file(char	*str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		return (0);
	close(fd);
	return (1);
}

void	check_img(void)
{
	if (check_img_file("./assets/player.xpm") == 0
		|| check_img_file("./assets/uterus.xpm") == 0
		|| check_img_file("./assets/baby.xpm") == 0
		|| check_img_file("./assets/walls.xpm") == 0
		|| check_img_file("./assets/ovule2.xpm") == 0
		|| check_img_file("./assets/uterus.xpm") == 0)
	{
		errors_message("File path is incorrect");
		exit(0);
	}
}

//assign xpm file to a path for the image.  
void	get_img(t_vars	*game)
{
	check_img();
	game->img_p = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm",
			&game->img_y, &game->img_x);
	game->img_exit1 = mlx_xpm_file_to_image(game->mlx, "./assets/uterus.xpm",
			&game->img_y, &game->img_x);
	game->img_exit2 = mlx_xpm_file_to_image(game->mlx, "./assets/baby.xpm",
			&game->img_y, &game->img_x);
	game->img_walls = mlx_xpm_file_to_image(game->mlx, "./assets/walls.xpm",
			&game->img_y, &game->img_x);
	game->img_coins = mlx_xpm_file_to_image(game->mlx, "./assets/ovule2.xpm",
			&game->img_y, &game->img_x);
	game->img_bg = mlx_xpm_file_to_image(game->mlx, "./assets/background.xpm",
			&game->img_y, &game->img_x);
}
