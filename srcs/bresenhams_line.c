/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:28:57 by ddryha            #+#    #+#             */
/*   Updated: 2019/01/20 11:29:00 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#define CR_N(x) data->color[x]

static	int		sign(int x)
{
	if (x < 0)
		return (-1);
	if (x > 0)
		return (1);
	return (0);
}

static	void	init_bres(t_bres *br, t_data *data, int index1, int index2)
{
	br->x = data->result.values[index1][0];
	br->y = data->result.values[index1][1];
	br->dx = data->result.values[index2][0] - data->result.values[index1][0];
	br->dy = data->result.values[index2][1] - data->result.values[index1][1];
	br->s1 = sign(br->dx);
	br->s2 = sign(br->dy);
	br->dx = abs(br->dx);
	br->dy = abs(br->dy);
	if (br->dy > br->dx)
	{
		br->temp = br->dx;
		br->dx = br->dy;
		br->dy = br->temp;
		br->flg = 1;
	}
	br->error = 2 * br->dy - br->dx;
	br->color = !data->gradient ? data->color[index1][0] : data->gradient;
	if (data->color[index1][0] != data->color[index2][0] &&
		br->dx && !data->gradient)
		br->step = get_rgb_step(data->color[index1][0],
			data->color[index2][0], br->dx);
}

void			draw_line(t_data *data, int index1, int index2)
{
	int		i;
	t_bres	br;

	i = 0;
	ft_bzero(&br, sizeof(t_bres));
	init_bres(&br, data, index1, index2);
	while (br.dx && i++ <= br.dx)
	{
		mlx_pixel_put(data->mlx_ptr, data->win, br.x, br.y, br.color);
		while (br.error >= 0)
		{
			if (br.flg)
				br.x += br.s1;
			else
				br.y += br.s2;
			br.error = br.error - 2 * br.dx;
		}
		if (br.flg)
			br.y += br.s2;
		else
			br.x += br.s1;
		br.error = br.error + 2 * br.dy;
		if (CR_N(index1)[0] != CR_N(index2)[0] && br.dx && !data->gradient)
			br.color = make_gradient(br.color, br.step);
	}
}
