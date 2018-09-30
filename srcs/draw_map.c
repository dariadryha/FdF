#include "../fdf.h"

int		check_cords(t_matrix matrix, int index)
{
	if (matrix.values[index][0] > 1 || matrix.values[index][0] < -1)
		return (0);
	if (matrix.values[index][1] > 1 || matrix.values[index][1] < -1)
		return (0);
	if (matrix.values[index][2] > 1 || matrix.values[index][2] < -1)
		return (0);
	return (1);
}

static	void	print_usage(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win, PAD_L, 10, 0xFFFFFF, "Change color: 1 - 5");
	mlx_string_put(data->mlx_ptr, data->win, PAD_L, 50, 0xFFFFFF, "Rotation about X: W, S");
	mlx_string_put(data->mlx_ptr, data->win, PAD_L, 70, 0xFFFFFF, "Rotation about Y: A, D");
	mlx_string_put(data->mlx_ptr, data->win, PAD_L, 90, 0xFFFFFF, "Rotation about Z: Q, E");
	mlx_string_put(data->mlx_ptr, data->win, PAD_L, 130, 0xFFFFFF, "Scaling Z: O, L");
	mlx_string_put(data->mlx_ptr, data->win, PAD_L, 170, 0xFFFFFF, "Move: arrows");
	mlx_string_put(data->mlx_ptr, data->win, PAD_L, 210, 0xFFFFFF, "Zoom: +, -");
	mlx_string_put(data->mlx_ptr, data->win, PAD_L, 250, 0xFFFFFF, "Reset changes: space");
}

void			draw_map(t_data *data)
{
	print_usage(data);
	draw_vertical(data);
	draw_horizontal(data);
}
