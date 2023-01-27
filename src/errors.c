/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:53:07 by tel-dana          #+#    #+#             */
/*   Updated: 2023/01/23 13:10:48 by tel-dana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	errors_message(char *str)
{
	write(2, "Error\n", 7);
	printf("%s\n", str);
	return (-1);
}
