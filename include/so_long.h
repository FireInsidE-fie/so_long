/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:19:22 by estettle          #+#    #+#             */
/*   Updated: 2024/11/28 10:42:51 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Macros
# define TEXTURES_FOLDER "./assets/textures/"
# define WALL_PATH TEXTURES_FOLDER "wall.xpm"

// Libft
# include "../libft/libft.h"

// MinilibX
# include "../mlx_linux/mlx.h"

// Stdlib
# include <inttypes.h>

// Structs
typedef struct s_core
{
	void	*mlx_ptr;		// MLX pointer
	void	*win_ptr;		// MLX window pointer
	void	*textures[10];	// MLX image pointers
	char	**map;			// Map pointer
}	t_core;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// Window utils functions
void	put_pixel(t_data *data, int x, int y, uint32_t color);

#endif //SO_LONG_H
