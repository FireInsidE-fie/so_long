/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:19:22 by estettle          #+#    #+#             */
/*   Updated: 2024/11/28 19:17:59 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// XPM files paths
# define WALL_PATH  "./assets/textures/wall.xpm"
# define MADDIE1_PATH  "./assets/textures/maddie1.xpm"
# define MADDIE2_PATH  "./assets/textures/maddie2.xpm"
# define MADDIE3_PATH  "./assets/textures/maddie3.xpm"
# define KEY1_PATH  "./assets/textures/key1.xpm"
# define KEY2_PATH  "./assets/textures/key2.xpm"
# define KEY3_PATH  "./assets/textures/key3.xpm"
# define ENEMY_PATH  "./assets/textures/enemy.xpm"
# define STRAWBERRY_PATH  "./assets/textures/strawberry.xpm"
# define CHEST_PATH  "./assets/textures/chest.xpm"

// Libft
# include "../libftprintf/ft_printf.h"

// MinilibX
# include "../mlx_linux/mlx.h"

// Stdlib
# include <stdlib.h>
# include <inttypes.h>

// X11
# include <X11/X.h>
# include <X11/keysym.h>

// Enums
enum e_textures
{
	WALL,
	MADDIE1,
	MADDIE2,
	MADDIE3,
	KEY1,
	KEY2,
	KEY3,
	ENEMY,
	STRAWBERRY,
	CHEST
};

// Structs

// For an image and its associated data
typedef struct s_img
{
	void	*img;			// The image pointer itself
	char	*addr;			// The address of the image
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}	t_img;

// For core MLX and so_long functionalities
typedef struct s_core
{
	void	*mlx_ptr;		// MLX pointer
	void	*win_ptr;		// MLX main window pointer
	t_img	textures[10];	// MLX image pointers
	char	**map;			// So_long map pointer
}	t_core;

// General functions
int		ft_kill(t_core *core, int err_code);

// Init functions
t_core	init_mlx(char *path);
void	init_textures(t_core *core);
t_img	init_image(t_core *core, char *path);

// Window utils functions
void	put_pixel(t_img *img_data, int x, int y, uint32_t color);

// Input functions
int		key_pressed(int key, t_core core);

#endif //SO_LONG_H
