#include "../fdf.h"

void	transform_figure(t_data *data)
{
	t_matrix temp;

	temp.values = matrix_multiplication(data->matrix_model,
		data->matrix_view);
	temp.rows = data->matrix_model.rows;
	if (data->matrix_mvp.values)
		free_matrix(data->matrix_mvp);
	data->matrix_mvp.values = matrix_multiplication(temp,
		data->matrix_projection);
	free_matrix(temp);
	if (data->result.values)
		free_matrix(data->result);
	data->result.values = matrix_multiplication(data->cord,
		data->matrix_mvp);
	normilize_cord(data->result, data->temp);
	temp.values = matrix_multiplication(data->result,
		data->matrix_viewport);
	free_matrix(data->result);
	data->result.values = temp.values;
}

int expose_hook(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win);
	transform_figure(data);
	draw_map(data);
	return (0);
}

int key_hook(int key, void *param)
{
	if (key == ESC)
		exit(1);
	if (ROTATE1(key) || ROTATE2(key))
		rotate(param, key);
	if (MOVE1(key) || MOVE2(key))
		move(param, key);
	if (key == O || key == L)
		scale(param, key);
	if (key == SPACE)
		reset_cord(param);
	if (COLOR1(key) || COLOR2(key))
		change_color(param, key);
	expose_hook(param);
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		ft_error("Usage : ./fdf <filename>");
	ft_bzero(&data, sizeof(t_data));
	read_data(&data, &argv[1]);
	if (!(data.mlx_ptr = mlx_init()))
		ft_error("Fails to set up the connection!");
	data.win = mlx_new_window (data.mlx_ptr, SIZE_X, SIZE_Y, "FdF by ddryha.");
	data.dist = get_distance(&data);
	create_transformation_matrix(&data);
	init_matrix(&data);
	transform_figure(&data);
	draw_map(&data);
	mlx_hook(data.win, 2, 5, key_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
