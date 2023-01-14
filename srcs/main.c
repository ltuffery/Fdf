/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:33:23 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/14 16:19:30 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stddef.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	data.points = get_content_file(av[1]);
	if (data.points == NULL)
		return (1);
}
