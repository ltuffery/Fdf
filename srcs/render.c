/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:52:39 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/16 23:43:13 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

void	dda(void)
{
}

static t_img	*create_img(t_data *data)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}

void	render(t_data *data, unsigned int color)
{
	char	*dst;
	int		x;
	int		y;

	dst = 0;
	y = 5;
	x = 5;
	data->img = create_img(data);
	if (data->img == NULL)
		return ;
	dst = data->img->addr + y * data->img->line_length + x * (data->img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
