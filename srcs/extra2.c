/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:29:36 by ddryha            #+#    #+#             */
/*   Updated: 2019/01/20 11:29:38 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#define TRANS data->matrix_translation
#define REFL data->matrix_reflection

static	void	set_rows_of_matrix(t_data *data)
{
	data->matrix_translation.rows = SIZE;
	data->matrix_rotation.rows = SIZE;
	data->rotation_x.rows = SIZE;
	data->rotation_y.rows = SIZE;
	data->rotation_z.rows = SIZE;
	data->matrix_model.rows = SIZE;
	data->matrix_view.rows = SIZE;
	data->matrix_projection.rows = SIZE;
	data->matrix_mvp.rows = SIZE;
	data->matrix_viewport.rows = SIZE;
	data->matrix_reflection.rows = SIZE;
	data->result.rows = data->cord.rows;
	data->temp.rows = data->cord.rows;
}

void			create_transformation_matrix(t_data *data)
{
	set_rows_of_matrix(data);
	TRANS.values = create_matrix(TRANS.rows);
	data->matrix_rotation.values = create_matrix(data->matrix_rotation.rows);
	REFL.values = create_matrix(REFL.rows);
	data->matrix_model.values = create_matrix(data->matrix_model.rows);
	data->temp.values = create_matrix(data->cord.rows);
	data->rotation_x.values = create_matrix(data->rotation_x.rows);
	data->rotation_y.values = create_matrix(data->rotation_y.rows);
	data->rotation_z.values = create_matrix(data->rotation_z.rows);
	unit_matrix(&data->rotation_x);
	unit_matrix(&data->rotation_y);
	unit_matrix(&data->rotation_z);
	unit_matrix(&data->matrix_model);
	unit_matrix(&data->matrix_translation);
	unit_matrix(&data->matrix_rotation);
	unit_matrix(&data->matrix_reflection);
	data->matrix_reflection.values[1][1] = -1;
	data->matrix_reflection.values[2][2] = -1;
}

t_vectr			get_center_of_figure(t_matrix *matrix)
{
	int		i;
	t_vectr	result;

	i = -1;
	ft_bzero(&result, sizeof(t_vectr));
	while (++i < matrix->rows)
	{
		result.x += matrix->values[i][0];
		result.y += matrix->values[i][1];
		result.z += matrix->values[i][2];
	}
	result.x /= matrix->rows;
	result.y /= matrix->rows;
	result.z /= matrix->rows;
	return (result);
}

float			get_distance_z(t_data *data)
{
	float	result;

	if (data->dist.x >= data->dist.y && data->dist.x >= data->dist.z)
		result = (data->dist.x / 2) * (1 + 1 / tan(RAD(90) / 2)) + 5;
	else if (data->dist.y >= data->dist.x && data->dist.y >= data->dist.z)
		result = (data->dist.y / 2) * (1 + 1 / tan(RAD(90) / 2)) + 5;
	else
		result = data->dist.z + 10;
	return (result);
}

t_vectr			get_distance(t_data *data)
{
	t_vectr	m[2];
	int		i;

	i = -1;
	ft_bzero(&m, sizeof(t_vectr) * 2);
	while (++i < data->cord.rows)
	{
		if (m[0].x < data->cord.values[i][0])
			m[0].x = data->cord.values[i][0];
		if (m[1].x > data->cord.values[i][0])
			m[1].x = data->cord.values[i][0];
		if (m[0].y < data->cord.values[i][1])
			m[0].y = data->cord.values[i][1];
		if (m[1].y > data->cord.values[i][1])
			m[1].y = data->cord.values[i][1];
		if (m[0].z < data->cord.values[i][2])
			m[0].z = data->cord.values[i][2];
		if (m[1].z > data->cord.values[i][2])
			m[1].z = data->cord.values[i][2];
	}
	m[0].x = (m[0].x + 1) - m[1].x;
	m[0].y = (m[0].y + 1) - m[1].y;
	m[0].z -= m[1].z;
	return (m[0]);
}
