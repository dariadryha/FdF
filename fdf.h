/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 10:49:00 by ddryha            #+#    #+#             */
/*   Updated: 2019/01/20 10:49:06 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include <math.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <stdio.h>

# define SIZE	4
# define SIZE_X 1024
# define SIZE_Y 768
# define PI 3.14
# define RAD(x) (x * PI) / 180
# define ANGLE 10
# define STEP 2
# define PAD_L 15
# define PAD_T 10

# define ESC 53
# define O 31
# define L 37
# define SPACE 49
# define W 13
# define S 1
# define A 0
# define D 2
# define Q 12
# define E 14
# define PLUS 24
# define MINUS 27
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define FIVE 23

# define ROTATE1(x) x == W || x == S || x == A ? 1 : 0
# define ROTATE2(x) x == D || x == Q || x == E ? 1 : 0
# define MOVE1(x) x == LEFT || x == RIGHT || x == DOWN ? 1 : 0
# define MOVE2(x) x == UP || x == PLUS || x == MINUS ? 1 : 0
# define COLOR1(x) x == ONE || x == TWO || x == THREE ? 1 : 0
# define COLOR2(x) x == FOUR || x == FIVE ? 1 : 0

typedef	struct	s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef struct	s_vectr
{
	float		x;
	float		y;
	float		z;
	float		w;
	int			color;
}				t_vectr;

typedef	struct	s_matrix
{
	float		**values;
	int			rows;
}				t_matrix;

typedef	struct	s_camera
{
	t_vectr		pos;
	t_vectr		target;
	t_vectr		direction;
	t_vectr		right;
	t_vectr		up;
}				t_camera;

typedef	struct	s_proj
{
	float		near;
	float		far;
	float		hfov;
	float		vfov;
	float		right;
	float		left;
	float		top;
	float		bottom;
}				t_proj;

typedef struct	s_bres
{
	int			x;
	int			y;
	int			color;
	t_color		step;
	int			temp;
	int			dx;
	int			dy;
	int			s1;
	int			s2;
	int			flg;
	int			error;
}				t_bres;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win;
	t_matrix	matrix_translation;
	t_matrix	matrix_rotation;
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation_z;
	t_matrix	matrix_reflection;
	t_matrix	matrix_model;
	t_matrix	matrix_view;
	t_matrix	matrix_projection;
	t_matrix	matrix_mvp;
	t_matrix	matrix_viewport;
	t_matrix	cord;
	t_matrix	result;
	t_matrix	default_cord;
	t_matrix	temp;
	t_vectr		dist;
	int			gradient;
	int			**color;
	int			x;
	int			y;
}				t_data;

void			read_data(t_data *data, char **argv);
void			ft_error(char *str);
int				ft_atoi_base(char *str, int base);
void			del_content(void *content, size_t size);
void			draw_map(t_data *data);
t_vectr			matrix_subtraction(t_vectr v1, t_vectr v2);
float			**matrix_multiplication(t_matrix m1, t_matrix m2);
float			**create_matrix(int size);
t_vectr			cross(t_vectr v1, t_vectr v2);
t_vectr			normilize_vector(t_vectr v);
void			init_matrix(t_data *data);
void			normilize_cord(t_matrix matrix, t_matrix temp);
void			free_matrix(t_matrix matrix);
void			unit_matrix(t_matrix *matrix);
void			create_transformation_matrix(t_data *data);
void			init_matrix_model(t_data *data);
void			reset_matrix(t_matrix *matrix);
void			rotate(t_data *data, int key);
void			change_color(t_data *data, int key);
int				make_gradient(int color, t_color step);
t_color			get_rgb_step(int color1, int color2, int length);
void			draw_line(t_data *data, int index1, int index2);
void			move(t_data *data, int key);
void			scale(t_data *data, int key);
float			get_distance_z(t_data *data);
t_vectr			get_center_of_figure(t_matrix *matrix);
void			to_world(t_data *data);
t_vectr			get_distance(t_data *data);
void			reset_cord(t_data *data);
void			draw_vertical(t_data *data);
void			draw_horizontal(t_data *data);
int				check_cords(t_matrix matrix, int index);

#endif
