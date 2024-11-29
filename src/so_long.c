/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:09:05 by estettle          #+#    #+#             */
/*   Updated: 2024/11/29 17:06:55 by estettle         ###   ########.fr       */
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

	parse_map(&core, argv[1]);

	init_textures(&core);

	put_img_to_index(&core, WALL, 0, 0);
	put_img_to_index(&core, MADDIE1, 1, 0);
	put_img_to_index(&core, MADDIE2, 2, 0);
	put_img_to_index(&core, MADDIE3, 3, 0);
	put_img_to_index(&core, KEY1, 4, 0);
	put_img_to_index(&core, KEY2, 5, 0);
	put_img_to_index(&core, KEY3, 6, 0);
	put_img_to_index(&core, ENEMY, 7, 0);
	put_img_to_index(&core, STRAWBERRY, 8, 0);
	put_img_to_index(&core, CHEST, 9, 0);

	mlx_hook(core.win_ptr, DestroyNotify, StructureNotifyMask, &ft_kill, &core);
	mlx_hook(core.win_ptr, KeyPress, KeyPressMask, &key_pressed, &core);

	mlx_loop(core.mlx_ptr);

	return (0);
}
