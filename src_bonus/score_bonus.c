/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:43:48 by estettle          #+#    #+#             */
/*   Updated: 2024/12/18 12:58:08 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
	while (i < 10)
	{
		ft_printf("%d\n", digits[i]);
		mlx_put_image_to_window(core->mlx_ptr, core->win_ptr,
			core->font[digits[i]].img, x, y);
		x += 40;
		i++;
	}
}
