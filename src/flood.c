/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:04:30 by estettle          #+#    #+#             */
/*   Updated: 2024/12/05 14:22:35 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	flood_check(t_core *core, int x, int y, int exit_found, int collectibles)
{
	flood_check(core, x + 1, y, exit_found, collectibles);
	flood_check(core, x, y + 1, exit_found, collectibles);
	flood_check(core, x - 1, y, exit_found, collectibles);
	flood_check(core, x, y - 1, exit_found, collectibles);

	if (core->map.map[y][x] == 'E')
		exit_found = 1;
	else if (core->map.map[y][x] == 'C')
		collectibles++;

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

	y = 0;
	while (core->map.map[y])
	{
		x = 0;
		while (core->map.map[y][x])
		{
			if (core->map.map[y][x] == 'P')
				break ;
			x++;
		}
		if (core->map.map[y][x] == 'P')
			break ;
		y++;
	}
	// here's the plan : call a recursive function that performs the check,
	// returns a value if a path is found and another if none can be found.
	// Then we can return a value from check_paths itself depending.
	if (flood_check(core, x, y) != 2)
		return (-1);
	return (0);
}
