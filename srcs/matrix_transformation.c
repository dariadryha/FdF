/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:30:44 by ddryha            #+#    #+#             */
/*   Updated: 2019/01/20 11:30:45 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static	void	change_z(t_data *data, int value)
{
	int i;

	i = -1;
	while (++i < data->cord.rows)
	{
		if (data->default_cord.values[i][2])
			data->cord.values[i][2] += value;
	}
}

void			scale(t_data *data, int key)
{
	if (key == O)
		change_z(data, STEP);
	if (key == L)
		change_z(data, -STEP);
}

static	void	init_matrix_translation(t_data *data, int key)
{
	if (key == RIGHT)
		data->matrix_translation.values[3][0] += STEP;
	if (key == LEFT)
		data->matrix_translation.values[3][0] += -STEP;
	if (key == DOWN)
		data->matrix_translation.values[3][1] += -STEP;
	if (key == UP)
		data->matrix_translation.values[3][1] += STEP;
	if (key == PLUS)
		data->matrix_translation.values[3][2] += -STEP;
	if (key == MINUS)
		data->matrix_translation.values[3][2] += STEP;
}

void			to_world(t_data *data)
{
	t_matrix temp;

	init_matrix_model(data);
	temp.values = matrix_multiplication(data->matrix_model,
		data->matrix_rotation);
	free_matrix(data->matrix_model);
	data->matrix_model.values = temp.values;
	data->matrix_model.values[3][0] += data->matrix_translation.values[3][0];
	data->matrix_model.values[3][1] += data->matrix_translation.values[3][1];
	data->matrix_model.values[3][2] += data->matrix_translation.values[3][2];
}

void			move(t_data *data, int key)
{
	init_matrix_translation(data, key);
	to_world(data);
}
