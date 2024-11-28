/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:27:17 by estettle          #+#    #+#             */
/*   Updated: 2024/11/28 21:52:46 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_pixel(t_img *img_data, int x, int y, uint32_t color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_length + x
			*(img_data->bits_per_pixel / 8));
	*(uint32_t *)dst = color;
}

void	put_img_to_index(t_core *core, int texture, int x, int y)
{
	mlx_put_image_to_window(core->mlx_ptr, core->win_ptr,
		core->textures[texture].img, x * TILE_SIZE, y * TILE_SIZE);
}
