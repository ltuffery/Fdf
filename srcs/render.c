/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:52:39 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/19 10:58:57 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	find_point(int *x, int *y, int z)
{
	float	angle;

	angle = 0.72;
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	dda(t_data *data, int X0, int Y0, int X1, int Y1)
{
	int		dx;
	int		dy;
	char	*dst;
	int		steps;

	dy = Y1 - Y0;
	dx = X1 - X0;
	dst = 0;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	dx = dx / steps;
	dy = dy / steps;
	for (int i = 0; i <= steps; i++) {
	dst = data->img->addr + \
		(HEIGHT / 2 + Y0) * data->img->line_length + \
		(WIDTH / 2 + X0) * (data->img->bits_per_pixel / 8);
	*(unsigned int *)dst = 0x00FF0000;
	X0 += dx;
	Y0 += dy;
	}
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

void	render(t_data *data, unsigned int color)
{
	char	*dst = 0;
	int	i;
	int	j;
	int	x;
	int	y;

	(void) color;
	j = 0;
	data->img = create_img(data);
	if (data->img == NULL)
		return ;
	while (j < data->map->total_y)
	{
		i = 0;
		while (i < data->map->total_x)
		{
			x = i;
			y = j;
			find_point(&x, &y, data->map->points[j][i]);
			dst = data->img->addr + \
				(HEIGHT / 2 + y * 15) * data->img->line_length + \
				(WIDTH / 2 + x * 15) * (data->img->bits_per_pixel / 8);
			*(unsigned int *)dst = 0x00FF0000;
			printf("x : %i | y : %i\n", x, y);
			i++;
		}
		printf("----------------\n");
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
