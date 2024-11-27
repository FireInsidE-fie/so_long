/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:09:05 by estettle          #+#    #+#             */
/*   Updated: 2024/11/27 11:58:52 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <stdio.h> // TO REMOVE

int	main(void)
{
	void	*mlx;
	t_data	img;
	t_data	celst;
	void	*mlx_win;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hewwo world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
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
	put_pixel(&img, 750, 750, 0xFFFFFFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	int celst_x, celst_y;
	celst_x = 106;
	celst_y = 187;
	celst.img = mlx_xpm_file_to_image(mlx, "../assets/textures/celeste_sprites.xpm", &celst_x, &celst_y);
	if (!celst.img && printf("Failed to put xpm file to image!!\n"))
		return (-1);
	mlx_put_image_to_window(mlx, mlx_win, celst.img, 0, 0);
	mlx_loop(mlx);
}
