/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:52:39 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/21 15:12:33 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

t_point	*get_point(t_point point)
{
	float	angle;
	t_point	*new;

	angle = 0.55;
	new = malloc(sizeof(t_point));
	new->x = (point.x - point.y) * cos(angle);
	new->y = (point.x + point.y) * sin(angle) - point.z;
	return (new);
}

void	dda(t_data *data, t_point point0, t_point point1)
{
	char	*dst;
	t_point	inc;
	int		dx;
	int		dy;
	int		steps;

	dst = 0;
	dx = point1.x - point0.x;
	dy = point1.y - point0.y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	inc.x = dx / (float)steps;
	inc.y = dy / (float)steps;
	while (steps >= 0)
	{
		dst = data->img->addr + \
			(HEIGHT / 2 + (int)point0.y) * data->img->line_length + \
			(WIDTH / 2 + (int)point0.x) * (data->img->bits_per_pixel / 8);
		*(unsigned int *)dst = 0x00FF0000;
		point0.x += inc.x;
		point0.y += inc.y;
		steps--;
	}
}

t_img	*create_img(t_data *data)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, \
			&img->bits_per_pixel, \
			&img->line_length, \
			&img->endian);
	return (img);
}

void	render(t_data *data, unsigned int color)
{
	int		x;
	int		y;
	t_point	*point0;
	t_point	*point1;

	(void) color;
	y = 0;
	data->img = create_img(data);
	if (data->img == NULL)
		return ;
	while (y < data->map->total_y - 1)
	{
		x = 0;
		while (x < data->map->total_x - 1)
		{
			point0 = get_point(data->map->points[y][x]);
			point1 = get_point(data->map->points[y][x + 1]);
			dda(data, *point0, *point1);
			free(point1);
			point1 = get_point(data->map->points[y + 1][x]);
			dda(data, *point0, *point1);
			free(point0);
			free(point1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
