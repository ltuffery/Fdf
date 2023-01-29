/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:10:18 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/28 20:32:42 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"
#include <math.h>

#define RESIZE_VALUE 0.65

int	count_split_items(char **items)
{
	int	i;

	i = 0;
	while (items[i] != NULL)
		i++;
	return (i);
}

void	error(char const *msg)
{
	ft_putendl_fd((char *)msg, 1);
	exit(1);
}

int	create_trgb(unsigned char t, unsigned char r, \
		unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	find_zoom(t_map *map)
{
	float	d;
	t_point	*point0;
	t_point	*point1;

	point0 = get_point(map->points[0][0]);
	point1 = get_point(map->points[0][map->total_x - 1]);
	d = sqrtf(powf((point1->x - point0->x), 2) + \
			powf((point1->y - point0->y), 2));
	while (d > HEIGHT)
	{
		d *= RESIZE_VALUE;
		map->zoom *= RESIZE_VALUE;
	}
	free(point0);
	free(point1);
}
