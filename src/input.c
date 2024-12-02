/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:16:14 by estettle          #+#    #+#             */
/*   Updated: 2024/12/02 14:08:07 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_core *core)
{
	put_img_to_index(core, EMPTY, core->player.x, core->player.y);
	core->player.y--;
	put_img_to_index(core, MADDIE1, core->player.x, core->player.y);
}

void	move_left(t_core *core)
{
	put_img_to_index(core, EMPTY, core->player.x, core->player.y);
	core->player.x--;
	put_img_to_index(core, MADDIE1, core->player.x, core->player.y);
}

void	move_down(t_core *core)
{
	put_img_to_index(core, EMPTY, core->player.x, core->player.y);
	core->player.y++;
	put_img_to_index(core, MADDIE1, core->player.x, core->player.y);
}

void	move_right(t_core *core)
{
	put_img_to_index(core, EMPTY, core->player.x, core->player.y);
	core->player.x++;
	put_img_to_index(core, MADDIE1, core->player.x, core->player.y);
}

int	key_pressed(int key, t_core *core)
{
	// Leaving a comment here for future me : why not get rid of the t_map struct?
	// The only use for the width and height values would be when checking the map and
	// initializing right?
	if (key == 'w' && core->map.map[core->player.y - 1][core->player.x] != '1')
		move_up(core);
	else if (key == 'a' && core->map.map[core->player.y][core->player.x - 1] != '1')
		move_left(core);
	else if (key == 's' && core->map.map[core->player.y + 1][core->player.x] != '1')
		move_down(core);
	else if (key == 'd'	&& core->map.map[core->player.y][core->player.x + 1] != '1')
		move_right(core);
	else if (key == 65307) // ESC
		ft_kill(core, 0);
	if (core->map.map[core->player.y][core->player.x] == 'C')
	{
		ft_printf("Picked up a key!\n");
		core->player.keys++;
		core->map.map[core->player.y][core->player.x] = '0';
		if (core->player.keys >= core->map.collectibles)
			put_img_to_index(core, STRAWBERRY,
				core->map.exit_x, core->map.exit_y);
	}
	// ft_printf("Pressed key %d\n", key); // debug
	return (0);
}
