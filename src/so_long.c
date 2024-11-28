/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:09:05 by estettle          #+#    #+#             */
/*   Updated: 2024/11/28 12:41:25 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <stdio.h> // TO REMOVE

int	main(int argc, char **argv)
{
	t_core	core;
	t_img	wall;
	int		size_x;
	int		size_y;

	core.mlx_ptr = mlx_init();
	if (core.mlx_ptr == NULL || argc != 2)
		return (-1);
	ft_printf("%s\n", argv[1]);
	core.win_ptr = mlx_new_window(core.mlx_ptr, 1920, 1080, "Hewwo world!");
	if (core.win_ptr == NULL)
		return (free(core.mlx_ptr), -1);

	wall.img = mlx_xpm_file_to_image(core.mlx_ptr, WALL_PATH, &size_x, &size_y);
	wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel, &wall.line_length,
		&wall.endian);
	if (!wall.img && printf("Failed to put xpm file to image!!\n"))
		return (free(core.mlx_ptr), free(core.win_ptr), -1);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, wall.img, 0, 0);

	mlx_loop(core.mlx_ptr);

	return (0);
}
