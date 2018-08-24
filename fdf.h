#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include <math.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

# define SIZE_X 1000
# define SIZE_Y 1000

typedef	struct	s_cord
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_cord;

typedef struct	s_algo
{
	int			dx;
	int			dy;
	int			s1;
	int			s2;
	int			error;
	int			x;
	int			y;
	int			flg;
}				t_algo;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_cord		**cord;
	t_algo		brez;
	int			interval;
	int		 	x;
	int			y;
	int			color;	
}				t_data;

void	read_data(t_data *data, char **argv);
void	ft_error(char *str);
int		ft_atoi_base(char *str, int base);
int		draw_maps(t_data *data);

#endif
