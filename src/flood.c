/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:04:30 by estettle          #+#    #+#             */
/*   Updated: 2024/12/08 21:15:47 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_check(char **map, int x, int y, int *exit_found, int *collectibles)
{
	// Need to make a copy of the map, so I can modify it to only count collectibles once
	// As it stands the flood fill will just go on for eternity, it'll come back
	// on already explored tiles forever
	if (map[y][x] == 'E')
		*exit_found = 1;
	else if (map[y][x] == 'C')
		(*collectibles)++;
	else if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flood_check(map, x, y, exit_found, collectibles);
	flood_check(map, x, y, exit_found, collectibles);
	flood_check(map, x, y, exit_found, collectibles);
	flood_check(map, x, y , exit_found, collectibles);
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
