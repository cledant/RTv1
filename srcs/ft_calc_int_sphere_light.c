/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_int_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:02:06 by cledant           #+#    #+#             */
/*   Updated: 2016/02/26 15:23:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_calc_int_sphere_light(t_sphere *sphere, t_light *camera,
								double cur_dir[3], double *dist)
{
	double		var[3];
	double		det;
	double		length[2];

//	printf("CUR_DIR[0] = %f\n", cur_dir[0]);
//	printf("CUR_DIR[1] = %f\n", cur_dir[1]);
//	printf("CUR_DIR[2] = %f\n", cur_dir[2]);
//	printf("light pos %f\n", camera->coord[0]);
	var[0] = (cur_dir[0] * cur_dir[0]) + (cur_dir[1] * cur_dir[1]) +
				(cur_dir[2] * cur_dir[2]);
	var[1] = 2 *(cur_dir[0] * -(camera->coord[0] - sphere->coord[0]) +
					cur_dir[1] * -(camera->coord[1] - sphere->coord[1]) +
						cur_dir[2] * -(camera->coord[2] - sphere->coord[2]));
	var[2] = ((camera->coord[0] - sphere->coord[0]) * (camera->coord[0] -
				sphere->coord[0]) + (camera->coord[1] - sphere->coord[1]) *
					(camera->coord[1] - sphere->coord[1]) + (camera->coord[2] -
							sphere->coord[2]) * (camera->coord[2] -
								sphere->coord[2]) - (sphere->radius *
									sphere->radius));
	det = var[1] * var[1] - (4 * var[0] * var[2]);
//	printf("DET = : %f\n", det);
	if (det < 0)
		return (0);
	else if (det == 0)
	{
		length[0] = (-var[1] / (2 * var[0]));
		if (length[0] < *dist)
		{
			*dist = length[0];
			return (1);
		}
		return (0);
	}
	else
	{
		length[0] = (-var[1] + sqrt(det)) / (2 * var[0]);
		length[1] = (-var[1] - sqrt(det)) / (2 * var[0]);
		if (length[1] < length[0])
		{
			if (length[1] < *dist)
			{
				*dist = length[1];
				return(1);
			}
		}
		else
		{
			if (length[0] < *dist)
			{
				*dist = length[0];
				return(1);
			}
		}
		return (0);
	}
}
