/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:59:30 by estettle          #+#    #+#             */
/*   Updated: 2025/01/29 11:06:36 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:25:14 by estettle          #+#    #+#             */
/*   Updated: 2024/12/16 21:45:20 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief Checks if the map's width is uniform, thus verifying it is
 * rectangular.
 *
 * @param core The core struct of the program.
 * @return 0 if the map is rectangular, 1 if not.
 */
int	check_width(t_core *core)
{
	int	i;
	int	width;

	i = 0;
	width = (int)ft_strlen(core->map.map[i]);
	while (++i < core->map.height - 1)
	{
		if ((int)ft_strlen(core->map.map[i]) != width
			&& ft_perror("Error\n[!] - Map is not rectangular!\n"))
			return (-1);
	}
	if ((int)ft_strlen(core->map.map[i]) != width - 1
		&& ft_perror("Error\n[!] - Map is not rectangular!\n"))
		return (-1);
	return (0);
}

/**
 * @brief Checks the characters of the map for 1 player, 1 exit, at least 1
 * collectible, and no other characters than those expected.
 *
 * @param core The core struct of the program.
 * @return 0 if the checks passed, -1 otherwise.
 */
int	check_items(t_core *core)
{
	int	x;
	int	y;

	y = -1;
	while (++y < core->map.height)
	{
		x = -1;
		while (++x < core->map.width - 1)
		{
			if (core->map.map[y][x] == 'C')
				core->map.collectibles_count++;
			else if (core->map.map[y][x] == 'P')
				core->map.player_count++;
			else if (core->map.map[y][x] == 'E')
				core->map.exit_count++;
			else if (core->map.map[y][x] != '1' && core->map.map[y][x] != '0'
			&& ft_perror("Error\n[!] - Map contains bad characters!\n"))
				return (-1);
		}
	}
	if ((core->map.collectibles_count < 1 || core->map.exit_count < 1
			|| core->map.player_count < 1)
		&& ft_perror("Error\n[!] - Map does not contain necessary items!\n"))
		return (-1);
	return (0);
}

/**
 * @brief Checks if the current map is valid or not.
 *
 * @param core The core struct of the program.
 * @return 0 if all is well, -1 if there's a problem with the map.
 */
int	check_map(t_core *core)
{
	int	x;
	int	y;

	x = -1;
	while (++x < core->map.width - 1)
		if ((core->map.map[0][x] != '1'
			|| core->map.map[core->map.height - 1][x] != '1')
			&& ft_perror("Error\n[!] - Map 1s not surrounded by walls!\n"))
			return (-1);
	y = 0;
	while (++y < core->map.height - 1)
	{
		if ((core->map.map[y][0] != '1'
			|| core->map.map[y][ft_strlen(core->map.map[y]) - 2] != '1')
			&& ft_perror("Error\n[!] - Map is not surrounded by wall2!\n"))
			return (-1);
	}
	if (check_width(core) == -1 || check_items(core) == -1
		|| check_paths(core) == -1)
		return (-1);
	return (0);
}

/**
 * @brief Takes a relative path and parses it into a double pointer of strings.
 *
 * @param core The core struct of the program.
 * @param path The relative path to the .ber file to parse.
 */
void	parse_map(t_core *core, char *path)
{
	int		fd;
	int		i;

	check_path(core, path);
	fd = open(path, O_RDONLY);
	if (fd < 0 && ft_printf("Error\n[!] - Failed to open the specified map!\n"
			"Is the file path correct?\n"))
		ft_kill(core, 3);
	i = 0;
	core->map.map = ft_calloc(MAX_TILES, sizeof(char *));
	core->map.map[i] = get_next_line(fd);
	while (core->map.map[i++])
		core->map.map[i] = get_next_line(fd);
	core->map.height = i - 1;
	core->map.width = (int)ft_strlen(core->map.map[i - 2]);
	close(fd);
	core->map.collectibles_count = 0;
	core->map.exit_count = 0;
	core->map.player_count = 0;
	if (check_map(core) == -1)
		ft_kill(core, 4);
}

/**
 * @brief Renders the current map's starting position, outputting the right
 * textures to the window's indexes.
 *
 * @param core The core struct of the program.
 */
void	render_map(t_core *core)
{
	int	x;
	int	y;

	y = 0;
	while (core->map.map[y])
	{
		x = 0;
		while (core->map.map[y][x])
		{
			if (core->map.map[y][x] == '1')
				put_img_to_index(core, WALL, x, y);
			else if (core->map.map[y][x] == 'P')
				put_img_to_index(core, MADDIE1, x, y);
			else if (core->map.map[y][x] == 'E')
			{
				core->map.exit_x = x;
				core->map.exit_y = y;
				put_img_to_index(core, CHEST, x, y);
			}
			else if (core->map.map[y][x] == 'C')
				put_img_to_index(core, KEY1, x, y);
			x++;
		}
		y++;
	}
}
