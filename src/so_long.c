/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:09:05 by estettle          #+#    #+#             */
/*   Updated: 2025/01/30 00:05:12 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief This functions writes the given string to stderr.
 * returns it.
 *
 * @param str The string to output to stderr.
 * @return The string pointer that was given as argument.
 */
char	*ft_perror(char *str)
{
	write(2, str, ft_strlen(str));
	return (str);
}

/**
 * @brief Kills the program after having freed mlx related variables.
 *
 * @param core The core struct containing mlx and other things to be freed.
 */
int	ft_kill(t_core *core, int err_code)
{
	int	i;

	i = 0;
	while (i < TEXTURE_COUNT)
		mlx_destroy_image(core->mlx_ptr, core->textures[i++].img);
	if (err_code != 3)
		destroy_map(&(core->map.map));
	if (err_code != 3 && err_code != 4)
		mlx_destroy_window(core->mlx_ptr, core->win_ptr);
	mlx_destroy_display(core->mlx_ptr);
	free(core->mlx_ptr);
	exit(err_code);
}

int	main(int argc, char **argv)
{
	t_core	core;

	core = init_mlx();
	if (argc != 2 || core.mlx_ptr == NULL)
		return (ft_perror("error\n[!] - failed to initialize mlx!\n"), -1); // CHANGE THIS PLEASE
	init_textures(&core);
	parse_map(&core, argv[1]);
	init_player(&core);
	init_window(&core);
	render_map(&core);
	mlx_hook(core.win_ptr, DestroyNotify, StructureNotifyMask, &ft_kill, &core);
	mlx_hook(core.win_ptr, KeyPress, KeyPressMask, &key_pressed, &core);
	mlx_loop(core.mlx_ptr);
	return (0);
}
