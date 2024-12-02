/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:16:14 by estettle          #+#    #+#             */
/*   Updated: 2024/12/02 17:17:05 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_player(int key, t_core *core)
{
	if (core->map.map[core->player.y][core->player.x] != 'E')
		put_img_to_index(core, EMPTY, core->player.x, core->player.y);
	else
		put_img_to_index(core, CHEST, core->player.x, core->player.y);
	if (key == 'w' || key == 'a' || key == 's' || key == 'd')
	{
		if (key == 'w' && core->map.map[core->player.y - 1][core->player.x] != '1')
			core->player.y--;
		else if (key == 'a' && core->map.map[core->player.y][core->player.x - 1] != '1')
			core->player.x--;
		else if (key == 's' && core->map.map[core->player.y + 1][core->player.x] != '1')
			core->player.y++;
		else if (key == 'd' && core->map.map[core->player.y][core->player.x + 1] != '1')
			core->player.x++;
	}
	put_img_to_index(core, MADDIE1, core->player.x, core->player.y);
}

int	key_pressed(int key, t_core *core)
{
	// Leaving a comment here for future me : why not get rid of the t_map struct?
	// The only use for the width and height values would be when checking the map and
	// initializing right?
	move_player(key, core);
	if (key == 65307) // ESC
		ft_kill(core, 0);
	if (core->map.map[core->player.y][core->player.x] == 'C')
	{
		ft_printf("Picked up a key!\n");
		core->player.keys++;
		core->map.map[core->player.y][core->player.x] = '0';
		if (core->player.keys == core->map.collectibles)
			put_img_to_index(core, STRAWBERRY,
				core->map.exit_x, core->map.exit_y);
	}
	if (core->map.map[core->player.y][core->player.x] == 'E' &&
		core->player.keys >= core->map.collectibles)
	{
		ft_printf("You got the strawberry!\n");
		ft_kill(core, 0);
	}
	// ft_printf("Pressed key %d\n", key); // debug
	return (0);
}
