/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:10:18 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/25 17:04:54 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../libft/includes/libft.h"
#include "../includes/fdf.h"
#include <stdio.h>

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
