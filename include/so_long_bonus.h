/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:19:22 by estettle          #+#    #+#             */
/*   Updated: 2025/02/03 13:57:45 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// General macros
# define TILE_SIZE 80
# define MAX_TILES 100
# define TEXTURE_COUNT 11
# define MAX_ENEMIES 50
# define FONT_LENGTH 10

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

// Pixel font images
# define ZERO_PATH			"./assets/font_bonus/0.xpm"
# define ONE_PATH			"./assets/font_bonus/1.xpm"
# define TWO_PATH			"./assets/font_bonus/2.xpm"
# define THREE_PATH			"./assets/font_bonus/3.xpm"
# define FOUR_PATH			"./assets/font_bonus/4.xpm"
# define FIVE_PATH			"./assets/font_bonus/5.xpm"
# define SIX_PATH			"./assets/font_bonus/6.xpm"
# define SEVEN_PATH			"./assets/font_bonus/7.xpm"
# define EIGHT_PATH			"./assets/font_bonus/8.xpm"
# define NINE_PATH			"./assets/font_bonus/9.xpm"

// Libft
# include "../libftprintf/ft_printf.h"
# include "../libftprintf/get_next_line.h"

// MinilibX
# include "mlx.h"

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
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}	t_img;

// For holding the current map and its size
typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		collectibles_count;
	int		exit_count;
	int		player_count;
	int		exit_x;
	int		exit_y;
}	t_map;

// For holding player information
typedef struct s_you
{
	int	x;
	int	y;
	int	keys;
	int	moves;
}	t_you;

// For holding an enemy's info
typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

// For core MLX and so_long functionalities, contains more or less everything
typedef struct s_core
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	textures[TEXTURE_COUNT];
	t_img	font[FONT_LENGTH];
	int		animation;
	t_map	map;
	t_you	player;
	t_enemy	enemies[MAX_ENEMIES];
}	t_core;

// General functions
int		ft_kill(t_core *core, int err_code);
char	*ft_perror(char *str);

// Init functions
t_core	init_mlx(void);
void	init_window(t_core *core);
void	init_textures(t_core *core);
t_img	init_image(t_core *core, char *path);

// Window utils functions
void	put_pixel(t_img *img_data, int x, int y, uint32_t color);
void	put_img_to_index(t_core *core, int texture, int x, int y);
void	clear_index(t_core *core, int x, int y);

// Map functions
void	parse_map(t_core *core, char *path);
void	render_map(t_core *core);
int		check_paths(t_core *core);
char	**copy_map(t_core *core);
void	destroy_map(char ***map);
void	check_path(t_core *core, char *path);

// Input functions
int		key_pressed(int key, t_core *core);
void	init_player(t_core *core);
void	put_score(t_core *core);

// Enemies functions
void	init_enemies(t_core *core);
void	update_enemies(t_core *core);

// Score functions
void	display_number(t_core *core, int x, int y, int number);

#endif //SO_LONG_BONUS_H
