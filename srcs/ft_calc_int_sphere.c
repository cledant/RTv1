/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_int_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:02:06 by cledant           #+#    #+#             */
/*   Updated: 2016/02/17 19:50:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_calc_int_sphere(t_mlx *e, double cur_dir[3], double (*coord)[3])
{
	t_camera	*camera;
	t_sphere	*sphere;
	double		var[3];
	double		det;
	double		lenght[2];

	*camera = e->cam;
	*sphere = e->sph;
	var[0] = (cur_dur[0] * cur_dur[0]) + (cur_dur[1] * cur_dur[1]) +
				(cur_dur[2] * cur_dur[2]);
	var[1] = 2 *(cur_dur[0] * (camera->coord[0] - sphere->coord[0]) +
					cur_dur[1] * (camera->coord[1] - sphere->coord[1]) +
						cur_dur[2] * (camera->coord[2] - sphere->coord[2]));
	var[2] = (camera->coord[0] - sphere->coord[0]) * (camera->coord[0] -
				sphere->coord[0]) + (camera->coord[1] - sphere->coord[1]) *
					(camera->coord[1] - sphere->coord[1]) + (camera->coord[2] -
							sphere->coord[2]) * (camera->coord[2] - sphere->coord[2]);
	det = var[1] * var[1] - (4 * var[0] * var[2]);
	if (det < 0)
	{
		(*coord)[0] = camera->coord[0];
		(*coord)[1] = camera->coord[1];
		(*coord)[2] = camera->coord[2];
		return (0);
	}
	if (det == 0)
	{
		length[0] = (-var[1] / (2 * var[0]));
		(*coord)[0] = camera->coord[0] + norm_dir_vec[0] * length[0];
		(*coord)[1] = camera->coord[1] + norm_dir_vec[1] * length[0];
		(*coord)[2] = camera->coord[2] + norm_dir_vec[2] * length[0];
		return (1);
	}
	else
	{
		length[0] = (-var[1] + sqrt(det)) / (2 * var[0]);
		length[1] = (-var[1] - sqrt(det)) / (2 * var[0]);
		if (length[1] < length[0])
		{
			(*coord)[0] = camera->coord[0] + norm_dir_vec[0] * length[1];
			(*coord)[1] = camera->coord[1] + norm_dir_vec[1] * length[1];
			(*coord)[2] = camera->coord[2] + norm_dir_vec[2] * length[1];	
		}
		else
		{
			(*coord)[0] = camera->coord[0] + norm_dir_vec[0] * length[0];
			(*coord)[1] = camera->coord[1] + norm_dir_vec[1] * length[0];
			(*coord)[2] = camera->coord[2] + norm_dir_vec[2] * length[0];
		}
		return(1);
	}
}
