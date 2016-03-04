/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:33:23 by cledant           #+#    #+#             */
/*   Updated: 2016/03/04 20:05:47 by cledant          ###   ########.fr       */
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
# define MLX_KEY_UP 126
# define MLX_KEY_DOWN 125
# define MLX_KEY_RIGHT 124
# define MLX_KEY_LEFT 123
# define MLX_KEY_PLUS 69
# define MLX_KEY_MINUS 78
# define MLX_KEY_W 13
# define MLX_KEY_A 0
# define MLX_KEY_S 1
# define MLX_KEY_D 2
# define MLX_KEY_Q 12
# define MLX_KEY_E 14
# define MLX_KEY_1 18
# define MLX_KEY_2 19
# define MLX_CAM_STEP 0.5
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
	double	shiny;
}				t_sphere;

typedef struct	s_plane
{
	int		color;
	double	coord[3];
	double	factor[3];
	double	diffuse;
	double	ambiant;
	double	specular;
	double	shiny;
}				t_plane;

typedef struct	s_cylinder
{
	int		color;
	double	coord[3];
	double	dir[3];
	double	radius;
	double	diffuse;
	double	ambiant;
	double	specular;
	double	shiny;
}				t_cylinder;

typedef struct	s_cone
{
	int		color;
	double	coord[3];
	double	dir[3];
	double	angle;
	double	k;
	double	radius;
	double	diffuse;
	double	ambiant;
	double	specular;
	double	shiny;
}				t_cone;

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

void			ft_camera_init(t_camera *cam_scene);

void			ft_calc_int_pos(double dist, double cur_vec[3], double coord_cam[3],
					double (*int_coord)[3]);

t_light			*ft_light_new(double loc[3], int color);
int				ft_is_light_interrupt(t_light *light, t_list *list, 
					double int_coord[3]);
int				ft_getlight(t_list *obj, t_light *light, double int_coord[3],
					double norm_cur_dir[3]);
int				ft_getambiant_light(t_list *obj);

t_sphere		*ft_sphere_new(int coloration, double origin[3], double size);
void			ft_sphere_material(double amb, double diff, double spec,
					t_sphere *sph);
int				ft_sphere_getlight(t_sphere *obj, t_light *light,
					double int_coord[3], double cam_vector[3]);
int				ft_calc_int_sphere(t_sphere *sphere, t_camera *camera,
					double cur_dir[3], double *dist);
int				ft_calc_int_sphere_light(t_sphere *sphere, t_light *light,
					double cur_dir[3], double *dist);
int				ft_sphere_ambiant(t_sphere *obj);

t_cylinder		*ft_cylinder_new(int coloration, double origin[3], double size,
					double dir[3]);
void			ft_cylinder_material(double amb, double diff, double spec,
					t_cylinder *cyl);
int				ft_cylinder_getlight(t_cylinder *obj, t_light *light,
					double int_coord[3], double cam_vector[3]);
int				ft_calc_int_cylinder(t_cylinder *cyl, t_camera *camera,
					double cur_dir[3], double *dist);
int				ft_calc_int_cylinder_light(t_cylinder *cyl, t_light *light,
					double cur_dir[3], double *dist);
int				ft_cylinder_ambiant(t_cylinder *obj);

t_cone			*ft_cone_new(int coloration, double origin[3], double size,
					double dir[3]);
void			ft_cone_angle(double c_angle, t_cone *cone);
void			ft_cone_material(double amb, double diff, double spec,
					t_cone *cone);
int				ft_cone_getlight(t_cone *obj, t_light *light,
					double int_coord[3], double cam_vector[3]);
int				ft_calc_int_cone(t_cone *cone, t_camera *camera,
					double cur_dir[3], double *dist);
int				ft_calc_int_cone_light(t_cone *cone, t_light *light,
					double cur_dir[3], double *dist);
int				ft_cone_ambiant(t_cone *obj);

t_plane			*ft_plane_new(int coloration, double origin[3], double vec[3]);
void			ft_plane_material(double amb, double diff, double spec,
					t_plane *plane);
int				ft_plane_getlight(t_plane *obj, t_light *light,
					double int_coord[3], double cam_vector[3]);
int				ft_calc_int_plane(t_plane *plane, t_camera *camera,
					double cur_dir[3], double *dist);
int				ft_calc_int_plane_light(t_plane *plane, t_light *camera,
					double cur_dir[3], double *dist);
int				ft_plane_ambiant(t_plane *obj);

int				ft_add_color(int color1, int color2);

void			ft_draw_image(t_mlx *e);
void			ft_init_scene(t_mlx *e);
void			ft_init_scene_2(t_mlx *e);
void			ft_lstfree_malloc(void *content, size_t size);
int				ft_dot_product(double v1[3], double v2[3]);
void			ft_scalar_product(double v1[3], double v2[3], double (*res)[3]);
void			ft_normalize_vec(double (*vec)[3]);


#endif
