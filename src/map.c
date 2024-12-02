/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:25:14 by estettle          #+#    #+#             */
/*   Updated: 2024/12/02 14:08:55 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/*
int		check_map(t_core *core, char *path)
{

}
*/

/**
 * @brief Prints the current map to the standard output.
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
}

void	render_map(t_core *core)
{
	int	x;
	int	y;

	y = 0;
	core->map.collectibles = 0;
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
				put_img_to_index(core, CHEST, x, y);
				core->map.exit_y = y;
				core->map.exit_x = x;
			}
			else if (core->map.map[y][x] == 'C' && ++core->map.collectibles)
				put_img_to_index(core, KEY1, x, y);
			x++;
		}
		y++;
	}
}
