/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:33:23 by cledant           #+#    #+#             */
/*   Updated: 2016/02/22 13:49:26 by cledant          ###   ########.fr       */
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

typedef struct	s_sphere
{
	int		color;
	double	coord[3];
	double	radius;
}				t_sphere;

typedef struct	s_plane
{
	int		color;
	double	coord[3];
	double	factor[3];
}				t_plane;

typedef struct	s_light
{
	int		color;
	double	coord[3];
}				t_light;

typedef struct	s_camera
{
	double	coord[3];
	double	camera_size[3];
	double	camera_look_at[3];
	double	dir_vec[3];
	double	norm;
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
	t_camera	*cam;
	t_list		*obj_list;
	t_list		*obj_light;
}				t_mlx;

int				expose_hook(t_mlx *e);
int				key_hook(int keycode, t_mlx *e);
void			ft_lstfree_malloc(void *content, size_t size);
t_sphere		*ft_sphere_new(int coloration, double origin[3], double size);
t_plane			*ft_plane_new(int coloration, double origin[3], double vec[3]);
void			ft_draw_image(t_mlx *e);
void			ft_init_scene(t_mlx *e);
int				ft_calc_int_sphere(t_sphere *sphere, t_camera *camera,
										double cur_dir[3], double *dist);
int				ft_calc_int_plane(t_plane *plane, t_camera *camera,
										double cur_dir[3], double *dist);
void			ft_rot_x(double (*vec)[3], double angle);
void			ft_rot_y(double (*vec)[3], double angle);
void			ft_rot_z(double (*vec)[3], double angle);
void			ft_scalar_product(double v1[3], double v2[3], double (*res)[3]);

#endif
