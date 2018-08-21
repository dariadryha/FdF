#include "fdf.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sign(int x)
{
	if (x < 0)
		return (-1);
	if (x > 0)
		return (1);
	return (0);
}

static void draw(t_data data)
{
	int x1 = -60;
	int y1 = -100;
	int x = 0;
	int y = 0;
	int dx;
	int dy;
	int s1;
	int s2;
	int flg;
	int t;
	int temp;
	int x_;
	int y_;

	dx = x - x1;
	dy = y - y1;
	s1 = sign(dx);
	s2 = sign(dy);
	dx = abs(dx);
	dy = abs(dy);
	printf("%d %d\n", dx, dy);
	if (dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		flg = 1;
	}
	else
		flg = 0;
	t = 2 * dy - dx;
	int i = 1;
	x_ = x1;
	y_ = y1;
	while (i < dx)
	{
		mlx_pixel_put(data.mlx_ptr, data.win, x_ + 200, y_ + 200, 0x00FFFF);
		while (t >= 0)
		{
			 if (flg)
			 	x_ += s1;
			 else
			 	y_ += s2;
			t = t - 2 * dx;
		}
		if (flg)
			y_ += s2;
		else
			x_ += s1;
		t = t + 2 * dy;
		i++;
	}
}

int main(void)
{
	t_data data;

	if (!(data.mlx_ptr = mlx_init()))
		printf("Fails to set up the connection!\n");
	data.win = mlx_new_window (data.mlx_ptr, 1000, 1000, "kuku");
	//mlx_pixel_put(data.mlx_ptr, data.win, 10, 10, 0x00FFFF);
	draw(data);
	mlx_loop(data.mlx_ptr);
	return (0);
}