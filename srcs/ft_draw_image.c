/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:49:40 by cledant           #+#    #+#             */
/*   Updated: 2016/02/26 19:26:41 by cledant          ###   ########.fr       */
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
	int			*ptr_color;

	obj_int = NULL;
	light = e->light_list;
	camera = e->cam;
	lst = e->obj_list;
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0x00000000;
	counter[3] = 0;
	counter[4] = 0x00000000;
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
				lst = lst->next;
			}
			if (obj_int != NULL)
			{
//				printf("LIGNE = %d\n", counter[0]);
//				printf("COLONNE = %d\n", counter[1]);
				lst = e->obj_list;
				counter[2] = 0x00000000;
				ft_calc_int_pos(dist, norm_cur_dir, camera->coord, &int_coord);
				while (light != NULL)
				{
					while (lst != NULL)
					{
//						if (lst != obj_int)
						{
							if (lst->content_size == 0)
							{
								if (ft_sphere_is_light_interrupt(light->content, 
										lst->content, int_coord) == 0)
								{
//									ptr_color = (int *)(e->c_img + counter[1] * 4
//											+ counter[0] * 4 * WIN_X);
									counter[2] = 
						ft_getlight(obj_int, light->content, 
							int_coord, norm_cur_dir);
//									counter[4] = ft_mix_color(*ptr_color, counter[2],
//											0.1);
					ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
									&counter[2], sizeof(int));
								break ;
								}
								else
								{
									ptr_color = (int *)(e->c_img + counter[1] * 4
											+ counter[0] * 4 * WIN_X); 
									counter[2] = ft_sphere_ambiant(lst->content);
									counter[4] = ft_mix_color(counter[2], 0x00000000,
											0.8);
					ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
									&counter[4], sizeof(int));
//									counter[4] = ft_mix_color(0x00000000, 
//											ft_sphere_ambiant(lst->content), 0.8);
//									counter[3] = 1;
								}
							}
							else if (lst->content_size == 1)
							{
								if (ft_plane_has_int(lst->content,
											light->content, int_coord) == 1)
								{
//									counter[2] =
//					ft_getlight(obj_int, light->content, int_coord,
//							norm_cur_dir);
									ptr_color = (int *)(e->c_img + counter[1] * 4
											+ counter[0] * 4 * WIN_X);
									counter[2] = 
						ft_getlight(obj_int, light->content, 
							int_coord, norm_cur_dir);
//									counter[4] = ft_mix_color(*ptr_color, counter[2],
//											0.1);
					ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
									&counter[2], sizeof(int));
					break ;
								}
								else
								{
//									counter[4] = ft_plane_ambiant(lst->content);
//									counter[4] = ft_mix_color(0x00000000, 
//											ft_plane_ambiant(lst->content), 0.8);
//									counter[3] = 1;
//									ptr_color = (int *)(e->c_img + counter[1] * 4
//											+ counter[0] * 4 * WIN_X);
									counter[2] = ft_sphere_ambiant(lst->content);
									counter[4] = ft_mix_color(counter[2], 0x00000000,
											0.8);
					ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
									&counter[4], sizeof(int));
								}
							}	
						}
						lst = lst->next;
					}
					lst = e->obj_list;
					light = light->next;
				}
//				if (counter[2] != 0x00000000 && counter[3] == 0)
//				{
//					ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
//									&counter[2], sizeof(int));
//				}
//				else if (counter[3] == 1)
//				{
//					ft_memcpy(e->c_img + counter[1] * 4 + counter[0] * 4 * WIN_X,
//									&counter[4], sizeof(int));
//				}
				counter[4] = 0x00000000;
				counter[2] = 0x00000000;
				counter[3] = 0;
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
