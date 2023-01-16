/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:33:23 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/16 22:28:00 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	data.map = parse_file(av[1]);
	if (data.map == NULL)
		error("Error");
	printf("%i", data.map->points[0][2]);
	clean_points(data.map->points, data.map->total_y);
	free(data.map);
}
