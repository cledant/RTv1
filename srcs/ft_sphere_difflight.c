/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_difflight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:46:38 by cledant           #+#    #+#             */
/*   Updated: 2016/02/24 18:21:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_sphere_difflight(t_sphere *obj, t_light *light, double int_coord[3])
{
	double	vector[3];
	double	norm;
	double	norm_vec_light[3];
	double	norm_vec_normal[3];
	double	angle;
	int		ret_color[5];

	vector[0] = int_coord[0] - light->coord[0];
	vector[1] = int_coord[1] - light->coord[1];
	vector[2] = int_coord[2] - light->coord[2];
//	printf("light coord = %f\n", light->coord[0]);
//	printf("light coord = %f\n", light->coord[1]);
//	printf("light coord = %f\n", light->coord[2]);
//	printf("int coord = %f\n", int_coord[0]);
//	printf("int coord = %f\n", int_coord[1]);
//	printf("int coord = %f\n", int_coord[2]);
	norm = sqrt(vector[0] * vector[0] + vector[1] * vector[1] + 
			vector[2] * vector[2]);
	norm_vec_light[0] = vector[0] / norm;
	norm_vec_light[1] = vector[1] / norm;
	norm_vec_light[2] = vector[2] / norm;
	vector[0] = int_coord[0] - obj->coord[0];
	vector[1] = int_coord[1] - obj->coord[1];
	vector[2] = int_coord[2] - obj->coord[2];
	norm = sqrt(vector[0] * vector[0] + vector[1] * vector[1] + 
			vector[2] * vector[2]);
	norm_vec_normal[0] = vector[0] / norm;
	norm_vec_normal[1] = vector[1] / norm;
	norm_vec_normal[2] = vector[2] / norm;
	angle = -norm_vec_normal[0] * norm_vec_light[0] + 
				-norm_vec_normal[1] * norm_vec_light[1] +
					-norm_vec_normal[2] * norm_vec_light[2];
//	printf("cos angle = %f\n", angle);
	if (angle < 0)
		return (0x00000000);
	else
	{
		ret_color[0] = (light->color & 0xFF000000);
		ret_color[0] = ret_color[0] >> (4 * 6);
		ret_color[0] = ret_color[0] * obj->diffuse * angle;
		ret_color[0] = ret_color[0] << (4 * 6);
		ret_color[1] = (light->color & 0x00FF0000);
		ret_color[1] = ret_color[1] >> (4 * 4);
		ret_color[1] = ret_color[1] * obj->diffuse * angle;
		ret_color[1] = ret_color[1] << (4 * 4);
		ret_color[2] = (light->color & 0x0000FF00);
		ret_color[2] = ret_color[2] >> (4 * 2);
		ret_color[2] = ret_color[2] * obj->diffuse * angle;
		ret_color[2] = ret_color[2] << (4 * 2);
		ret_color[3] = (light->color & 0x000000FF) * obj->diffuse * angle;
		ret_color[4] = ret_color[0] + ret_color[1] + ret_color[2] + ret_color[3];
//		printf("COLOR = %x\n", ret_color[4]);
		return (ret_color[4]);
	}
}
