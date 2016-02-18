/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_int_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:02:06 by cledant           #+#    #+#             */
/*   Updated: 2016/02/18 12:53:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_calc_int_sphere(t_mlx *e, double cur_dir[3], double (*coord)[3])
{
	t_camera	*camera;
	t_sphere	*sphere;
	double		var[3];
	double		det;
	double		length[2];

	camera = e->cam;
	sphere = e->sph;
//	printf("CUR_DIR[0] = %f\n", cur_dir[0]);
//	printf("CUR_DIR[1] = %f\n", cur_dir[1]);
//	printf("CUR_DIR[2] = %f\n", cur_dir[2]);
	var[0] = (cur_dir[0] * cur_dir[0]) + (cur_dir[1] * cur_dir[1]) +
				(cur_dir[2] * cur_dir[2]);
	var[1] = 2 *(cur_dir[0] * (camera->coord[0] - sphere->coord[0]) +
					cur_dir[1] * (camera->coord[1] - sphere->coord[1]) +
						cur_dir[2] * (camera->coord[2] - sphere->coord[2]));
	var[2] = ((camera->coord[0] - sphere->coord[0]) * (camera->coord[0] -
				sphere->coord[0]) + (camera->coord[1] - sphere->coord[1]) *
					(camera->coord[1] - sphere->coord[1]) + (camera->coord[2] -
							sphere->coord[2]) * (camera->coord[2] -
								sphere->coord[2]) - (sphere->radius *
									sphere->radius));
	det = var[1] * var[1] - (4 * var[0] * var[2]);
//	printf("DET = : %f\n", det);
	if (det < 0)
	{
		(*coord)[0] = camera->coord[0];
		(*coord)[1] = camera->coord[1];
		(*coord)[2] = camera->coord[2];
		return (0);
	}
	else if (det == 0)
	{
		length[0] = (-var[1] / (2 * var[0]));
		(*coord)[0] = camera->coord[0] + cur_dir[0] * length[0];
		(*coord)[1] = camera->coord[1] + cur_dir[1] * length[0];
		(*coord)[2] = camera->coord[2] + cur_dir[2] * length[0];
		return (1);
	}
	else
	{
		length[0] = (-var[1] + sqrt(det)) / (2 * var[0]);
		length[1] = (-var[1] - sqrt(det)) / (2 * var[0]);
		if (length[1] < length[0])
		{
			(*coord)[0] = camera->coord[0] + cur_dir[0] * length[1];
			(*coord)[1] = camera->coord[1] + cur_dir[1] * length[1];
			(*coord)[2] = camera->coord[2] + cur_dir[2] * length[1];	
		}
		else
		{
			(*coord)[0] = camera->coord[0] + cur_dir[0] * length[0];
			(*coord)[1] = camera->coord[1] + cur_dir[1] * length[0];
			(*coord)[2] = camera->coord[2] + cur_dir[2] * length[0];
		}
//		printf("intersection = %f\n", (*coord)[0]);
//		printf("intersection = %f\n", (*coord)[1]);
//		printf("intersection = %f\n", (*coord)[2]);
		return(1);
	}
}
