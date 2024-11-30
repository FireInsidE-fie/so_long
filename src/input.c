/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:16:14 by estettle          #+#    #+#             */
/*   Updated: 2024/11/30 14:50:04 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_pressed(int key, t_core *core)
{
	if (key == 'w')
		put_img_to_index(core, MADDIE1, core->player.x, core->player.y - 1); // Move up
	else if (key == 'a')
		put_img_to_index(core, MADDIE1, core->player.x - 1, core->player.y); // Move up
	else if (key == 's')
		put_img_to_index(core, MADDIE1, core->player.x, core->player.y + 1); // Move up
	else if (key == 'd')
		put_img_to_index(core, MADDIE1, core->player.x + 1, core->player.y); // Move up
	return (0);
}
