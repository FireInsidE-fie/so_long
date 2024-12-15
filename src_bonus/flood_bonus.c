/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:04:30 by estettle          #+#    #+#             */
/*   Updated: 2024/12/15 16:59:06 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

/**
 * @brief This function is a flood fill that will walk through a map from a
 * given starting position, and set two specific values : exit_found and
 * collectibles when finding 'E' and 'C' characters respectively.
 *
 * @param map A copy of the current map to flood check through.
 * @param x The starting x position.
 * @param y The starting y position.
 * @param sum A pointer to an int that will be incremented by 1 each time a key
 * or an exit is found. The goal is for this int to be set to the target number
 * of keys + 1 (the exit) for a map to be valid.
 */
static void	flood_check(char **map, int x, int y, int *sum)
{
	if (map[y][x] == 'E')
		(*sum)++;
	else if (map[y][x] == 'C')
		(*sum)++;
	else if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	flood_check(map, x - 1, y, sum);
	flood_check(map, x, y - 1, sum);
	flood_check(map, x + 1, y, sum);
	flood_check(map, x, y + 1, sum);
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
	int		x;
	int		y;
	int		sum;
	char	**map_copy;

	y = -1;
	while (++y < core->map.height)
	{
		x = -1;
		while (++x < core->map.width)
			if (core->map.map[y][x] == 'P')
				break ;
		if (core->map.map[y][x] == 'P')
			break ;
	}
	sum = 0;
	map_copy = copy_map(core);
	if (map_copy)
		flood_check(map_copy, x, y, &sum);
	destroy_map(&map_copy);
	if (sum != core->map.collectibles + 1
		&& ft_perror("Error\n[!] - Map does not contain a valid path!\n"))
		return (-1);
	return (0);
}
