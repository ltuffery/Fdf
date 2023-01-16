/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:56:51 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/16 22:29:34 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/fdf.h"
#include <fcntl.h>

#define LEN_EXTENSION 4

static void	check_extension_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len <= 3)
		error("The file extension is not correct");
	if (ft_strncmp(&file[len - LEN_EXTENSION], ".fdf", LEN_EXTENSION) != 0)
		error("The file extension is not correct");
}

static char	**get_content(char *file)
{
	int		fd;
	char	*line;
	char	**content;

	fd = open(file, O_RDONLY);
	content = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	while (line != NULL)
	{
		content = ft_strappend(line, content);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}

static t_map	*fill_map(char **content, t_map *map)
{
	int		i;
	int		j;
	int		size;
	char	**split;

	i = 0;
	while (content[i] != NULL)
	{
		j = 0;
		split = ft_split(content[i], ' ');
		size = count_split_items(split);
		if (map->total_x > size)
			map->total_x = size;
		map->points[i] = malloc(sizeof(int) * size);
		if (map->points[i] == NULL)
			return (NULL);
		while (split[j] != NULL)
		{
			map->points[i][j] = ft_atoi(split[j]);
			j++;
		}
		tab_clean(split);
		i++;
	}
	return (map);
}

static t_map	*convert_tab_char_to_map(char **content)
{
	t_map	*map;
	int		size;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	size = count_split_items(content);
	map->points = malloc(sizeof(int *) * size);
	if (map->points == NULL)
		return (NULL);
	map->total_x = ft_strlen(content[0]);
	map->total_y = size;
	map = fill_map(content, map);
	if (map == NULL)
		return (NULL);
	return (map);
}

t_map	*parse_file(char *file)
{
	char	**content;
	t_map	*map;

	check_extension_file(file);
	content = get_content(file);
	if (content == NULL)
		error("Content file is not valid");
	map = convert_tab_char_to_map(content);
	tab_clean(content);
	return (map);
}
