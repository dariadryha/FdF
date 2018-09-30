#include "../fdf.h"

static	void	init_matrix_viewport(t_data *data)
{
	data->matrix_viewport.values = create_matrix(data->matrix_viewport.rows);
	data->matrix_viewport.values[0][0] = (SIZE_X - 1) / 2;
	data->matrix_viewport.values[1][1] = -((SIZE_Y - 1) / 2);
	data->matrix_viewport.values[2][2] = 1;
	data->matrix_viewport.values[3][3] = 1;
	data->matrix_viewport.values[3][0] = (SIZE_X - 1) / 2;
	data->matrix_viewport.values[3][1] = (SIZE_Y - 1) / 2;;
}

static	void	init_matrix_projection(t_data *data)
{
	t_proj	pr;

	ft_bzero(&pr, sizeof(t_proj));
	pr.near = 1;
	pr.far = data->matrix_view.values[3][2] * 2;
	pr.hfov = RAD(90);
	pr.vfov = pr.hfov * SIZE_Y / SIZE_X;
	pr.right = tan(pr.hfov / 2);
	pr.left = -pr.right;
	pr.top = tan(pr.vfov / 2);
	pr.bottom = - pr.top;
	data->matrix_projection.values = create_matrix(data->matrix_projection.rows);
	data->matrix_projection.values[0][0] = 2 / (pr.right - pr.left);
	data->matrix_projection.values[1][1] = 2 / (pr.top - pr.bottom);
	data->matrix_projection.values[2][0] = (pr.left + pr.right) / (pr.left - pr.right);
	data->matrix_projection.values[2][1] = (pr.bottom + pr.top) / (pr.bottom - pr.top);
	data->matrix_projection.values[2][2] = (pr.far + pr.near) / (pr.far - pr.near);
	data->matrix_projection.values[2][3] = 1;
	data->matrix_projection.values[3][2] = - (2 * pr.near * pr.far) / (pr.far - pr.near);
}

static	void	init_matrix_view(t_data *data)
{
	t_camera	camera;

	ft_bzero(&camera, sizeof(t_camera));
	camera.pos.z = get_distance_z(data);
	camera.direction = matrix_subtraction(camera.pos, camera.target);
	camera.direction = normilize_vector(camera.direction);
	camera.up.y = 1;
	camera.right = cross(camera.up, camera.direction);
	camera.right = normilize_vector(camera.right);
	camera.up = cross(camera.direction, camera.right);
	data->matrix_view.values = create_matrix(data->matrix_view.rows);
	data->matrix_view.values[0][0] = camera.right.x;
	data->matrix_view.values[0][1] = camera.up.x;
	data->matrix_view.values[0][2] = camera.direction.x;
	data->matrix_view.values[1][0] = camera.right.y;
	data->matrix_view.values[1][1] = camera.up.y;
	data->matrix_view.values[1][2] = camera.direction.y;
	data->matrix_view.values[2][0] = camera.right.z;
	data->matrix_view.values[2][1] = camera.up.z;
	data->matrix_view.values[2][2] = camera.direction.z;
	data->matrix_view.values[3][0] = camera.pos.x;
	data->matrix_view.values[3][1] = camera.pos.y;
	data->matrix_view.values[3][2] = camera.pos.z;
	data->matrix_view.values[3][3] = 1;
}

void	init_matrix_model(t_data *data)
{
	t_vectr		center;
	float		**temp;

	center = get_center_of_figure(&data->cord);
	reset_matrix(&data->matrix_model);
	unit_matrix(&data->matrix_model);
	data->matrix_model.values[3][0] = -center.x;
	data->matrix_model.values[3][1] = -center.y;
	data->matrix_model.values[3][2] = -center.z;
	temp = matrix_multiplication(data->matrix_model, data->matrix_reflection);
	if (data->matrix_model.values)
		free_matrix(data->matrix_model);
	data->matrix_model.values = temp;
	data->gradient = 0;
}

void	init_matrix(t_data *data)
{
	init_matrix_model(data);
	init_matrix_view(data);
	init_matrix_projection(data);
	init_matrix_viewport(data);
}
