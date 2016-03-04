/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_getlight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:06:03 by cledant           #+#    #+#             */
/*   Updated: 2016/03/04 12:20:11 by cledant          ###   ########.fr       */
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
	int		obj_color[5];
	int		ambiant_color[5];
	double	factor_color[2];
	double	ratio[2];
	double	norm_vec_reflec[3];
	double	spec_angle;
	int		spec_color[5];

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
	if (angle < 0)
		angle = -angle;
	ambiant_color[0] = (obj->color & 0xFF000000);
	ambiant_color[0] = ambiant_color[0] >> (4 * 6);
	ambiant_color[0] = ambiant_color[0] * obj->ambiant * 0.333;
	ambiant_color[0] = ambiant_color[0] << (4 * 6);
	ambiant_color[1] = (obj->color & 0x00FF0000);
	ambiant_color[1] = ambiant_color[1] >> (4 * 4);
	ambiant_color[1] = ambiant_color[1] * obj->ambiant * 0.333;
	ambiant_color[1] = ambiant_color[1] << (4 * 4);
	ambiant_color[2] = (obj->color & 0x0000FF00);
	ambiant_color[2] = ambiant_color[2] >> (4 * 2);
	ambiant_color[2] = ambiant_color[2] * obj->ambiant * 0.333;
	ambiant_color[2] = ambiant_color[2] << (4 * 2);
	ambiant_color[3] = (obj->color & 0x000000FF);
	ambiant_color[3] = ambiant_color[3] * obj->ambiant * 0.333;
	//c1
	if (angle > 0)
	{
		ratio[0] = 0.5;
		ratio[1] = 1 - ratio[0];
		obj_color[0] = (obj->color & 0xFF000000);
		obj_color[0] = obj_color[0] >> (4 * 6);
		factor_color[0] = obj_color[0] / (double)255;
		ret_color[0] = (light->color & 0xFF000000);
		ret_color[0] = ret_color[0] >> (4 * 6);
		factor_color[1] = ret_color[0] / (double)255;
		ret_color[0] = (int)((factor_color[0] * ratio[0] + 
			factor_color[1] * ratio[1]) * 255);
//		ret_color[0] = factor_color[0] * factor_color[1] * 255;
		ret_color[0] = ret_color[0] * obj->diffuse * angle * 0.333;
		ret_color[0] = ret_color[0] << (4 * 6);
		//c2
		obj_color[1] = (obj->color & 0x00FF0000);
		obj_color[1] = obj_color[1] >> (4 * 4);
		factor_color[0] = obj_color[1] / (double)255;
		ret_color[1] = (light->color & 0x00FF0000);
		ret_color[1] = ret_color[1] >> (4 * 4);
		factor_color[1] = ret_color[1] / (double)255;
		ret_color[1] = (int)((factor_color[0] * ratio[0] + 
				factor_color[1] * ratio[1]) * 255);
//		ret_color[1] = factor_color[0] * factor_color[1] * 255;
		ret_color[1] = ret_color[1] * obj->diffuse * angle * 0.333;
		ret_color[1] = ret_color[1] << (4 * 4);
		//c3
		obj_color[2] = (obj->color & 0x0000FF00);
		obj_color[2] = obj_color[2] >> (4 * 2);
		factor_color[0] = obj_color[2] / (double)255;
		ret_color[2] = (light->color & 0x0000FF00);
		ret_color[2] = ret_color[2] >> (4 * 2);
		factor_color[1] = ret_color[2] / (double)255;
		ret_color[2] = (int)((factor_color[0] * ratio[0] + 
				factor_color[1] * ratio[1]) * 255);
//			ret_color[2] = factor_color[0] * factor_color[1] * 255;
		ret_color[2] = ret_color[2] * obj->diffuse * angle * 0.333;
		ret_color[2] = ret_color[2] << (4 * 2);
		//c4
		obj_color[3] = (obj->color & 0x000000FF);
		factor_color[0] = obj_color[3] / (double)255;
		ret_color[3] = (light->color & 0x000000FF);
		factor_color[1] = ret_color[3] / (double)255;
		ret_color[3] = (int)((factor_color[0] * ratio[0] + 
				factor_color[1] * ratio[1]) * 255);
	//		ret_color[3] = factor_color[0] * factor_color[1] * 255;
		ret_color[3] = ret_color[3] * obj->diffuse * angle * 0.333;
	//		printf("COLOR = %x\n", ret_color[4]);
	//specuclar
	norm_vec_reflec[0] = 2 * angle * norm_vec_normal[0] - -norm_vec_light[0];
	norm_vec_reflec[1] = 2 * angle * norm_vec_normal[1] - -norm_vec_light[1];
	norm_vec_reflec[2] = 2 * angle * norm_vec_normal[2] - -norm_vec_light[2];
	spec_angle = norm_vec_reflec[0] * cam_vector[0] +  norm_vec_reflec[1] *
		cam_vector[1] + norm_vec_reflec[2] * cam_vector[2];
	spec_color[0] = (obj->color & 0xFF000000);
	spec_color[0] = spec_color[0] >> (4 * 6);
	spec_color[0] = spec_color[0] * obj->specular * pow(spec_angle, obj->shiny)
		* 0.333;
	if (spec_color[0] > 0xFF)
		spec_color[0] = 0xFF * 0.333;
	spec_color[0] = spec_color[0] << (4 * 6);
	spec_color[1] = (obj->color & 0x00FF0000);
	spec_color[1] = spec_color[1] >> (4 * 4);
	spec_color[1] = spec_color[1] * obj->specular * pow(spec_angle, obj->shiny)
		* 0.333;
	if (spec_color[1] > 0xFF)
		spec_color[1] = 0xFF * 0.333;
	spec_color[1] = spec_color[1] << (4 * 4);
	spec_color[2] = (obj->color & 0x0000FF00);
	spec_color[2] = spec_color[2] >> (4 * 2);
	spec_color[2] = spec_color[2] * obj->specular * pow(spec_angle, obj->shiny)
		* 0.333;
	if (spec_color[2] > 0xFF)
		spec_color[2] = 0xFF * 0.333;
	spec_color[2] = spec_color[2] << (4 * 2);
	spec_color[3] = (obj->color & 0x000000FF);
	spec_color[3] = spec_color[3] * obj->specular * pow(spec_angle, obj->shiny)
		* 0.333;
	if (spec_color[3] > 0xFF)
		spec_color[3] = 0xFF * 0.333;
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
	ret_color[4] = ambiant_color[0] + ret_color[0] + ambiant_color[1] + ret_color[1]
		+ ambiant_color[2] + ret_color[2] + ambiant_color[3] + ret_color[3] +
		spec_color[0] + spec_color[1] + spec_color[2] + spec_color[3];
	return (ret_color[4]);
}
