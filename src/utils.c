/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:27:17 by estettle          #+#    #+#             */
/*   Updated: 2025/01/31 14:46:05 by estettle         ###   ########.fr       */
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

/**
 * @brief Frees a map that is MAX_TILES high.
 *
 * @param map A pointer to the first pointer of a map.
 */
void	destroy_map(char ***map)
{
	int	i;

	i = 0;
	while (i < MAX_TILES)
		free((*map)[i++]);
	free(*map);
}

/**
 * @brief Takes the core struct and allocates a copy of the map contained
 * within.
 *
 * @param core The core struct of the program.
 * @return The copied map.
 */
char	**copy_map(t_core *core)
{
	char	**copy;
	int		i;
	int		j;

	copy = ft_calloc(MAX_TILES, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < core->map.height)
	{
		copy[i] = ft_calloc(core->map.width, sizeof(char));
		if (!copy[i])
			return (NULL);
		j = 0;
		while (j < core->map.width)
		{
			copy[i][j] = core->map.map[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}

void	check_path(t_core *core, char *path)
{
	int		i;
	char	**splits;

	i = 0;
	splits = ft_split(path, '.');
	if (!splits && ft_perror("Error\n[!] - Malloc failure (ft_split)\n"))
		ft_kill(core, 3);
	while (splits[i])
	{
		if (ft_strncmp(splits[i], "ber", 3) == 0 && !splits[i + 1])
		{
			while (splits[i])
				free(splits[i++]);
			free(splits[i]);
			free(splits);
			return ;
		}
		free(splits[i++]);
	}
	free(splits[i]);
	free(splits);
	ft_printf("Error\n[!] - The specified file is not a .ber file!\n");
	ft_kill(core, 3);
}
