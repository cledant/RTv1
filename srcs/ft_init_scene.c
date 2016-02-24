/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:25:57 by cledant           #+#    #+#             */
/*   Updated: 2016/02/24 10:33:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_init_scene(t_mlx *e)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_light		*light;
	t_list		*begin;
	t_list		*member;
	t_camera	*cam_scene;
	double		tmp_coord[3];
	double		tmp_vec[3];

	cam_scene = e->cam;
	if ((begin = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	e->light_list = begin;
	tmp_coord[0] = 4;
	tmp_coord[1] = 4;
	tmp_coord[2] = 4;
	if ((light = ft_light_new(tmp_coord, 0x00FFFFFF)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	begin->content = light;
	begin->content_size = 0;
	if ((begin = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	e->obj_list = begin;
	tmp_coord[0] = 0;
	tmp_coord[1] = 0;
	tmp_coord[2] = 0;
	if ((sphere = ft_sphere_new(0x00AA0000, tmp_coord, 3)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.1, 1, 0.5, sphere);
	begin->content = sphere;
	begin->content_size = 0;
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = 0;
	tmp_coord[2] = 8;
	if ((sphere = ft_sphere_new(0x0000AA00, tmp_coord, 2)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.1, 1, 0.5, sphere);
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 8;
	tmp_coord[1] = 0;
	tmp_coord[2] = 0;
	if ((sphere = ft_sphere_new(0x000000AA, tmp_coord, 2)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.1, 1, 0.5, sphere);
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = 8;
	tmp_coord[2] = 0;
	if ((sphere = ft_sphere_new(0x00AA00AA, tmp_coord, 2)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.1, 1, 0.5, sphere);
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
//	if ((member = ft_lstnew(NULL, 0)) == NULL)
//	{
//		ft_putendl("Not enough memory");
//		key_hook(MLX_KEY_ESC, e);
//	}
//	tmp_coord[0] = 0;
//	tmp_coord[1] = 0;
//	tmp_coord[2] = 0;
//	tmp_vec[0] = 1;
//	tmp_vec[1] = 0;
//	tmp_vec[2] = 0;
//	if ((plane = ft_plane_new(0x00AAAAAA, tmp_coord, tmp_vec)) == NULL)
//	{
//		free(member);
//		ft_putendl("Not enough memory");
//		key_hook(MLX_KEY_ESC, e);	
//	}
//	ft_plane_material(0.1, 0.5, 0.5, plane);
//	member->content = plane;
//	member->content_size = 1;
//	ft_lstpushback(begin, member);
//	if ((member = ft_lstnew(NULL, 0)) == NULL)
//	{
//		ft_putendl("Not enough memory");
//		key_hook(MLX_KEY_ESC, e);
//	}
//	tmp_coord[0] = 0;
//	tmp_coord[1] = 0;
//	tmp_coord[2] = 0;
//	tmp_vec[0] = 0;
//	tmp_vec[1] = 0;
//	tmp_vec[2] = 1;
//	if ((plane = ft_plane_new(0x0000AAAA, tmp_coord, tmp_vec)) == NULL)
//	{
//		free(member);
//		ft_putendl("Not enough memory");
//		key_hook(MLX_KEY_ESC, e);	
//	}
//	ft_plane_material(0.1, 0.5, 0.5, plane);
//	member->content = plane;
//	member->content_size = 1;
//	ft_lstpushback(begin, member);
//	if ((member = ft_lstnew(NULL, 0)) == NULL)
//	{
//		ft_putendl("Not enough memory");
//		key_hook(MLX_KEY_ESC, e);
//	}
//	tmp_coord[0] = 0;
//	tmp_coord[1] = 0;
//	tmp_coord[2] = 0;
//	tmp_vec[0] = 0;
//	tmp_vec[1] = 1;
//	tmp_vec[2] = 0;
//	if ((plane = ft_plane_new(0x00AAAA00, tmp_coord, tmp_vec)) == NULL)
//	{
//		free(member);
//		ft_putendl("Not enough memory");
//		key_hook(MLX_KEY_ESC, e);	
//	}
//	ft_plane_material(0.1, 0.5, 0.5, plane);
//	member->content = plane;
//	member->content_size = 1;
//	ft_lstpushback(begin, member);
	//debut init camera
	cam_scene->coord[0] = 500;
	cam_scene->coord[1] = 500;
	cam_scene->coord[2] = 500;
	cam_scene->camera_size[0] = 20;
	cam_scene->camera_size[1] = 20;
	cam_scene->camera_size[2] = 1;
	cam_scene->camera_look_at[0] = 0;
	cam_scene->camera_look_at[1] = 0;
	cam_scene->camera_look_at[2] = 0;
	cam_scene->dir_vec[0] = cam_scene->camera_look_at[0] - cam_scene->coord[0];
	cam_scene->dir_vec[1] = cam_scene->camera_look_at[1] - cam_scene->coord[1];
	cam_scene->dir_vec[2] = cam_scene->camera_look_at[2] - cam_scene->coord[2];
	cam_scene->norm = sqrt(cam_scene->dir_vec[0] * cam_scene->dir_vec[0] +
		cam_scene->dir_vec[1] * cam_scene->dir_vec[1] + cam_scene->dir_vec[2] *
		cam_scene->dir_vec[2]);
	cam_scene->norm_dir_vec[0] = cam_scene->dir_vec[0] / cam_scene->norm;
	cam_scene->norm_dir_vec[1] = cam_scene->dir_vec[1] / cam_scene->norm;
	cam_scene->norm_dir_vec[2] = cam_scene->dir_vec[2] / cam_scene->norm;
	printf("dir_vec = %f\n", cam_scene->norm_dir_vec[0]);
	printf("dir_vec = %f\n", cam_scene->norm_dir_vec[1]);
	printf("dir_vec = %f\n", cam_scene->norm_dir_vec[2]);
	// debut triangle ortho
	if (cam_scene->coord[0] == 0 && cam_scene->coord[1] == 0 &&
			cam_scene->coord[2] > 0)
	{
		cam_scene->up_vec[0] = -1;
		cam_scene->up_vec[1] = 0;
		cam_scene->up_vec[2] = 0;
	}
	else if (cam_scene->coord[0] == 0 && cam_scene->coord[1] == 0 &&
			cam_scene->coord[2] < 0)
	{
		cam_scene->up_vec[0] = 1;
		cam_scene->up_vec[1] = 0;
		cam_scene->up_vec[2] = 0;
	}
	else
	{
		cam_scene->up_vec[0] = 0;
		cam_scene->up_vec[1] = 0;
		cam_scene->up_vec[2] = 1;
	}
	cam_scene->right_vec[0] = 0;
	cam_scene->right_vec[1] = 0;
	cam_scene->right_vec[2] = 0;
	ft_scalar_product(cam_scene->up_vec, cam_scene->norm_dir_vec,
			&cam_scene->right_vec);
	ft_scalar_product(cam_scene->right_vec, cam_scene->norm_dir_vec, 
			&cam_scene->up_vec);
	// fin triangle ortho
	printf("up_vec = %f\n", cam_scene->up_vec[0]);
	printf("up_vec = %f\n", cam_scene->up_vec[1]);
	printf("up_vec = %f\n", cam_scene->up_vec[2]);
	printf("right_vec = %f\n", cam_scene->right_vec[0]);
	printf("right_vec = %f\n", cam_scene->right_vec[1]);
	printf("right_vec = %f\n", cam_scene->right_vec[2]);
	cam_scene->up_left_win[0] = cam_scene->coord[0] +
			((cam_scene->norm_dir_vec[0] *
				cam_scene->camera_size[2]) + (cam_scene->up_vec[0] *
					(cam_scene->camera_size[1] / (double)2)) -
						(cam_scene->right_vec[0] * (cam_scene->camera_size[0] /
													(double)2)));
	cam_scene->up_left_win[1] = cam_scene->coord[1] + ((cam_scene->norm_dir_vec[1] *
				cam_scene->camera_size[2]) + (cam_scene->up_vec[1] *
					(cam_scene->camera_size[1] / (double)2)) -
						(cam_scene->right_vec[1] * (cam_scene->camera_size[0] /
													(double)2)));
	cam_scene->up_left_win[2] = cam_scene->coord[2] +
		((cam_scene->norm_dir_vec[2] *
				cam_scene->camera_size[2]) + (cam_scene->up_vec[2] *
					(cam_scene->camera_size[1] / (double)2)) -
						(cam_scene->right_vec[2] * (cam_scene->camera_size[0] /
													(double)2)));
	printf("up_left = %f\n", cam_scene->up_left_win[0]);
	printf("up_left = %f\n", cam_scene->up_left_win[1]);
	printf("up_left = %f\n", cam_scene->up_left_win[2]);
	cam_scene->x_inc = cam_scene->camera_size[0] / (double)WIN_X;
	cam_scene->y_inc = cam_scene->camera_size[1] / (double)WIN_Y;
	//fin camera
}
