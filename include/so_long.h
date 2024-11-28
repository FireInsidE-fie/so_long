/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:19:22 by estettle          #+#    #+#             */
/*   Updated: 2024/11/28 16:53:23 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Macros
# define TEXTURES_FOLDER "./assets/textures/"
# define WALL_PATH TEXTURES_FOLDER "wall.xpm"

// Libft
# include "../libftprintf/ft_printf.h"

// MinilibX
# include "../mlx_linux/mlx.h"

// Stdlib
# include <stdlib.h>
# include <inttypes.h>

// X11
#include <X11/X.h>
#include <X11/keysym.h>

// Structs
typedef struct s_core		// For core MLX and so_long functionalities
{
	void	*mlx_ptr;		// MLX pointer
	void	*win_ptr;		// MLX main window pointer
	void	*textures[10];	// MLX image pointers
	char	**map;			// So_long map pointer
}	t_core;

typedef struct s_img		// For an image and its associated data
{
	void	*img;			// The image pointer itself
	char	*addr;			// The address of the image
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

// General functions
int	ft_kill(t_core *core, int err_code);

// Init functions
t_core	init_mlx(int argc, char **argv);

// Window utils functions
void	put_pixel(t_img *img_data, int x, int y, uint32_t color);

// Input functions
int	key_pressed(int key, t_core core);

#endif //SO_LONG_H
