/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:20:01 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/22 21:39:02 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "error_codes.h"
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 2560  // 2400
# define HEIGHT 1440 // 1200
# define TILESIZE 64 // messes up raycaster when changed
// # define PLAYEROFFSET 5
// # define ANGLE_INCREMENT 0.0174533 // ray angle increment value
// # define RD 64              // render distance
// # define LT WIDTH / FOV     // line thickness
# define MINIMAP_SIZE 6     // 1 is whole screen
# define PLAYER_SPEED 0.1     // player speed
# define ROTATION_SPEED 0.1 // player rotation speed

# define WALL_COLOR_X 0x00FF00FF
# define WALL_COLOR_Y 0x0000FFFF
# define TEXTURE_SIZE 512
# define FOV 0.66 // field of view

//// random sht by matt

typedef enum e_dir
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}					t_dir;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_vec
{
	double			x;
	double			y;
}					t_vec;

typedef struct s_player
{
	t_vec			pos;
	t_vec			dir;
	t_vec			plane;
	int				pitch;
	double			speed;
	double			cos_rot;
	double			sin_rot;
}					t_player;

typedef struct s_ray
{
	double			cam_x;
	double			perpendicular_wall_dist;
	t_vec			dir;
	t_point			map_tile;
	t_vec			side_dist;
	t_vec			delta_dist;
	t_point			step;
	bool			hit;
	int				side;
	double			wall_hit_x;
	int				texture_x;
	int				line_height;
	int				line_start;
	int				line_end;
}					t_ray;

/*
typedef struct mlx_texture
{
	uint32_t		width;
	uint32_t		height;
	uint8_t			bytes_per_pixel;
	uint8_t*	pixels;
}					mlx_texture_t;
*/
///

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

typedef struct s_line
{
	int				x_diff;
	int				y_diff;
	int				x_step;
	int				y_step;
	int				error;
	int				error2;
	int				x;
	int				y;
	int				x_end;
	int				y_end;
}					t_line;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_parser
{
	char			*map_path_stack;
	char			**map_copy_heap;
	int				map_fd;
	int				last_type_index;
	char			*floor_color;
	char			*ceiling_color;
}					t_parser;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_map_data
{
	char			*north_texture;
	char			*east_texture;
	char			*south_texture;
	char			*west_texture;
	int				floor_color;
	int				ceiling_color;
	char			**map_coor;
	int				map_width;
	int				map_height;
	char			player_orientation;
	t_point			player_pos;
}					t_map_data;

//////////////////////////////////////////////////////////////////////////////

// typedef struct s_player
// {
// 	t_point			pos;
// 	t_point			delta;
// 	double			angle;
// }					t_player;

//////////////////////////////////////////////////////////////////////////////

/*
typedef struct s_rayy
{
	float

}
*/

// typedef struct s_ray
// {
// 	float			x;
// 	float			y;
// 	float			x_offset;
// 	float			y_offset;
// 	float			tan;
// 	double			angle;
// 	float			distance;
// 	bool			no_hit;
// 	int				dof;
// 	int				line_height;
// 	float			line_offset;
// 	float			fisheye_fix;
// }					t_ray;

//////////////////////////////////////////////////////////////////////////////

typedef struct s_main
{
	t_parser		*parser;
	t_map_data		*map_data;
	t_player		*player;
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_image_t		*background;
	mlx_image_t		*minimap;
	mlx_texture_t	*textures[5];
	double			time;
	double			tmpfps;
	double			fps;
}					t_main;

// random sht by matt			!!!! !!! !!! !!! !!!
void				init_background(t_main *main);
void				render_3d(t_main *main);
void				step_x(t_ray *ray);
void				step_y(t_ray *ray);
void				dda_algo(t_main *main, t_ray *ray);
void				create_2d_map_squared(t_main *main);
void				fps(void *param);
void				load_textures(t_main *main);

//////////////////////////////////////////////////////////////////////////////

// init.c

t_main				*init_structs(void);

//////////////////////////////////////////////////////////////////////////////

// parser.c

void				parse_arguments(int num_arg_strings, char **arg_strings,
						t_main *main);

// parse_basic.c

void				parse_num_arg_strings(int num_arg_strings, t_main *main);
void				parse_map_file_format(char *arg_map_path, t_main *main);

// parse_copy_map.c

void				parse_copy_map(t_main *main);

// parse_map.c

void				parse_map(t_main *main);

// parse_set_types.c

void				set_types(t_main *main);

// parse_get_map_coor.c

void				get_map_coor(t_main *main);

// parse_check_map_coor.c

void				check_map_coor(t_main *main);

// parse_get_missing_information.c

void				get_player_pos(t_map_data *map_data);
void				get_map_dimensions(t_map_data *map_data);

// parse_check_for_garbage.c

void				check_for_garbage(t_main *main);

// parse_convert_colors.c

void				convert_colors(t_main *main);

// parse_utils.c

char				*ft_strjoin_free(char *s1, char *s2);
char				*copy_path(char *to_copy, t_main *main);
int					skip_whitespaces(char *str, int i);
int					reverse_skip_whitespaces(char *str, int i);

//////////////////////////////////////////////////////////////////////////////

// game.c

void				init_data(t_main *main);
void				during_game(t_main *main);
void				end_game(t_main *main);

// game_key_hooks.c

void				key_hooks(void *main);

// game_wasd_keys.c

void				wasd_keys(t_main *main);

// game_arrow_keys.c

void				arrow_keys(t_main *main);

// game_loop_hooks.c

void				loop_hooks(void *param);

// game_minimap.c

void				draw_minimap(t_main *main);

// game_set_player_data.c

void				set_player_data(t_main *main);

//////////////////////////////////////////////////////////////////////////////

// ray.c

void				draw_rays(t_main *main);
float				distance(float ax, float ay, float bx, float by);

// ray_horizontal.c

t_ray				ray_horizontal(t_main *main, t_ray ray);

// ray_vertical.c

t_ray				ray_vertical(t_main *main, t_ray ray);

//////////////////////////////////////////////////////////////////////////////

// free.c

void				free_structs(t_main *main);
void				free_parser_struct(t_main *main);

// free_utils.c

void				safe_free(void *to_free);
void				free_matrix(char **to_free);

//////////////////////////////////////////////////////////////////////////////

// error.c

void				error_exit(t_main *main, int error_code);

//////////////////////////////////////////////////////////////////////////////

// draw_line.c

void				draw_line(t_point start, t_point end, t_main *main,
						int color);
void				draw_line_minimap(t_point start, t_point end, t_main *main,
						int color);

//////////////////////////////////////////////////////////////////////////////

#endif
