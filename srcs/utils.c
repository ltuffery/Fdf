/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:10:18 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/16 21:11:28 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	count_split_items(char **items)
{
	int	i;

	i = 0;
	while (items[i] != NULL)
		i++;
	return (i);
}
