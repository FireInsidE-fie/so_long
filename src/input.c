/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:16:14 by estettle          #+#    #+#             */
/*   Updated: 2024/11/30 19:57:33 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_pressed(int key, t_core *core)
{
	// Leaving a comment here for future me : why not get rid of the t_map struct?
	// The only use for the width and height values would be when checking the map and
	// initializing right?
	if (key == 'w' && core->map.map[core->player.y - 1][core->player.x] != '1')
	{
		put_img_to_index(core, EMPTY, core->player.x, core->player.y);
		core->player.y--;
		put_img_to_index(core, MADDIE1, core->player.x, core->player.y);
	}
	else if (key == 'a' && core->map.map[core->player.y][core->player.x - 1] != '1')
	{
		put_img_to_index(core, EMPTY, core->player.x, core->player.y);
		core->player.x--;
		put_img_to_index(core, MADDIE1, core->player.x, core->player.y);
	}
	else if (key == 's' && core->map.map[core->player.y + 1][core->player.x] != '1')
	{
		put_img_to_index(core, EMPTY, core->player.x, core->player.y);
		core->player.y++;
		put_img_to_index(core, MADDIE1, core->player.x, core->player.y);
	}
	else if (key == 'd'	&& core->map.map[core->player.y][core->player.x + 1] != '1')
	{
		put_img_to_index(core, EMPTY, core->player.x, core->player.y);
		core->player.x++;
		put_img_to_index(core, MADDIE1, core->player.x, core->player.y);
	}
	return (0);
}
