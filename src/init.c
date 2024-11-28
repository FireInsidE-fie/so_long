/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:34:31 by estettle          #+#    #+#             */
/*   Updated: 2024/11/28 16:52:46 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_core	init_mlx(int argc, char **argv)
{
	t_core	core;

	core.mlx_ptr = mlx_init();
	if (core.mlx_ptr == NULL || argc != 2)
		return (core);
	ft_printf("%s\n", argv[1]);
	core.win_ptr = mlx_new_window(core.mlx_ptr, 1920, 1080, "Hewwo world!");
	if (core.win_ptr == NULL)
		ft_kill(&core, -1);
	return (core);
}
