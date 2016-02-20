/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:25:57 by cledant           #+#    #+#             */
/*   Updated: 2016/02/20 16:19:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_init_scene(t_mlx *e)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_list		*begin;
	t_list		*member;
	t_camera	*cam_scene;
	double		angle[2];
	double		tmp_coord[3];
	double		tmp_vec[3];

	cam_scene = e->cam;
	if ((begin = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	e->obj_list = begin;
	tmp_coord[0] = 0;
	tmp_coord[1] = 0;
	tmp_coord[2] = 0;
	if ((sphere = ft_sphere_new(0x00FF0000, tmp_coord, 2)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	begin->content = sphere;
	begin->content_size = 0;
//	if ((member = ft_lstnew(NULL, 0)) == NULL)
//	{
//		ft_putendl("Not enough memory");
//		key_hook(MLX_KEY_ESC, e);
//	}
//	tmp_coord[0] = -3;
//	tmp_coord[1] = 0;
//	tmp_coord[2] = 0;
//	if ((sphere = ft_sphere_new(0x0000FF00, tmp_coord, 3)) == NULL)
//	{
//		free(member);
//		ft_putendl("Not enough memory");
//		key_hook(MLX_KEY_ESC, e);	
//	}
//	member->content = sphere;
//	member->content_size = 0;
//	ft_lstpushback(begin, member);
//	if ((member = ft_lstnew(NULL, 0)) == NULL)
//	{
//		ft_putendl("Not enough memory");
//		key_hook(MLX_KEY_ESC, e);
//	}
//	tmp_coord[0] = 5;
//	tmp_coord[1] = 0;
//	tmp_coord[2] = 0;
//	if ((sphere = ft_sphere_new(0x000000FF, tmp_coord, 2)) == NULL)
//	{
//		free(member);
//		ft_putendl("Not enough memory");
//		key_hook(MLX_KEY_ESC, e);	
//	}
//	member->content = sphere;
//	member->content_size = 0;
//	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = 0;
	tmp_coord[2] = 0;
	tmp_vec[0] = 1;
	tmp_vec[1] = 1;
	tmp_vec[2] = 0;
	if ((plane = ft_plane_new(0x00FFFFFF, tmp_coord, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	member->content = plane;
	member->content_size = 1;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = 0;
	tmp_coord[2] = 0;
	tmp_vec[0] = 1;
	tmp_vec[1] = 0;
	tmp_vec[2] = 1;
	if ((plane = ft_plane_new(0x0000FFFF, tmp_coord, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	member->content = plane;
	member->content_size = 1;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = 0;
	tmp_coord[2] = 0;
	tmp_vec[0] = 0;
	tmp_vec[1] = 1;
	tmp_vec[2] = 1;
	if ((plane = ft_plane_new(0x00FFFF00, tmp_coord, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	member->content = plane;
	member->content_size = 1;
	ft_lstpushback(begin, member);
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
	angle[0] = acos(cam_scene->norm_dir_vec[2]);
	if (angle[0] == 0)
		angle[1] = 0;
	else
		angle[1] = acos(cam_scene->norm_dir_vec[0] / (cos(M_PI_2 - angle[0])));
	cam_scene->up_vec[0] = 1;
	cam_scene->up_vec[1] = 0;
	cam_scene->up_vec[2] = 0;
	if ((cam_scene->coord[0] == 0 && cam_scene->coord[1] == 0) || 
			(cam_scene->coord[1] == 0 && cam_scene->coord[2] == 0) ||
				(cam_scene->coord[0] == 0 && cam_scene->coord[2] == 0) ||
					(cam_scene->coord[2] == 0 && cam_scene->coord[0] &&
					 	cam_scene->coord[1] != 0))
	{
		ft_rot_y(&cam_scene->up_vec, -angle[0]);
		printf("angle[0] = %f\n", -angle[0]);
	}
	else
	{
		ft_rot_y(&cam_scene->up_vec, -angle[0] - M_PI_2);
		printf("angle[0] = %f\n", -angle[0] - M_PI_2);
	}
	printf("angle[1] = %f\n", angle[1]);
	ft_rot_z(&cam_scene->up_vec, angle[1]);
	cam_scene->right_vec[0] = (cam_scene->norm_dir_vec[1] * cam_scene->up_vec[2] - cam_scene->norm_dir_vec[2] * cam_scene->up_vec[1]);
	cam_scene->right_vec[1] = (cam_scene->norm_dir_vec[2] * cam_scene->up_vec[0] - cam_scene->norm_dir_vec[0] * cam_scene->up_vec[2]);
	cam_scene->right_vec[2] = (cam_scene->norm_dir_vec[0] * cam_scene->up_vec[1] - cam_scene->norm_dir_vec[1] * cam_scene->up_vec[0]);
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
	cam_scene->x_inc = cam_scene->camera_size[0] / (double)WIN_X;
	cam_scene->y_inc = cam_scene->camera_size[1] / (double)WIN_Y;
	//fin camera
}
