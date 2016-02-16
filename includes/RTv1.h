/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:33:23 by cledant           #+#    #+#             */
/*   Updated: 2016/02/16 19:38:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include <sys/time.h>
# include "libft.h"
# define MLX_KEY_ESC 53
# define WIN_X 1280
# define WIN_Y 720
# define FOV 90

typedef struct	s_sphere
{
	size_t	total_sp;
	double	coord[3];
	double	rotation[3];
	double	translation[3];
}				t_sphere;

typedef struct	s_camera
{
	double	coord[3];
	double	angle[2];
}				t_camera;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			render;
	double		dist_to_proj_plane;
	t_camera	cam;
	t_sphere	sph;
}				t_mlx;

int				expose_hook(t_mlx *e);
int				key_hook(int keycode, t_mlx *e);
void			ft_draw_image(t_mlx *e);
void			ft_init_scene(t_mlx *e);
void			ft_move_cart_with_sph(double (*cart)[3],
					double radius, double angle[2])

#endif
