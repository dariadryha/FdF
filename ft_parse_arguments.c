#include "fdf.h"

static	int	get_length_arr(char **arr)
{
	int k;

	k = 0;
	while (arr[k])
		k++;
	return (k);
}

void	ft_parse_cord(t_data *data, int i, int j, char *str)
{
	char **arr;

	arr = ft_strsplit(str, ',');
	data->cord[i][j].y = i;
	data->cord[i][j].x = j;
	data->cord[i][j].z = ft_atoi(arr[0]);
	if (arr[1] && !(data->cord[i][j].color = ft_atoi_base(arr[1], 16)))
		data->cord[i][j].color = 0xFFFF00;
}

void	ft_parse_arguments(t_data *data, t_list *head)
{
	t_list	*temp;
	char	**arr;
	int		length[2];
	int		i;
	int 	j;

	temp = head;
	i = 0;
	ft_bzero(&length, sizeof(int) * 2);
	data->y = ft_lstlen(head);
	data->cord = (t_cord **)malloc(sizeof(t_cord *) * ft_lstlen(head));
	while (temp)
	{
		j = 0;
		arr = ft_strsplit(temp->content, ' ');
		if (!length[0])
		{
			length[0] = get_length_arr(arr);
			data->x = length[0];
		}
		length[1] = get_length_arr(arr);
		if (length[1] < length[0])
			ft_error("Found wrong line length. Exiting.");
		data->cord[i] = (t_cord *)malloc(sizeof(t_cord) * length[0]);
		while (arr[j])
		{
			ft_parse_cord(data, i, j, arr[j]);
			j++;
		}
		i++;
		temp = temp->next;
	}
}

void	read_data(t_data *data, char **argv)
{
	int		fd;
	char	*line;
	t_list	*head;

	line = NULL;
	head = NULL;
	if ((fd = open(argv[0], O_RDONLY)) == -1)
		ft_error("Can't read source file!");
	while (get_next_line(fd, &line) > 0)
	{
		if (!head)
			head = ft_lstnew(line, ft_strlen(line) + 1);
		else
			ft_lstadd_back(head, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	close(fd);
	ft_parse_arguments(data, head);
}
