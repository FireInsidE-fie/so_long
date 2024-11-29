/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:09:05 by estettle          #+#    #+#             */
/*   Updated: 2024/11/29 23:24:16 by estettle         ###   ########.fr       */
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
	// Possibly free all textures I guess?
	exit(err_code);
}

int	main(int argc, char **argv)
{
	t_core	core;

	core = init_mlx(argv[1]);
	if (argc != 2 || core.mlx_ptr == NULL)
		return (free(core.mlx_ptr), -1);

	parse_map(&core, argv[1]);
	write_map(&core);

	init_textures(&core);
	init_player(&core);
	if (core.player.x == -1)
		ft_kill(&core, -4);

	render_map(&core);

	mlx_hook(core.win_ptr, DestroyNotify, StructureNotifyMask, &ft_kill, &core);
	mlx_hook(core.win_ptr, KeyPress, KeyPressMask, &key_pressed, &core);

	mlx_loop(core.mlx_ptr);

	return (0);
}
