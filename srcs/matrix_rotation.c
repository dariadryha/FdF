#include "../fdf.h"

static	t_matrix	matrix_rotation_x(t_matrix *matrix, int	value)
{
	matrix->values[1][1] = cos(RAD(value));
	matrix->values[1][2] = sin(RAD(value));
	matrix->values[2][1] = -sin(RAD(value));
	matrix->values[2][2] = cos(RAD(value));
	return (*matrix);
}

static	t_matrix	matrix_rotation_y(t_matrix *matrix, int	value)
{
	matrix->values[0][0] = cos(RAD(value));
	matrix->values[0][2] = -sin(RAD(value));
	matrix->values[2][0] = sin(RAD(value));
	matrix->values[2][2] = cos(RAD(value));
	return (*matrix);
}

static	t_matrix	matrix_rotation_z(t_matrix *matrix, int	value)
{
	matrix->values[0][0] = cos(RAD(value));
	matrix->values[0][1] = sin(RAD(value));
	matrix->values[1][0] = -sin(RAD(value));
	matrix->values[1][1] = cos(RAD(value));
	return (*matrix);
}

static	void	init_matrix_rotation(t_data *data, int key)
{
	t_matrix mod;
	t_matrix temp;

	if (key == W)
		mod = matrix_rotation_x(&data->rotation_x, ANGLE);
	if (key == S)
		mod = matrix_rotation_x(&data->rotation_x, -ANGLE);
	if (key == D)
		mod = matrix_rotation_y(&data->rotation_y, -ANGLE);
	if (key == A)
		mod = matrix_rotation_y(&data->rotation_y, ANGLE);
	if (key == Q)
		mod = matrix_rotation_z(&data->rotation_z, ANGLE);
	if (key == E)
		mod = matrix_rotation_z(&data->rotation_z, -ANGLE);
	temp.values = matrix_multiplication(data->matrix_rotation, mod);
	free_matrix(data->matrix_rotation);
	data->matrix_rotation.values = temp.values;
}

void			rotate(t_data *data, int key)
{
	init_matrix_rotation(data, key);
	to_world(data);
}
