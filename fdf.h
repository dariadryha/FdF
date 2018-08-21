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

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win;
	t_cord		**cord;
	int			color;
}				t_data;

#endif
