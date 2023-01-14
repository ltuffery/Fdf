/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:10:31 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/14 16:19:03 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_NAME "fdf"
# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920

/*	STRUCT	*/
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		**points;
}	t_data;

/*	READ_FILE	*/
int	**get_content_file(char *file);

#endif
