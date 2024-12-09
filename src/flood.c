/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:04:30 by estettle          #+#    #+#             */
/*   Updated: 2024/12/09 12:50:03 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief This function is a flood fill that will walk through a map from a
 * given starting position, and set two specific values : exit_found and
 * collectibles when finding 'E' and 'C' characters respectively.
 *
 * @param map A copy of the current map to flood check through.
 * @param x The starting x position.
 * @param y The starting y position.
 * @param exit_found A pointer to an int that will be set to 1 once an exit is
 * found.
 * @param collectibles A pointer to an int that will be incremented as
 * collectibles are found.
 */
void	flood_check(char **map, int x, int y, int *exit_found, int *collectibles)
{
	if (map[y][x] == 'E' && ft_printf("Exit found!\n"))
		*exit_found = 1;
	else if (map[y][x] == 'C' && ft_printf("Key found!\n"))
		(*collectibles)++;
	else if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flood_check(map, x - 1, y, exit_found, collectibles);
	flood_check(map, x, y - 1, exit_found, collectibles);
	flood_check(map, x + 1, y, exit_found, collectibles);
	flood_check(map, x, y + 1 , exit_found, collectibles);
}

/**
 * @brief This function checks the current map for a path between the starting
 * position of the player, all collectibles and the exit.
 *
 * @param core The core struct of the program.
 * @return 0 if a path exists, -1 otherwise.
 */
int	check_paths(t_core *core)
{
	int	x;
	int	y;
	int	exit_found;
	int	collectibles;

	y = -1;
	while (++y < core->map.height)
	{
		x = -1;
		while (++x < core->map.width)
		{
			if (core->map.map[y][x] == 'P')
				break ;
		}
		if (core->map.map[y][x] == 'P')
			break ;
	}
	exit_found = 0;
	collectibles = 0;
	flood_check(copy_map(core), x, y, &exit_found, &collectibles);
	ft_printf("%d\t%d\n", exit_found, collectibles);
	if (exit_found != 1 || collectibles != core->map.collectibles)
		return (-1);
	return (0);
}
