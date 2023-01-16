/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:38:19 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/16 23:33:11 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

static void	window_close(t_data *data)
{
	if (data->img != NULL)
		mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	clean_points(data->map->points, data->map->total_y);
	free(data->map);
	exit(0);
}

int	esc(int keycode, t_data *data)
{
	if (keycode == 65307)
		window_close(data);
	return (0);
}

int	quit(t_data *data)
{
	window_close(data);
	return (0);
}
