/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:25:14 by estettle          #+#    #+#             */
/*   Updated: 2024/11/29 17:40:49 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/*
int		check_map(t_core *core, char *path)
{

}
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
}

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
