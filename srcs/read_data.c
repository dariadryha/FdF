#include "../fdf.h"

static	void	parse_color(char *str, t_vectr *vec)
{
	char **arr;

	arr = ft_strsplit(str, ',');
	vec->color = arr[1] ? ft_atoi_base(arr[1], 16) : 0x2300FF;
	vec->z = ft_atoi(arr[0]);
	ft_del_mas_str(arr);
}

static	void	parse_arguments(t_data *data, t_list *head)
{
	int		i;
	t_list	*temp;

	i = -1;
	temp = head;
	data->cord.rows = ft_lstlen(head);
	data->default_cord.rows = data->cord.rows;
	data->cord.values = create_matrix(data->cord.rows);
	data->default_cord.values = create_matrix(data->cord.rows);
	data->color = (int **)malloc(sizeof(int *) * data->cord.rows);
	while (++i < data->cord.rows)
	{
		data->color[i] = (int *)malloc(sizeof(int));
		data->cord.values[i][0] = (float)((t_vectr *)(temp->content))->x;
		data->cord.values[i][1] = (float)((t_vectr *)(temp->content))->y;
		data->cord.values[i][2] = (float)((t_vectr *)(temp->content))->z;
		data->cord.values[i][3] = 1;
		data->default_cord.values[i][0] = (float)((t_vectr *)(temp->content))->x;
		data->default_cord.values[i][1] = (float)((t_vectr *)(temp->content))->y;
		data->default_cord.values[i][2] = (float)((t_vectr *)(temp->content))->z;
		data->color[i][0] = (int)((t_vectr *)(temp->content))->color;
		data->default_cord.values[i][3] = 1;
		temp = temp->next;
	}
}

static	void	parse_cord(t_vectr *vec, t_list **head, char *line)
{
	char	**arr;
	int		j;

	j = -1;
	arr = ft_strsplit(line, ' ');
	while (arr[++j])
	{
		vec->x = j;
		parse_color(arr[j], vec);
		if (!*head)
			*head = ft_lstnew(vec, sizeof(t_vectr));
		else
			ft_lstadd_back(*head, ft_lstnew(vec, sizeof(t_vectr)));
	}
	ft_del_mas_str(arr);
}

void	read_data(t_data *data, char **argv)
{
	int		fd;
	int 	i;
	char	*line;
	t_list	*head;
	t_vectr vec;

	line = NULL;
	head = NULL;
	i = 0;
	if ((fd = open(argv[0], O_RDONLY)) == -1)
		ft_error("Can't read source file!");
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0')
			ft_error("No data found.");
		vec.y = i;
		parse_cord(&vec, &head, line);
		free(line);
		i++;
	}
	close(fd);
	if (!head)
		ft_error("Source file is empty!");
	parse_arguments(data, head);
	ft_lstdel(&head, del_content);
}
