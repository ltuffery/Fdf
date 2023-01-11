/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:29:53 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/10 16:42:43 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}	t_vars;

int	test(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.mlx_win, 2, 1L << 0, test, &vars);
	mlx_loop(vars.mlx);
}
