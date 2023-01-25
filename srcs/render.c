/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:52:39 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/23 14:38:11 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

t_point	*get_point(t_data *data, t_point point)
{
	float	angle;
	t_point	*new;

	(void) data;
	angle = 0.55;
	new = malloc(sizeof(t_point));
	new->x = (point.x - point.y) * cos(angle);
	new->x += WIDTH / 2 - data->map->total_x * 15 / 2;
	new->y = (point.x + point.y) * sin(angle) - point.z;
	new->y += HEIGHT / 2 - data->map->total_points * 15 / 4;
	return (new);
}

static void	put_pixel(t_data *data, int x, int y)
{
	char	*dst;

	dst = 0;
	dst = data->img->addr + \
		y * data->img->line_length + \
		x * (data->img->bits_per_pixel / 8);
	*(unsigned int *)dst = 0x00FF0000;
}

void	dda(t_data *data, t_point point0, t_point point1)
{
	char	*dst;
	t_point	inc;
	float	dx;
	float	dy;
	float	steps;

	dst = 0;
	dx = point1.x - point0.x;
	dy = point1.y - point0.y;
	steps = fmax(fabs(dx), fabs(dy));
	inc.x = dx / (float)steps;
	inc.y = dy / (float)steps;
	while (steps >= 0)
	{
		steps--;
		if (point0.x >= 0 && point0.x <= WIDTH)
			if (point0.y >= 0 && point0.y <= HEIGHT)
				put_pixel(data, (int)point0.x, (int)point0.y);
		point0.x += inc.x;
		point0.y += inc.y;
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

void	render(t_data *data)
{
	int		x;
	int		y;
	t_point	*point0;
	t_point	*point1;

	y = 0;
	data->img = create_img(data);
	if (data->img == NULL)
		return ;
	while (y < data->map->total_y - 1)
	{
		x = 0;
		while (x < data->map->total_x - 1)
		{
			point0 = get_point(data, data->map->points[y][x]);
			point1 = get_point(data, data->map->points[y][x + 1]);
			dda(data, *point0, *point1);
			free(point1);
			point1 = get_point(data, data->map->points[y + 1][x]);
			dda(data, *point0, *point1);
			free(point0);
			if (y == data->map->total_y - 2)
			{
				point0 = get_point(data, data->map->points[y + 1][x + 1]);
				dda(data, *point1, *point0);
				free(point0);
			}
			free(point1);
			x++;
		}
		point0 = get_point(data, data->map->points[y][x]);
		point1 = get_point(data, data->map->points[y + 1][x]);
		dda(data, *point0, *point1);
		free(point0);
		free(point1);
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
