/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:19:22 by estettle          #+#    #+#             */
/*   Updated: 2024/12/02 13:28:49 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// General macros
# define TILE_SIZE 80
# define MAX_TILES 50
# define TEXTURE_COUNT 11

// XPM files paths
# define EMPTY_PATH			"./assets/textures/empty.xpm"
# define WALL_PATH			"./assets/textures/wall.xpm"
# define MADDIE1_PATH		"./assets/textures/maddie1.xpm"
# define MADDIE2_PATH		"./assets/textures/maddie2.xpm"
# define MADDIE3_PATH		"./assets/textures/maddie3.xpm"
# define KEY1_PATH			"./assets/textures/key1.xpm"
# define KEY2_PATH			"./assets/textures/key2.xpm"
# define KEY3_PATH			"./assets/textures/key3.xpm"
# define ENEMY_PATH			"./assets/textures/enemy.xpm"
# define STRAWBERRY_PATH	"./assets/textures/strawberry.xpm"
# define CHEST_PATH			"./assets/textures/chest.xpm"

// Libft
# include "../libftprintf/ft_printf.h"
# include "../libftprintf/get_next_line.h"

// MinilibX
# include "../mlx_linux/mlx.h"

// Stdlib
# include <stdlib.h>
# include <inttypes.h>
# include <fcntl.h>

// X11
# include <X11/X.h>
# include <X11/keysym.h>

// Enums
enum e_textures
{
	EMPTY,
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

// For holding the current map and its size
typedef struct s_map
{
	char	**map;			// So_long map pointer
	int		width;
	int		height;
	int		collectibles;
}	t_map;

typedef struct s_you
{
	int	x;					// Horizontal coordinates
	int	y;					// Vertical coordinates
	int	keys;				// Number of keys already collected
}	t_you;

// For core MLX and so_long functionalities
typedef struct s_core
{
	void	*mlx_ptr;		// MLX pointer
	void	*win_ptr;		// MLX main window pointer
	t_img	textures[11];	// MLX image pointers
	t_map	map;
	t_you	player;
}	t_core;

// General functions
int		ft_kill(t_core *core, int err_code);

// Init functions
t_core	init_mlx(char *path);
void	init_textures(t_core *core);
t_img	init_image(t_core *core, char *path);

// Window utils functions
void	put_pixel(t_img *img_data, int x, int y, uint32_t color);
void	put_img_to_index(t_core *core, int texture, int x, int y);
void	clear_index(t_core *core, int x, int y);

// Map functions
void	parse_map(t_core *core, char *path);
void	render_map(t_core *core);

// Input functions
int		key_pressed(int key, t_core *core);
void	write_map(t_core *core);
void	init_player(t_core *core);

#endif //SO_LONG_H
