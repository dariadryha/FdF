/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:29:43 by ddryha            #+#    #+#             */
/*   Updated: 2019/01/20 11:29:49 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	reset_matrix(t_matrix *matrix)
{
	int i;

	i = -1;
	while (++i < matrix->rows)
		ft_bzero(matrix->values[i], sizeof(float) * SIZE);
}

void	reset_cord(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->cord.rows)
	{
		data->cord.values[i][0] = data->default_cord.values[i][0];
		data->cord.values[i][1] = data->default_cord.values[i][1];
		data->cord.values[i][2] = data->default_cord.values[i][2];
		data->cord.values[i][3] = data->default_cord.values[i][3];
	}
	reset_matrix(&data->matrix_rotation);
	unit_matrix(&data->matrix_rotation);
	reset_matrix(&data->matrix_translation);
	unit_matrix(&data->matrix_translation);
	init_matrix_model(data);
	data->gradient = 0;
}

void	ft_error(char *str)
{
	ft_printf("%e%s\n", str);
	exit(1);
}
