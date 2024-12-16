/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:35:01 by estettle          #+#    #+#             */
/*   Updated: 2024/12/16 15:08:37 by estettle         ###   ########.fr       */
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