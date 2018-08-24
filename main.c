#include "fdf.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		ft_error("Usage : ./fdf <filename>");
	ft_bzero(&data, sizeof(t_data));
	if (!(data.mlx_ptr = mlx_init()))
		ft_error("Fails to set up the connection!");
	data.interval = 20;
	read_data(&data, &argv[1]);
	data.win = mlx_new_window (data.mlx_ptr, SIZE_X, SIZE_Y, "FdF by ddryha.");
	data.img = mlx_new_image(data.mlx_ptr, SIZE_X, SIZE_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line, &data.endian);
	data.color = 0x00FFFF;
	// mlx_clear_window(data.mlx_ptr, data.win);
	// //data.interval = 1;
	int i;
	int j;

	int x;
	int y;


	i = 0;
	j = 0;
	while (i < data.y)
	{
		j = 0;
		while (j < data.x)
		{
			x = data.cord[i][j].x;
			y = data.cord[i][j].y;
			printf("%d %d\n", (int)(x * cos(15) - y * sin(15)), (int)(x * sin(15) + y * cos(15)));
			data.cord[i][j].x = x * cos(15) - y * sin(15);
			data.cord[i][j].y = x * sin(15) + y * cos(15);
			//printf("%d %d %d\n", data.cord[i][j].x, data.cord[i][j].y, data.cord[i][j].z);
			j++;
		}
		i++;
	}
	mlx_loop_hook(data.mlx_ptr, draw_maps, &data);
	//draw_maps(data);
	//draw_maps(data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

        // rotated_point.x = point.x * cos(angle) - point.y * sin(angle);
        // rotated_point.y = point.x * sin(angle) + point.y * cos(angle)