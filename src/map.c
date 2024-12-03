/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:25:14 by estettle          #+#    #+#             */
/*   Updated: 2024/12/03 12:56:04 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_items(t_core *core)
{
	int	x;
	int	y;
	int	exit;
	int	player;

	y = -1;
	exit = 0;
	player = 0;
	core->map.collectibles = 0;
	while (++y < core->map.height)
	{
		x = -1;
		while (++x < core->map.width)
		{
			if (core->map.map[y][x] == 'C')
				core->map.collectibles++;
			else if (core->map.map[y][x] == 'P')
				player++;
			else if (core->map.map[y][x] == 'E')
				exit++;
		}
	}
	if (exit != 1 || player != 1)
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
	/* First check for walls all around the map
	 * then if there's only one player, one exit, and at least a collectible
	 * oh and no other characters too
	*/
	x = 0;
	while (x < core->map.width)
		if (core->map.map[0][x++] != '1')
			return (-1);
	y = 1;
	while (y < core->map.height - 1)
	{
		if (core->map.map[y][0] != '1'
			|| core->map.map[y][core->map.width - 1] != '1')
			return (-1);
		y++;
	}
	x = 0;
	while (x < core->map.width)
		if (core->map.map[y][x++] != '1')
			return (-1);
	if (check_items(core) == -1)
		return (-1);
	// Add flood fill path checking somewhere in there
	return (0);
}

/**
 * @brief Prints the current map to the standard output.
 *
 * @param core The core struct of the program.
 */
void	write_map(t_core *core)
{
	int	i;
	int	j;

	i = 0;
	while (core->map.map[i])
	{
		j = 0;
		while (core->map.map[i][j])
			write(1, core->map.map[i] + j++, 1);
		i++;
	}
	write(1, "\n", 1);
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
		ft_kill(core, -3);
	i = 0;
	core->map.map = ft_calloc(50, sizeof(char *));
	core->map.map[i] = get_next_line(fd);
	while (core->map.map[i++])
		core->map.map[i] = get_next_line(fd);
	core->map.height = i - 1;
	core->map.width = (int)ft_strlen(core->map.map[i - 2]);
	if (check_map(core) == -1)
		ft_kill(core, -4);
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
				put_img_to_index(core, CHEST, x, y);
			else if (core->map.map[y][x] == 'C')
				put_img_to_index(core, KEY1, x, y);
			x++;
		}
		y++;
	}
}
