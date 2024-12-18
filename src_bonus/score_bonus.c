/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:43:48 by estettle          #+#    #+#             */
/*   Updated: 2024/12/18 12:12:36 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void display_number(t_core *core, int x, int y, int number)
{
	int	digits[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		digits[i++] = number % 10;
		number = number / 10;
	}
	i = 0;
	while (digits[i])
	{
		mlx_put_image_to_window(core->mlx_ptr, core->win_ptr,
			core->font[*digits].img, x + i * 32, y);
		i++;
	}
}