/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:09:05 by estettle          #+#    #+#             */
/*   Updated: 2024/11/28 21:35:31 by estettle         ###   ########.fr       */
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

	core = init_mlx(argv[1]);
	if (argc != 2 || core.mlx_ptr == NULL)
		return (free(core.mlx_ptr), -1);

	init_textures(&core);

	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, core.textures[WALL].img, 0, 0);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, core.textures[MADDIE1].img, 80, 0);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, core.textures[MADDIE2].img, 160, 0);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, core.textures[MADDIE3].img, 240, 0);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, core.textures[KEY1].img, 320, 0);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, core.textures[KEY2].img, 400, 0);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, core.textures[KEY3].img, 480, 0);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, core.textures[ENEMY].img, 560, 0);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, core.textures[STRAWBERRY].img, 640, 0);
	mlx_put_image_to_window(core.mlx_ptr, core.win_ptr, core.textures[CHEST].img, 720, 0);

	mlx_hook(core.win_ptr, DestroyNotify, StructureNotifyMask, &ft_kill, &core);
	mlx_hook(core.win_ptr, KeyPress, KeyPressMask, &key_pressed, &core);

	mlx_loop(core.mlx_ptr);

	return (0);
}
