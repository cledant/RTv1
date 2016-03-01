/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_int_coneinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 09:33:09 by cledant           #+#    #+#             */
/*   Updated: 2016/03/01 21:24:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_calc_int_cone_light(t_cone *cone, t_light *light,
			double cur_dir[3], double *dist)
{
	double		var[3];
	double		det;
	double		length[2];

//	printf("CUR_DIR[0] = %f\n", cur_dir[0]);
//	printf("CUR_DIR[1] = %f\n", cur_dir[1]);
//	printf("CUR_DIR[2] = %f\n", cur_dir[2]);
//	printf("light pos %f\n", light->coord[0]);
//	printf("light pos %f\n", light->coord[1]);
//	printf("light pos %f\n", light->coord[2]);
//	printf("cone[0] = %f\n", cone->coord[0]);
//	printf("cone[1] = %f\n", cone->coord[1]);
//	printf("cone[2] = %f\n", cone->coord[2]);
	var[0] = ((cur_dir[0] * cur_dir[0]) + (cur_dir[1] * cur_dir[1]) +
		(cur_dir[2] * cur_dir[2])) - ((((cur_dir[0] * cone->dir[0]) + 
		(cur_dir[1] * cone->dir[1]) + (cur_dir[2] * cone->dir[2])) *
		 ((cur_dir[0] * cone->dir[0]) + (cur_dir[1] * cone->dir[1]) + 
		  (cur_dir[2] * cone->dir[2]))) * (1 + cone->k * cone->k));
	var[1] = 2 * ((cur_dir[0] * -(light->coord[0] - cone->coord[0]) +
		cur_dir[1] * -(light->coord[1] - cone->coord[1]) +cur_dir[2] *
		-(light->coord[2] - cone->coord[2])) - ((((cur_dir[0] * cone->dir[0]) + 
		(cur_dir[1] * cone->dir[1]) + (cur_dir[2] * cone->dir[2])) * 
		((cone->dir[0] * -(light->coord[0] - cone->coord[0]) +
		cone->dir[1] * -(light->coord[1] - cone->coord[1]) + cone->dir[2] *
		-(light->coord[2] - cone->coord[2])))) * (1 + cone->k * cone->k)));
	var[2] = ((light->coord[0] - cone->coord[0]) * (light->coord[0] -
		cone->coord[0]) + (light->coord[1] - cone->coord[1]) *
		(light->coord[1] - cone->coord[1]) + (light->coord[2] -
		cone->coord[2]) * (light->coord[2] - cone->coord[2])) - (cone->radius *
		cone->radius) - (((cone->dir[0] * -(light->coord[0] - cone->coord[0]) +
		cone->dir[1] * -(light->coord[1] - cone->coord[1]) + cone->dir[2] *
		-(light->coord[2] - cone->coord[2])) * (cone->dir[0] * 
		-(light->coord[0] - cone->coord[0]) + cone->dir[1] *
		-(light->coord[1] - cone->coord[1]) + cone->dir[2] *
		-(light->coord[2] - cone->coord[2]))) * (1 + cone->k * cone->k));
	det = var[1] * var[1] - (4 * var[0] * var[2]);
//	printf("DET = : %f\n", det);
	if (det < 0)
		return (0);
	else if (det == 0)
	{
		if (var[0] == 0)
			return (0);
		length[0] = (-var[1] / (2 * var[0]));
		if (length[0] < *dist)
		{
			if (length[0] < 0)
				return (0);
			*dist = length[0];
			return (1);
		}
		return (0);
	}
	else
	{
		if (var[0] == 0)
			return (0);
		length[0] = (-var[1] + sqrt(det)) / (2 * var[0]);
		length[1] = (-var[1] - sqrt(det)) / (2 * var[0]);
//		printf("length 0 = %f\n", length[0]);
//		printf("length 1 = %f\n", length[1]);
		if (length[1] < length[0])
		{
			if (length[1] < *dist)
			{
				if (length[1] < 0)
					return (0);
				else
				{
					*dist = length[1];
					return(1);
				}
			}
		}
		else
		{
			if (length[0] < *dist)
			{
				if (length[0] < 0)
					return (0);
				else
				{
					*dist = length[0];
					return(1);
				}
			}
		}
		return (0);
	}
}
