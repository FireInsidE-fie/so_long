/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:09:05 by estettle          #+#    #+#             */
/*   Updated: 2024/11/28 11:00:14 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <stdio.h> // TO REMOVE

int	main(void)
{
	t_core	sl_core;
	t_img	img;
	int		x;
	int		y;

	sl_core.mlx_ptr = mlx_init();
	if (sl_core.mlx_ptr == NULL)
		return (-1);
	sl_core.win_ptr = mlx_new_window(sl_core.mlx_ptr, 1920, 1080, "Hewwo world!");
	img.img = mlx_new_image(sl_core.mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	if (!img.addr)
		return (-1);
	x = 500;
	y = 500;
	while (x < 1000)
		put_pixel(&img, x++, y, 0x00FF0000);
	while (y < 1000)
		put_pixel(&img, x, y++, 0x0000FF00);
	while (x >= 500)
		put_pixel(&img, x--, y, 0x000000FF);
	while (y >= 500)
		put_pixel(&img, x, y--, 0x00FFFFFF);
	put_pixel(&img, 750, 750, 0x66FFFF00);
	put_pixel(&img, 750, 750, 0x000000FF);
	mlx_put_image_to_window(sl_core.mlx_ptr, sl_core.win_ptr, img.img, 0, 0);

	t_img	wall;
	int	size_x, size_y;
	wall.img = mlx_xpm_file_to_image(sl_core.mlx_ptr, WALL_PATH, &size_x, &size_y);
	if (!wall.img && printf("Failed to put xpm file to image!!\n"))
		return (-1);
	mlx_put_image_to_window(sl_core.mlx_ptr, sl_core.win_ptr, wall.img, 0, 0);

	mlx_loop(sl_core.mlx_ptr);

	return (0);
}
