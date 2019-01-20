/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:30:27 by ddryha            #+#    #+#             */
/*   Updated: 2019/01/20 11:30:29 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	**matrix_multiplication(t_matrix m1, t_matrix m2)
{
	float	**result;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	result = create_matrix(m1.rows);
	while (i < m1.rows)
	{
		j = 0;
		while (j < SIZE)
		{
			k = 0;
			while (k < SIZE)
			{
				result[i][j] += m1.values[i][k] * m2.values[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

void	normilize_cord(t_matrix matrix, t_matrix temp)
{
	int i;

	i = -1;
	while (++i < matrix.rows)
	{
		matrix.values[i][0] /= matrix.values[i][3];
		matrix.values[i][1] /= matrix.values[i][3];
		matrix.values[i][2] /= matrix.values[i][3];
		matrix.values[i][3] /= matrix.values[i][3];
		temp.values[i][0] = matrix.values[i][0];
		temp.values[i][1] = matrix.values[i][1];
		temp.values[i][2] = matrix.values[i][2];
		temp.values[i][3] = matrix.values[i][3];
	}
}

void	free_matrix(t_matrix matrix)
{
	int i;

	i = -1;
	while (++i < matrix.rows)
		free(matrix.values[i]);
	free(matrix.values);
}

void	unit_matrix(t_matrix *matrix)
{
	matrix->values[0][0] = 1;
	matrix->values[1][1] = 1;
	matrix->values[2][2] = 1;
	matrix->values[3][3] = 1;
}

float	**create_matrix(int size)
{
	float	**result;
	int		i;

	result = (float **)malloc(sizeof(float *) * size);
	i = -1;
	while (++i < size)
	{
		result[i] = (float *)malloc(sizeof(float) * SIZE);
		ft_bzero(result[i], sizeof(float) * SIZE);
	}
	return (result);
}
