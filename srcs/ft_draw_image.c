/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:49:40 by cledant           #+#    #+#             */
/*   Updated: 2016/03/04 10:59:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_draw_image(t_mlx *e)
{
	int			counter[5];
	double		cur_dir[3];
	double		val_cur_dir;
	double		norm_cur_dir[3];
	double		int_coord[3];
	t_list		*obj_int;
	double		dist;
	t_camera	*camera;
	t_list		*lst;
	t_list		*light;
	int			count_light;

	count_light = 0;
	obj_int = NULL;
	light = e->light_list;
	camera = e->cam;
	lst = e->obj_list;
	ft_bzero(e->c_img, WIN_X * 4 * WIN_Y);
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0x00000000;
	counter[3] = 0;
	counter[4] = 0x00000000;
	dist = 1000000;
	while (counter[0] < WIN_Y)
	{
		while (counter[1] < WIN_X)
		{
			cur_dir[0] = -(camera->up_left_win[0] + counter[1] * camera->x_inc *
				camera->right_vec[0] - counter[0] * camera->y_inc *
					camera->up_vec[0]) + camera->coord[0];
			cur_dir[1] = -(camera->up_left_win[1] + counter[1] * camera->x_inc *
				camera->right_vec[1] - counter[0] * camera->y_inc *
					camera->up_vec[1]) + camera->coord[1];
			cur_dir[2] = -(camera->up_left_win[2] + counter[1] * camera->x_inc *
				camera->right_vec[2] - counter[0] * camera->y_inc *
					camera->up_vec[2]) + camera->coord[2];
			val_cur_dir = sqrt(cur_dir[0] * cur_dir[0] + cur_dir[1] * cur_dir[1] +
				cur_dir[2] * cur_dir[2]);
			norm_cur_dir[0] = cur_dir[0] / val_cur_dir;
			norm_cur_dir[1] = cur_dir[1] / val_cur_dir;
			norm_cur_dir[2] = cur_dir[2] / val_cur_dir;
			while (lst != NULL)
			{
				if (lst->content_size == 0)
				{		
					if (ft_calc_int_sphere(lst->content, camera, 
								norm_cur_dir, &dist) == 1)
					{
						obj_int = lst;
					}
				}
				else if (lst->content_size == 1)
				{
					if (ft_calc_int_plane(lst->content, camera, 
								norm_cur_dir, &dist) == 1)
					{
						obj_int = lst;
					}
				}
				else if (lst->content_size == 2)
				{
					if (ft_calc_int_cylinder(lst->content, camera, 
								norm_cur_dir, &dist) == 1)
					{
						obj_int = lst;
					}
				}
				else if (lst->content_size == 3)
				{
					if (ft_calc_int_cone(lst->content, camera, 
								norm_cur_dir, &dist) == 1)
					{
						obj_int = lst;
					}
				}
				lst = lst->next;
			}
			if (obj_int != NULL)
			{
				lst = e->obj_list;
				counter[2] = 0x00000000;
				counter[4] = 0x00000000;
				ft_calc_int_pos(dist, norm_cur_dir, camera->coord, &int_coord);
				while (light != NULL)
				{
					while (lst != NULL)
					{
						if (lst != obj_int)
						{
							if (ft_is_light_interrupt(light->content, lst,
								int_coord) == 1)
							{
								counter[3] = 1;
								break ;
							}
						}
						lst = lst->next;
					}
					if (counter[3] != 1)
					{
						if (count_light == 0)
						{
						counter[2] = ft_getlight(obj_int, light->content, 
								int_coord, norm_cur_dir);
						ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
										&counter[2], sizeof(int));
						}
						else
						{
						counter[2] = ft_getlight(obj_int, light->content, 
								int_coord, norm_cur_dir);
						ft_memcpy(&counter[4], e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X, sizeof(int));
						counter[4] = ft_mix_color(counter[4],
											counter[2], 0.5);
						ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
										&counter[4], sizeof(int));
						}
					}
					else
					{
						if (count_light == 0)
						{
						counter[2] = ft_getambiant_light(obj_int);
						counter[4] = ft_mix_color(counter[4],
											counter[2], 0.2);
						ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
										&counter[4], sizeof(int));
						}
						else
						{
							counter[2] = 0x00000000;
						ft_memcpy(&counter[4], e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X, sizeof(int));
						counter[4] = ft_mix_color(counter[2],
											counter[4], 0.5);
						ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
										&counter[4], sizeof(int));					
						}
					}
					lst = e->obj_list;
					light = light->next;
					count_light = 1;
				}
				counter[4] = 0x00000000;
				counter[2] = 0x00000000;
				counter[3] = 0;
				lst = e->obj_list;
			}
			obj_int = NULL;
			dist = 1000000;
			lst = e->obj_list;
			light = e->light_list;
			counter[1]++;
		}
		counter[1] = 0;
		counter[0]++;
	}
}
