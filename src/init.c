/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:34:31 by estettle          #+#    #+#             */
/*   Updated: 2025/01/24 11:29:28 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Initializes the MLX as well as a new window
 *
 * @return The core struct containing the mlx pointer
 */
t_core	init_mlx(void)
{
	t_core	core;

	core.mlx_ptr = mlx_init();
	if (core.mlx_ptr == NULL)
		ft_perror("Error\n[!] - Failed to initialize MLX!\n");
	return (core);
}

/**
 * @brief Initializes the window that will be used throughout the program.
 *
 * Shoutout to Lucy for the banger name change!
 * @param core The core struct of the program.
 */
void	init_window(t_core *core)
{
	core->win_ptr = mlx_new_window(core->mlx_ptr, core->map.width * TILE_SIZE,
			core->map.height * TILE_SIZE, "c-leste");
	if (core->win_ptr == NULL
		&& ft_perror("Error\n[!] - Failed to create window!\n"))
		ft_kill(core, 1);
}

/**
 * @brief Initializes a xpm image to the mlx, contained in a t_img struct.
 *
 * @param core The core struct of the program.
 * @param path The relative path of the image to initialize.
 * @return The newly initialized t_img struct.
 */
t_img	init_image(t_core *core, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(core->mlx_ptr, path, &img.width,
			&img.height);
	if (!img.img
		&& ft_perror("Error\n[!] - Failed to init an image !\n"))
		ft_kill(core, 2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if (!img.addr
		&& ft_perror("Error\n[!] - Failed to get an image's address!\n"))
		ft_kill(core, 2);
	return (img);
}

/**
 * @brief Initializes all textures in the core struct for the game.
 *
 * @param core The core struct of the program.
 */
void	init_textures(t_core *core)
{
	core->textures[EMPTY] = init_image(core, EMPTY_PATH);
	core->textures[WALL] = init_image(core, WALL_PATH);
	core->textures[MADDIE1] = init_image(core, MADDIE1_PATH);
	core->textures[MADDIE2] = init_image(core, MADDIE2_PATH);
	core->textures[MADDIE3] = init_image(core, MADDIE3_PATH);
	core->textures[KEY1] = init_image(core, KEY1_PATH);
	core->textures[KEY2] = init_image(core, KEY2_PATH);
	core->textures[KEY3] = init_image(core, KEY3_PATH);
	core->textures[ENEMY] = init_image(core, ENEMY_PATH);
	core->textures[STRAWBERRY] = init_image(core, STRAWBERRY_PATH);
	core->textures[CHEST] = init_image(core, CHEST_PATH);
}

/**
 * @brief Goes through the current map and sets the player's coordinates to the
 * first 'P' character found.
 *
 * @param core The core struct of the program.
 */
void	init_player(t_core *core)
{
	core->player.keys = 0;
	core->player.moves = 0;
	core->player.y = 0;
	while (core->map.map[core->player.y])
	{
		core->player.x = 0;
		while (core->map.map[core->player.y][core->player.x])
		{
			if (core->map.map[core->player.y][core->player.x] == 'P')
				return ;
			core->player.x++;
		}
		core->player.y++;
	}
}
