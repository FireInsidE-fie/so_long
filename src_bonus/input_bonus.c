/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:16:14 by estettle          #+#    #+#             */
/*   Updated: 2025/02/03 13:50:36 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

/**
 * @brief Updates the position of the player depending on the key that was last
 * pressed. Supports both wasd and arrow keys.
 *
 * @param key The key that was pressed.
 * @param core The core struct of the program.
 */
static void	update_position(int key, t_core *core)
{
	int			movement;

	movement = 0;
	if ((key == 'w' || key == 65362)
		&& core->map.map[core->player.y - 1][core->player.x] != '1'
		&& ++movement)
		core->player.y--;
	else if ((key == 'a' || key == 65361)
		&& core->map.map[core->player.y][core->player.x - 1] != '1'
		&& ++movement)
		core->player.x--;
	else if ((key == 's' || key == 65364)
		&& core->map.map[core->player.y + 1][core->player.x] != '1'
		&& ++movement)
		core->player.y++;
	else if ((key == 'd' || key == 65363)
		&& core->map.map[core->player.y][core->player.x + 1] != '1'
		&& ++movement)
		core->player.x++;
	if (movement)
	{
		display_number(core, 20, 20, ++core->player.moves);
		update_enemies(core);
	}
}

/**
 * @brief Checks if the desired move can be executed (is there a wall there?
 * is the exit there or a collectible?), and if yes, calls the update_position
 * function and updates images displayed on screen.
 *
 * @param key The key that was pressed.
 * @param core The core struct of the program.
 */
static void	move_player(int key, t_core *core)
{
	int	y;
	int	x;

	if (core->map.map[core->player.y][core->player.x] != 'E')
		put_img_to_index(core, EMPTY, core->player.x, core->player.y);
	else
		put_img_to_index(core, CHEST, core->player.x, core->player.y);
	if (key == 'w' || key == 'a' || key == 's' || key == 'd'
		|| key == 65361 || key == 65362 || key == 65363 || key == 65364)
		update_position(key, core);
	y = 0;
	while (y < core->map.height)
	{
		x = 0;
		while (x < core->map.width)
		{
			if (core->map.map[y][x] == 'C')
				put_img_to_index(core, KEY1 + (core->animation) % 3, x, y);
			x++;
		}
		y++;
	}
	put_img_to_index(core, MADDIE1 + (core->animation)++ % 3,
		core->player.x, core->player.y);
}

/**
 * @brief KeyPressed hook for the MLX. Moves the player and checks for
 * special elements on the current tile (collectibles or exits).
 *
 * @param key The key that was pressed.
 * @param core The core struct of the program.
 * @return
 */
int	key_pressed(int key, t_core *core)
{
	move_player(key, core);
	if (key == 65307)
		ft_kill(core, 0);
	if (core->map.map[core->player.y][core->player.x] == 'S'
		&& ft_printf("You got eaten by a slime! You lose...\n"))
		ft_kill(core, 0);
	if (core->map.map[core->player.y][core->player.x] == 'C')
	{
		core->player.keys++;
		core->map.map[core->player.y][core->player.x] = '0';
		if (core->player.keys == core->map.collectibles_count)
			put_img_to_index(core, STRAWBERRY,
				core->map.exit_x, core->map.exit_y);
	}
	if (core->map.map[core->player.y][core->player.x] == 'E' &&
		core->player.keys >= core->map.collectibles_count)
	{
		ft_printf("You got the strawberry in %d moves!\n", core->player.moves);
		ft_kill(core, 0);
	}
	return (0);
}
