/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:27:17 by estettle          #+#    #+#             */
/*   Updated: 2024/11/29 22:27:49 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Puts a pixel at (aligned) coordinates in the image argument.
 *
 * @param img_data The img struct to put the pixel in.
 * @param x Horizontal coordinates in the image.
 * @param y Vertical coordinates in the image.
 * @param color Color of the pixel as a 32bit uinteger (0xTTRRGGBB)
 */
void	put_pixel(t_img *img_data, int x, int y, uint32_t color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_length + x
			*(img_data->bits_per_pixel / 8));
	*(uint32_t *)dst = color;
}

/**
 * @brief Puts a particular texture to the window, aligned as a tile in the
 * game.
 *
 * @param core The core struct of the program.
 * @param texture The texture index in the core struct (see e_textures enum).
 * @param x Horizontal tile coordinate.
 * @param y Vertical tile coordinate.
 */
void	put_img_to_index(t_core *core, int texture, int x, int y)
{
	mlx_put_image_to_window(core->mlx_ptr, core->win_ptr,
		core->textures[texture].img, x * TILE_SIZE, y * TILE_SIZE);
}
