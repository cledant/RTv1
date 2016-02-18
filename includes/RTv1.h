/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:33:23 by cledant           #+#    #+#             */
/*   Updated: 2016/02/18 12:54:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include <sys/time.h>
# include <stdio.h> //caca
# include "libft.h"
# define MLX_KEY_ESC 53
# define WIN_X 1000
# define WIN_Y 1000
# define FOV 90

typedef struct	s_sphere
{
	size_t	total_sp;
	int		color;
	double	coord[3];
	double	radius;
	double	rotation[3];
	double	translation[3];
}				t_sphere;

typedef struct	s_camera
{
	double	coord[3];
	double	camera_size[3];
	double	camera_look_at[3];
	double	dir_vec[3];
	double	normale;
	double	norm_dir_vec[3];
	double	up_vec[3];
	double	right_vec[3];
	double	x_inc;
	double	y_inc;
	double	up_left_win[3];
}				t_camera;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*c_img;
	int			render;
	double		dist_to_proj_plane;
	t_camera	*cam;
	t_sphere	*sph;
}				t_mlx;

int				expose_hook(t_mlx *e);
int				key_hook(int keycode, t_mlx *e);
void			ft_draw_image(t_mlx *e);
void			ft_init_scene(t_mlx *e);
int				ft_calc_int_sphere(t_mlx *e, double cur_dir[3], double (*coord)[3]);

#endif
