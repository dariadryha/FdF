#include "../fdf.h"

static	int		find_horizontal_index(t_data *data, int i)
{
	int j;

	j = i;
	while (j < data->cord.rows)
	{
		if (data->cord.values[i][0] != data->cord.values[j][0] &&
			data->cord.values[i][1] == data->cord.values[j][1])
			return (j);
		j++;
	}
	return (-1);
}

void			draw_horizontal(t_data *data)
{
	int i;
	int j;
	int temp[2];

	i = 0;
	ft_bzero(&temp, sizeof(int) * 2);
	while (i < data->dist.y)
	{
		j = 0;
		while (j < data->dist.x)
		{
			if ((temp[0] = find_horizontal_index(data, j + temp[1])) != -1)
			{
				if (check_cords(data->temp, j + temp[1]) &&
					check_cords(data->temp, temp[0]))
					draw_line(data, j + temp[1], temp[0]);
			}
			else
				break ;
			j++;
		}
		temp[1] += j + 1;
		i++;
	}
}

static	int		find_vertical_y(t_data *data, int i)
{
	int j;

	j = i;
	while (j < data->cord.rows)
	{
		if (data->cord.values[i][0] == data->cord.values[j][0] &&
			data->cord.values[j][1] != data->cord.values[i][1])
			return (j);
		j++;
	}
	return (-1);
}

static	int		find_vertical_x(t_data *data, int i)
{
	int j;

	j = i;
	while (j < data->cord.rows)
	{
		if (data->cord.values[j][0] > data->cord.values[i][0])
			return (j);
		j++;
	}
	return (-1);
}

void			draw_vertical(t_data *data)
{
	int i;
	int j;
	int	temp[2];

	i = -1;
	ft_bzero(&temp, sizeof(int) * 2);
	while (++i < data->dist.x)
	{
		j = -1;
		while (++j < data->dist.y)
		{
			if ((temp[1] = find_vertical_y(data, temp[0])) == -1)
				break ;
			if (data->cord.values[temp[1]][1] == data->cord.values[temp[0]][1] + 1)
			{
				if (check_cords(data->temp, temp[0]) &&
					check_cords(data->temp, temp[1]))
					draw_line(data, temp[0], temp[1]);
			}
			temp[0] = temp[1];	
		}
		temp[0] = find_vertical_x(data, i);
	}
}
