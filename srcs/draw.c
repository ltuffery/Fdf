/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:22:03 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/29 15:51:57 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

static void	put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = 0;
	dst = data->img->addr + \
		y * data->img->line_length + \
		x * (data->img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

void	dda(t_data *data, t_point point0, t_point point1)
{
	t_point	inc;
	float	dx;
	float	dy;
	float	steps;

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
				put_pixel(data, (int)point0.x, (int)point0.y, point0.color);
		point0.x += inc.x;
		point0.y += inc.y;
	}
}
