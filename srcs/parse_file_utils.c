/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:02:39 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/29 16:04:55 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	count_file_lines(char *file)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}
