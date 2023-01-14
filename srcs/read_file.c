/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:34:40 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/14 16:16:02 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include <fcntl.h>

static int	check_extension_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (ft_strncmp(&file[len - 4], ".fdf", 4) == 0)
		return (1);
	return (0);
}

static int	check_len_line(char *file)
{
	int		fd;
	char	*line;
	size_t	prev_len;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	prev_len = ft_strlen(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (prev_len != ft_strlen(line))
		{
			free(line);
			return (0);
		}
	}
	free(line);
	close(fd);
	return (1);
}

int	**get_content_file(char *file)
{
	if (check_extension_file(file) == 0)
		return (NULL);
	if (check_len_line(file) == 0)
		return (NULL);
	return (NULL);
}
