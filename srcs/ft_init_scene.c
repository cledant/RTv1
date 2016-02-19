/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:25:57 by cledant           #+#    #+#             */
/*   Updated: 2016/02/19 15:44:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_init_scene(t_mlx *e)
{
	t_sphere	*sp_scene;
	t_camera	*cam_scene;
	double		angle[2];

	cam_scene = e->cam;
	sp_scene = e->sph;
	sp_scene->color = 0x00FF0000;
	sp_scene->coord[0] = 0;
	sp_scene->coord[1] = 0;
	sp_scene->coord[2] = 0;
	sp_scene->radius = 1;
	cam_scene->coord[0] = -500;
	cam_scene->coord[1] = 0;
	cam_scene->coord[2] = 0;
	cam_scene->camera_size[0] = 5;
	cam_scene->camera_size[1] = 5;
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
}
