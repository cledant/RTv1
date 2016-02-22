/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:33:23 by cledant           #+#    #+#             */
/*   Updated: 2016/02/22 20:14:31 by cledant          ###   ########.fr       */
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
	double	diffuse;
	double	ambiant;
	double	specular;
}				t_sphere;

typedef struct	s_plane
{
	int		color;
	double	coord[3];
	double	factor[3];
	double	diffuse;
	double	ambiant;
	double	specular;
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
	t_list		*light_list;
}				t_mlx;

int				expose_hook(t_mlx *e);
int				key_hook(int keycode, t_mlx *e);
void			ft_lstfree_malloc(void *content, size_t size);
t_light			ft_light_new(double loc[3], int color);
t_sphere		*ft_sphere_new(int coloration, double origin[3], double size);
void			ft_sphere_material(double amb, double diff, double spec,
					t_sphere *sph);
int				ft_sphere_difflight(t_sphere *obj, t_light, double int_coord[3]);
int				ft_sphere_ambiant(t_sphere *sph);
int				ft_calc_int_sphere(t_sphere *sphere, t_camera *camera,
					double cur_dir[3], double *dist);
int				ft_sphere_has_int(t_sphere *sphere, t_light *light,
					double cur_dir[3]);
t_plane			*ft_plane_new(int coloration, double origin[3], double vec[3]);
void			ft_plane_material(double amb, double diff, double spec,
					t_plane *plane);
int				ft_plane_difflight(t_plane *obj, t_light *light,
					double int_coord[3]);
int				ft_plane_ambiant(t_plane *pl);
int				ft_plane_has_int(t_plane *plane, t_light *light,
					double cur_dir[3]);
int				ft_calc_int_plane(t_plane *plane, t_camera *camera,
					double cur_dir[3], double *dist);
void			ft_calc_int_pos(double dist, double cur_vec[3],
					double (*int_coord)[3]);
void			ft_draw_image(t_mlx *e);
void			ft_init_scene(t_mlx *e);
void			ft_rot_x(double (*vec)[3], double angle);
void			ft_rot_y(double (*vec)[3], double angle);
void			ft_rot_z(double (*vec)[3], double angle);
void			ft_scalar_product(double v1[3], double v2[3], double (*res)[3]);

#endif
