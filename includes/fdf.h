/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:10:31 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/16 21:48:08 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_NAME "fdf"
# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920

/*	STRUCT	*/
typedef struct s_map
{
	int	total_x;
	int	total_y;
	int	**points;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_data;

/*	PARSE_FILE	*/
t_map	*parse_file(char *file);

/*	ERROR	*/
void	error(char const *msg);

/*	CLEAN	*/
void	tab_clean(char **tab);
void	clean_points(int **points, int items);

/*	UTILS	*/
int		count_split_items(char **items);

#endif
