/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:35:01 by estettle          #+#    #+#             */
/*   Updated: 2025/02/03 13:49:37 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_enemies(t_core *core)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y < core->map.height)
	{
		x = 0;
		while (x < core->map.width)
		{
			if (core->map.map[y][x] == 'S')
			{
				core->enemies[i].x = x;
				core->enemies[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
	core->enemies[i].x = 0;
	core->enemies[i].y = 0;
}

/**
 * @brief Moves a single enemy in the direction provided, updating it on the
 * screen.
 *
 * @param core The core struct of the program.
 * @param enemy A pointer to the enemy element to update.
 * @param direction The direction the enemy will try to take :
 * 0 1 2 3 are up, left, down, right respectively.
 */
void	move_enemy(t_core *core, t_enemy *enemy, int direction)
{
	if (direction == 0 && core->map.map[enemy->y - 1][enemy->x] == '0')
		enemy->y--;
	else if (direction == 1 && core->map.map[enemy->y][enemy->x - 1] == '0')
		enemy->x--;
	else if (direction == 2 && core->map.map[enemy->y + 1][enemy->x] == '0')
		enemy->y++;
	else if (direction == 3 && core->map.map[enemy->y][enemy->x + 1] == '0')
		enemy->x++;
}

void	update_enemies(t_core *core)
{
	int	i;

	i = 0;
	while (core->enemies[i].x != 0)
	{
		core->map.map[core->enemies[i].y][core->enemies[i].x] = '0';
		put_img_to_index(core, EMPTY, core->enemies[i].x, core->enemies[i].y);
		if (rand() % 2 == 0)
			move_enemy(core, &(core->enemies[i]), rand() % 4);
		put_img_to_index(core, ENEMY, core->enemies[i].x, core->enemies[i].y);
		core->map.map[core->enemies[i].y][core->enemies[i].x] = 'S';
		i++;
	}
}
