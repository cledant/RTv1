/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_getlight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:06:03 by cledant           #+#    #+#             */
/*   Updated: 2016/03/04 13:53:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_plane_getlight(t_plane *obj, t_light *light, double int_coord[3],
			double cam_vector[3])
{
	double	vector[3];
	double	norm;
	double	norm_vec_light[3];
	double	norm_vec_normal[3];
	double	angle;
	int		ret_color[5];
	int		diff_color[4];
	int		ambiant_color[4];
	int		spec_color[4];
	double	norm_vec_reflec[3];
	double	spec_angle;

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
	norm = sqrt(obj->factor[0] * obj->factor[0] + obj->factor[1] * obj->factor[1] +
		obj->factor[2] * obj->factor[2]);
	norm_vec_normal[0] = obj->factor[0] / norm;
	norm_vec_normal[1] = obj->factor[1] / norm;
	norm_vec_normal[2] = obj->factor[2] / norm;
//	printf("norm plam = %f\n", norm_vec_normal[0]);
//	printf("norm plan = %f\n", norm_vec_normal[1]);
//	printf("norm plan = %f\n", norm_vec_normal[2]);
	angle = -norm_vec_normal[0] * norm_vec_light[0] + 
				-norm_vec_normal[1] * norm_vec_light[1] +
					-norm_vec_normal[2] * norm_vec_light[2];
//	printf("cos angle = %f\n", angle);
	ambiant_color[0] = (obj->color & 0xFF000000);
	ambiant_color[0] = ambiant_color[0] >> (4 * 6);
	ambiant_color[0] = ambiant_color[0] * obj->ambiant;
	ambiant_color[1] = (obj->color & 0x00FF0000);
	ambiant_color[1] = ambiant_color[1] >> (4 * 4);
	ambiant_color[1] = ambiant_color[1] * obj->ambiant;
	ambiant_color[2] = (obj->color & 0x0000FF00);
	ambiant_color[2] = ambiant_color[2] >> (4 * 2);
	ambiant_color[2] = ambiant_color[2] * obj->ambiant;
	ambiant_color[3] = (obj->color & 0x000000FF);
	ambiant_color[3] = ambiant_color[3] * obj->ambiant;
	if (angle < 0)
		angle = -angle;
	if (angle > 0)
	{
//diffuse
		diff_color[0] = (obj->color & 0xFF000000);
		diff_color[0] = diff_color[0] >> (4 * 6);
		diff_color[0] = diff_color[0] * obj->diffuse * angle;
		diff_color[1] = (obj->color & 0x00FF0000);
		diff_color[1] = diff_color[1] >> (4 * 4);
		diff_color[1] = diff_color[1] * obj->diffuse * angle;
		diff_color[2] = (obj->color & 0x0000FF00);
		diff_color[2] = diff_color[2] >> (4 * 2);
		diff_color[2] = diff_color[2] * obj->diffuse * angle;
		diff_color[3] = (obj->color & 0x000000FF);
		diff_color[3] = diff_color[3] * obj->diffuse * angle;
//specuclar
	norm_vec_reflec[0] = 2 * angle * norm_vec_normal[0] - -norm_vec_light[0];
	norm_vec_reflec[1] = 2 * angle * norm_vec_normal[1] - -norm_vec_light[1];
	norm_vec_reflec[2] = 2 * angle * norm_vec_normal[2] - -norm_vec_light[2];
	spec_angle = norm_vec_reflec[0] * cam_vector[0] +  norm_vec_reflec[1] *
		cam_vector[1] + norm_vec_reflec[2] * cam_vector[2];
	spec_color[0] = (obj->color & 0xFF000000);
	spec_color[0] = spec_color[0] >> (4 * 6);
	spec_color[0] = spec_color[0] * obj->specular * pow(spec_angle, obj->shiny);
	spec_color[1] = (obj->color & 0x00FF0000);
	spec_color[1] = spec_color[1] >> (4 * 4);
	spec_color[1] = spec_color[1] * obj->specular * pow(spec_angle, obj->shiny);
	spec_color[2] = (obj->color & 0x0000FF00);
	spec_color[2] = spec_color[2] >> (4 * 2);
	spec_color[2] = spec_color[2] * obj->specular * pow(spec_angle, obj->shiny);
	spec_color[3] = (obj->color & 0x000000FF);
	spec_color[3] = spec_color[3] * obj->specular * pow(spec_angle, obj->shiny);
	}
	else
	{
		ret_color[0] = 0;
		ret_color[1] = 0;
		ret_color[2] = 0;
		ret_color[3] = 0;
		spec_color[0] = 0;
		spec_color[1] = 0;
		spec_color[2] = 0;
		spec_color[3] = 0;
	}
	ret_color[0] = ambiant_color[0] + diff_color[0] + spec_color[0];
	if (ret_color[0] > 0xFF)
		ret_color[0] = 0xFF;
	ret_color[1] = ambiant_color[1] + diff_color[1] + spec_color[1];
	if (ret_color[1] > 0xFF)
		ret_color[1] = 0xFF;
	ret_color[2] = ambiant_color[2] + diff_color[2] + spec_color[2];
	if (ret_color[2] > 0xFF)
		ret_color[2] = 0xFF;
	ret_color[3] = ambiant_color[3] + diff_color[3] + spec_color[3];
	if (ret_color[3] > 0xFF)
		ret_color[3] = 0xFF;
	ret_color[0] = ret_color[0] << (4 * 6);
	ret_color[1] = ret_color[1] << (4 * 4);
	ret_color[2] = ret_color[2] << (4 * 2);
	ret_color[4] = ret_color[0] + ret_color[1] + ret_color[2] + ret_color[3];
	return (ret_color[4]);
}
