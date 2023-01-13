/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:29:53 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/12 17:01:53 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/fdf.h"
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img_ptr;
}	t_vars;

int	test(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_image(vars->mlx, vars->img_ptr->img);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			dst = data->addr + ((y + i) * data->line_length + (x + j) * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img_ptr = &img;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_hook(vars.mlx_win, 2, 1L << 0, test, &vars);
	mlx_loop(vars.mlx);
}
