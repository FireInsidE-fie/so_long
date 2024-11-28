/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:09:05 by estettle          #+#    #+#             */
/*   Updated: 2024/11/28 16:52:52 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Kills the program after having freed mlx related variables.
 *
 * @param core The core struct containing mlx and other things to be freed.
 */
int	ft_kill(t_core *core, int err_code)
{
	mlx_destroy_window(core->mlx_ptr, core->win_ptr);
	mlx_destroy_display(core->mlx_ptr);
	free(core->mlx_ptr);
	exit(err_code);
}

int	main(int argc, char **argv)
{
	t_core	core;
	t_img	wall;
	int		size_x;
	int		size_y;

	core = init_mlx(argc, argv);
	if (core.mlx_ptr == NULL)
		return (-1);

	wall.img = mlx_xpm_file_to_image(core.mlx_ptr, WALL_PATH, &size_x, &size_y);
	wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel, &wall.line_length,
		&wall.endian);
	if (!wall.img && ft_printf("Failed to put xpm file to image!!\n"))
		ft_kill(&core, -2);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, wall.img, 0, 0);

	mlx_hook(core.win_ptr, DestroyNotify, StructureNotifyMask, &ft_kill, &core);
	mlx_hook(core.win_ptr, KeyPress, KeyPressMask, &key_pressed, &core);

	mlx_loop(core.mlx_ptr);

	return (0);
}
