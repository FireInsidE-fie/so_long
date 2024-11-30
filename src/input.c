/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:16:14 by estettle          #+#    #+#             */
/*   Updated: 2024/11/30 15:21:37 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_pressed(int key, t_core *core)
{
	if (key == 'w' && core->map.map[core->player.y - 1][core->player.x] != '1')
		put_img_to_index(core, MADDIE1, core->player.x, core->player.y - 1); // Move up
	else if (key == 'a' && core->map.map[core->player.y][core->player.x - 1] != '1')
		put_img_to_index(core, MADDIE1, core->player.x - 1, core->player.y); // Move left
	else if (key == 's' && core->map.map[core->player.y + 1][core->player.x] != '1')
		put_img_to_index(core, MADDIE1, core->player.x, core->player.y + 1); // Move down
	else if (key == 'd'	&& core->map.map[core->player.y][core->player.x + 1] != '1')
		put_img_to_index(core, MADDIE1, core->player.x + 1, core->player.y); // Move right
	return (0);
}
