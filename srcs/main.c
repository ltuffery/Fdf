/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:33:23 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/28 18:45:33 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

static void	create_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, NAME);
	mlx_hook(data->win, 2, 1L << 0, esc, data);
	mlx_hook(data->win, 17, 0, quit, data);
	render(data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	data.img = NULL;
	data.map = parse_file(av[1]);
	if (data.map == NULL)
		error("Error");
	create_window(&data);
}
