/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:25:57 by cledant           #+#    #+#             */
/*   Updated: 2016/02/18 12:54:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_init_scene(t_mlx *e)
{
	t_sphere	*sp_scene;
	t_camera	*cam_scene;

	cam_scene = e->cam;
	sp_scene = e->sph;
	sp_scene->total_sp = 1;
	sp_scene->color = 0x00FF0000;
	sp_scene->coord[0] = 0;
	sp_scene->coord[1] = 0;
	sp_scene->coord[2] = 0;
	sp_scene->radius = 1;
	cam_scene->coord[0] = -200;
	cam_scene->coord[1] = 0;
	cam_scene->coord[2] = 0;
	cam_scene->camera_size[0] = 0.5 * 10;
	cam_scene->camera_size[1] = 0.5 * 10;
	cam_scene->camera_size[2] = 1 * 10;
	cam_scene->camera_look_at[0] = 0;
	cam_scene->camera_look_at[1] = 0;
	cam_scene->camera_look_at[2] = 0;
	cam_scene->dir_vec[0] = cam_scene->camera_look_at[0] - cam_scene->coord[0];
	cam_scene->dir_vec[1] = cam_scene->camera_look_at[1] - cam_scene->coord[1];
	cam_scene->dir_vec[2] = cam_scene->camera_look_at[2] - cam_scene->coord[2];
	cam_scene->normale = sqrt(cam_scene->dir_vec[0] * cam_scene->dir_vec[0] +
		cam_scene->dir_vec[1] * cam_scene->dir_vec[1] + cam_scene->dir_vec[2] *
		cam_scene->dir_vec[2]);
	cam_scene->norm_dir_vec[0] = cam_scene->dir_vec[0] / cam_scene->normale;
	cam_scene->norm_dir_vec[1] = cam_scene->dir_vec[1] / cam_scene->normale;
	cam_scene->norm_dir_vec[2] = cam_scene->dir_vec[2] / cam_scene->normale;
	/*
	** Hard code of norm_dir_rotation
	**  x' = -y
	**  y' = x
	*/
	printf("dir_vec = %f\n", cam_scene->norm_dir_vec[0]);
	printf("dir_vec = %f\n", cam_scene->norm_dir_vec[1]);
	printf("dir_vec = %f\n", cam_scene->norm_dir_vec[2]);
	cam_scene->up_vec[0] = -cam_scene->norm_dir_vec[2];
	cam_scene->up_vec[1] = cam_scene->norm_dir_vec[1];
	cam_scene->up_vec[2] = cam_scene->norm_dir_vec[0];
	cam_scene->right_vec[0] = -cam_scene->norm_dir_vec[1];
	cam_scene->right_vec[1] = cam_scene->norm_dir_vec[0];
	cam_scene->right_vec[2] = cam_scene->norm_dir_vec[2];
	printf("right_vec = %f\n", cam_scene->right_vec[0]);
	printf("right_vec = %f\n", cam_scene->right_vec[1]);
	printf("right_vec = %f\n", cam_scene->right_vec[2]);
	printf("up_vec = %f\n", cam_scene->up_vec[0]);
	printf("up_vec = %f\n", cam_scene->up_vec[1]);
	printf("up_vec = %f\n", cam_scene->up_vec[2]);
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
