/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:10:18 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/26 18:44:39 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

int	count_split_items(char **items)
{
	int	i;

	i = 0;
	while (items[i] != NULL)
		i++;
	return (i);
}

void	error(char const *msg)
{
	ft_putendl_fd((char *)msg, 1);
	exit(1);
}

int	create_trgb(unsigned char t, unsigned char r, \
		unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
