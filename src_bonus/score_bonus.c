/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:43:48 by estettle          #+#    #+#             */
/*   Updated: 2025/01/22 10:24:39 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	display_background(t_core *core, int x, int y, int digits)
{
	int	background_x;
	int	background_y;

	background_y = y - 4;
	while (background_y < y + 40)
	{
		background_x = x - 4;
		while (background_x < x + 40 * digits)
			mlx_pixel_put(core->mlx_ptr, core->win_ptr,
				background_x++, background_y, 0);
		background_y++;
	}
}

void	display_number(t_core *core, int x, int y, int number)
{
	int	digits[10];
	int	i;

	i = 9;
	while (i >= 0)
	{
		digits[i--] = number % 10;
		number = number / 10;
	}
	i = 0;
	while (digits[i] == 0)
		i++;
	display_background(core, x, y, 10 - i);
	while (i < 10)
	{
		mlx_put_image_to_window(core->mlx_ptr, core->win_ptr,
			core->font[digits[i]].img, x, y);
		x += 40;
		i++;
	}
}
