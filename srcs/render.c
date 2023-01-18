/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:52:39 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/18 17:35:52 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

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
		Y0 * data->img->line_length + \
		X0 * (data->img->bits_per_pixel / 8);
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
	char	*dst;
	int		x;
	int		y;

	(void) color;
	dst = 0;
	y = HEIGHT / 2;
	x = WIDTH / 2;
	data->img = create_img(data);
	if (data->img == NULL)
		return ;
	dda(data, 0, 0, 6, 6);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
