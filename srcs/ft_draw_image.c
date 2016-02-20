/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:49:40 by cledant           #+#    #+#             */
/*   Updated: 2016/02/20 18:38:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_draw_image(t_mlx *e)
{
	int			counter[3];
	double		cur_dir[3];
	double		val_cur_dir;
	double		norm_cur_dir[3];
	double		dist;
	t_camera	*camera;
	t_list		*lst;

	camera = e->cam;
	lst = e->obj_list;
	counter[0] = 0;
	counter[1] = 0;
	dist = 1000000;
//	printf("camera.up_left_vec = %f\n", camera->up_left_win[0]);
//	printf("camera.up_left_vec = %f\n", camera->up_left_win[1]);
//	printf("camera.up_left_vec = %f\n", camera->up_left_win[2]);
	while (counter[0] < WIN_Y)
	{
		while (counter[1] < WIN_X)
		{
			cur_dir[0] = camera->up_left_win[0] + counter[1] * camera->x_inc *
				camera->right_vec[0] - counter[0] * camera->y_inc *
					camera->up_vec[0];
			cur_dir[1] = camera->up_left_win[1] + counter[1] * camera->x_inc *
				camera->right_vec[1] - counter[0] * camera->y_inc *
					camera->up_vec[1];
			cur_dir[2] = camera->up_left_win[2] + counter[1] * camera->x_inc *
				camera->right_vec[2] - counter[0] * camera->y_inc *
					camera->up_vec[2];
			val_cur_dir = sqrt(cur_dir[0] * cur_dir[0] + cur_dir[1] * cur_dir[1] +
				cur_dir[2] * cur_dir[2]);
			norm_cur_dir[0] = cur_dir[0] / val_cur_dir;
			norm_cur_dir[1] = cur_dir[1] / val_cur_dir;
			norm_cur_dir[2] = cur_dir[2] / val_cur_dir;
//			printf("LIGNE = %d\n", counter[0]);
//			printf("COLONNE = %d\n", counter[1]);
			while (lst != NULL)
			{
				if (lst->content_size == 0)
				{		
					if (ft_calc_int_sphere(lst->content, camera, 
								norm_cur_dir, &dist) == 1)
						counter[2] = ((t_sphere *)(lst->content))->color;
				}
				else if (lst->content_size == 1)
				{
					if (ft_calc_int_plane(lst->content, camera, 
								norm_cur_dir, &dist) == 1)
						counter[2] = ((t_plane *)(lst->content))->color;
				}
				ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
								&counter[2], sizeof(int));
				lst = lst->next;
			}
			dist = 1000000;
			lst = e->obj_list;
			counter[1]++;
		}
		counter[1] = 0;
		counter[0]++;
	}
}
