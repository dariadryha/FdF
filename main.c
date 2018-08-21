#include "fdf.h"

void	ft_error(char *str)
{
	ft_printf("%e%s\n", str);
	exit(1);
}

void	ft_parse_color(t_data *data, char *str)
{
	char **arr;

	ft_strsplit(str, ',');
}

void	ft_parse_str(t_data *data, char *str)
{
	char **arr;
	int k;

	k = 0;
	arr = ft_strsplit(str, ' ');
	while (arr[k])
	{
		ft_parse_color(data, arr[k]);
		k++;
	}
}

void	ft_parse_arguments(t_data *data, char **argv)
{
	int fd;
	char *line;

	line = NULL;
	if ((fd = open(argv[0], O_RDONLY)) == -1)
		ft_error("Can't read source file!");
	while (get_next_line(fd, &line) > 0)
		ft_parse_str(data, line);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		ft_error("Usage : ./fdf <filename>");
	// if (!(data.mlx_ptr = mlx_init()))
	// 	ft_error("Fails to set up the connection!");
	ft_bzero(&data, sizeof(t_data));
	//ft_parse_arguments(&data, &argv[1]);
	//data.win = mlx_new_window (data.mlx_ptr, SIZE_X, SIZE_Y, "FdF by ddryha.");
	//mlx_loop(data.mlx_ptr);
	return (0);
}
