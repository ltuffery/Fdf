/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:33:16 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/11 10:10:51 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

static size_t	count_str_item(char **tab)
{
	size_t	nb_items;

	nb_items = 0;
	while (tab[nb_items] != NULL)
		nb_items++;
	return (nb_items);
}

char	*file_basename(char *file_name)
{
	char	**tab;
	size_t	count_items;

	tab = ft_split(file_name, '.');
	count_items = count_str_item(tab);
	if (count_items < 2)
		return (NULL);
	return (tab[count_items - 1]);
}

int	file_basename_is(char *file_name, char *basename)
{
	char	*base;
	int		len;

	len = ft_strlen(basename);
	base = file_basename(file_name);
	if (ft_strncmp(base, basename, len) == 0)
		if (ft_strlen(base) == len)
			return (1);
	return (0);
}
