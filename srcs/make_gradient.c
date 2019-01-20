/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_gradient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:30:15 by ddryha            #+#    #+#             */
/*   Updated: 2019/01/20 11:30:17 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_color	get_rgb(int color)
{
	t_color result;
	int		shift;
	int		i;
	int		temp[3];

	i = -1;
	shift = 16;
	while (++i < 3)
	{
		temp[i] = (color >> shift) & 0xFF;
		shift -= 8;
	}
	result.r = temp[0];
	result.g = temp[1];
	result.b = temp[2];
	return (result);
}

t_color	get_rgb_step(int color1, int color2, int length)
{
	t_color rgb1;
	t_color rgb2;
	t_color result;

	rgb1 = get_rgb(color1);
	rgb2 = get_rgb(color2);
	result.r = (rgb2.r - rgb1.r) / length;
	result.g = (rgb2.g - rgb1.g) / length;
	result.b = (rgb2.b - rgb1.b) / length;
	return (result);
}

int		make_gradient(int color, t_color step)
{
	t_color	temp;
	int		result;

	temp = get_rgb(color);
	result = temp.r + step.r;
	result = result << 8 | (temp.g + step.g);
	result = result << 8 | (temp.b + step.b);
	return (result);
}

void	change_color(t_data *data, int key)
{
	if (key == ONE)
		data->gradient = 0x0AFF01;
	if (key == TWO)
		data->gradient = 0xFF0000;
	if (key == THREE)
		data->gradient = 0xFFCC08;
	if (key == FOUR)
		data->gradient = 0x00FFFF;
	if (key == FIVE)
		data->gradient = 0;
}
