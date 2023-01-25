/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:52:39 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/25 17:46:56 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>

static t_point	*get_point(t_data *data, t_point point)
{
	float	angle;
	float	x;
	float	y;
	t_point	*new;

	angle = 0.5;
	x = point.x;
	y = point.y;
	new = malloc(sizeof(t_point));
	new->x = (x - point.y) * cos(angle) + WIDTH / 2;
	new->y = (point.x + y) * sin(angle) - point.z + HEIGHT / 2;
	(void) data;
	return (new);
}

static t_img	*create_img(t_data *data)
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

static void	line(t_data *data, t_point p0, t_point p1)
{
	t_point	*point0;
	t_point	*point1;

	point0 = get_point(data, p0);
	point1 = get_point(data, p1);
	dda(data, *point0, *point1);
	free(point0);
	free(point1);
}

void	render(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	data->img = create_img(data);
	if (data->img == NULL)
		return ;
	while (y < data->map->total_y - 1)
	{
		x = 0;
		while (x < data->map->total_x - 1)
		{
			line(data, data->map->points[y][x], data->map->points[y][x + 1]);
			line(data, data->map->points[y][x], data->map->points[y + 1][x]);
			if (y == data->map->total_y - 2)
				line(data, data->map->points[y + 1][x + 1], \
						data->map->points[y + 1][x]);
			x++;
		}
		line(data, data->map->points[y][x], data->map->points[y + 1][x]);
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
