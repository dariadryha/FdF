#include "fdf.h"

int sign(int x)
{
	if (x < 0)
		return (-1);
	if (x > 0)
		return (1);
	return (0);
}

void	init_brez(t_data *data, t_cord c1, t_cord c2)
{
	int temp;

	data->brez.x = c1.x;
	data->brez.y = c1.y;
	data->brez.flg = 0;
	data->brez.dx = c2.x - data->brez.x;
	data->brez.dy = c2.y - data->brez.y;
	data->brez.s1 = sign(data->brez.dx);
	data->brez.s2 = sign(data->brez.dy);
	data->brez.dx = abs(data->brez.dx);
	data->brez.dy = abs(data->brez.dy);
	if (data->brez.dy > data->brez.dx)
	{
		temp = data->brez.dx;
		data->brez.dx = data->brez.dy;
		data->brez.dy = temp;
		data->brez.flg = 1;
	}
	data->brez.error = 2 * data->brez.dy - data->brez.dx;
}

// void put(t_data *data, int j)
// {
// 	int temp;
// 	int shift;
// 	int i;

// 	i = 0;
// 	shift = 0;
// 	while (i < 3)
// 	{
// 		temp = data->color;
// 		temp = (temp >> shift) & 0xFF;
// 		//printf("%d %x\n", i, temp);
// 		data->addr[j + i] = mlx_get_color_value(data->mlx_ptr, temp);
// 		i++;
// 		shift += 8;
// 	}
// }

void	draw_pixel(t_data data)
{
	//static int count;
	int temp;
	int shift;
	int i;
	int j;

	i = 0;
	shift = 0;
	j = data.brez.y * data.size_line;
	//ft_printf("%d\n", j);
	while (i < 3)
	{
		temp = data.color;
		temp = (temp >> shift) & 0xFF;
		//printf("%d %x\n", i, temp);
		//ft_printf("%d\n", j + data.brez.x + i);
		data.addr[j + i + data.brez.x * 4] = mlx_get_color_value(data.mlx_ptr, temp);
		i++;
		shift += 8;
	}
	//count += 4;
}

void	draw_line(t_data data, t_cord c1, t_cord c2)
{
	int i;

	i = 0;
	init_brez(&data, c1, c2);
	while (i++ < data.brez.dx)
	{
		//ft_printf("%d %d\n", data.size_line, data.y);
		draw_pixel(data);
		// mlx_pixel_put(data.mlx_ptr, data.win,
		// 	data.brez.x, data.brez.y, 0x00FFFF);
		while (data.brez.error >= 0)
		{
			if (data.brez.flg)
				data.brez.x += data.brez.s1;
			else
				data.brez.y += data.brez.s2;
			data.brez.error = data.brez.error - 2 * data.brez.dx;
		}
		if (data.brez.flg)
			data.brez.y += data.brez.s2;
		else
			data.brez.x += data.brez.s1;
		data.brez.error = data.brez.error + 2 * data.brez.dy;
	}
}

int draw_maps(t_data *data)
{
	int j;

	j = 0;
	while (j < data->y)
	{
		if (j)
		{
			data->cord[j][0].y = j * data->interval - 1;
			data->cord[j][data->x - 1].y = j * data->interval - 1;
		}
		data->cord[j][data->x - 1].x = (data->x - 1) * data->interval;
		draw_line(*data, data->cord[j][0], data->cord[j][data->x - 1]);
		j++;
	}
	j = 0;
	while (j < data->x)
	{
		if (j)
		{
			data->cord[0][j].x = j * data->interval - 1;
			data->cord[data->y - 1][j].x = j * data->interval - 1;
		}
		data->cord[data->y - 1][j].y = (data->y - 1) * data->interval;
		draw_line(*data, data->cord[0][j], data->cord[data->y - 1][j]);
		j++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win, data->img, 200, 200);
	return (1);
}
