/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:25:14 by estettle          #+#    #+#             */
/*   Updated: 2024/12/11 19:55:48 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	int	sum;

	y = -1;
	sum = 0;
	core->map.collectibles = 0;
	while (++y < core->map.height)
	{
		x = -1;
		while (++x < core->map.width - 1)
		{
			if (core->map.map[y][x] == 'C')
				core->map.collectibles++;
			else if (core->map.map[y][x] == 'P' || core->map.map[y][x] == 'E')
				sum++;
			else if (core->map.map[y][x] != '1' && core->map.map[y][x] != '0'
			&& ft_perror("Error\n[!] - Map contains bad characters!\n"))
				return (-1);
		}
	}
	if ((sum != 2 || core->map.collectibles < 1)
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

	// Combine top and bottom wall checking like I did for left and right?
	x = 0;
	while (x < core->map.width - 1)
		if (core->map.map[0][x++] != '1'
			&& ft_perror("Error\n[!] - Map 1s not surrounded by walls!\n"))
			return (-1);
	y = 0;
	while (++y < core->map.height - 2)
		if ((core->map.map[y][0] != '1'
			|| core->map.map[y][ft_strlen(core->map.map[y]) - 2] != '1')
			&& ft_perror("Error\n[!] - Map is not surrounded by wall2!\n"))
			return (-1);
	x = 0;
	while (x < core->map.width - 1)
		if (core->map.map[y + 1][x++] != '1'
			&& ft_perror("Error\n[!] - Map is not surround3d by walls!\n"))
			return (-1);
	if (check_width(core) == -1
		|| check_items(core) == -1
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

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_kill(core, 3);
	i = 0;
	core->map.map = ft_calloc(MAX_TILES, sizeof(char *));
	core->map.map[i] = get_next_line(fd);
	while (core->map.map[i++])
		core->map.map[i] = get_next_line(fd);
	core->map.height = i - 1;
	core->map.width = (int)ft_strlen(core->map.map[i - 2]);
	if (check_map(core) == -1)
		ft_kill(core, 4);
	close(fd);
}

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
