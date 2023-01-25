/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:10:31 by ltuffery          #+#    #+#             */
/*   Updated: 2023/01/23 14:38:24 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define NAME "fdf"
# define HEIGHT 1080
# define WIDTH 1920

/*	STRUCT	*/
typedef struct s_point
{
	float	x;
	float	y;
	int		z;
}	t_point;

typedef struct s_map
{
	int		total_x;
	int		total_y;
	int		total_points;
	t_point	**points;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_map	*map;
}	t_data;

/*	PARSE_FILE	*/
t_map	*parse_file(char *file);

/*	ERROR	*/
void	error(char const *msg);

/*	CLEAN	*/
void	tab_clean(char **tab);
void	clean_points(t_point **points, int items);

/*	UTILS	*/
int		count_split_items(char **items);

/*	EVENTS	*/
int		esc(int keycode, t_data *data);
int		quit(t_data *data);

/*	RENDER	*/
void	render(t_data *data);

#endif
