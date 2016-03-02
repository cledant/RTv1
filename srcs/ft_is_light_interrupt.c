/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_light_interrupt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:23:36 by cledant           #+#    #+#             */
/*   Updated: 2016/03/02 12:12:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_is_light_interrupt(t_light *light, t_list *list, 
			double int_coord[3])
{
	double	vector[3];
	double	norm;
	double	norm_light[3];
	double	dist[2];

	dist[0] = 1000000;
//	printf("int coord %f\n", int_coord[0]);
//	printf("int coord %f\n", int_coord[1]);
//	printf("int coord %f\n", int_coord[2]);
//	printf("int coord %f\n", light->coord[0]);
//	printf("int coord %f\n", light->coord[1]);
//	printf("int coord %f\n", light->coord[2]);
	vector[0] = int_coord[0]  - light->coord[0];
	vector[1] = int_coord[1]  - light->coord[1];
	vector[2] = int_coord[2]  - light->coord[2];
	norm = sqrt(vector[0] * vector[0] + vector[1] * vector[1] + 
			vector[2] * vector[2]);
	norm_light[0] = -vector[0] / norm;
	norm_light[1] = -vector[1] / norm;
	norm_light[2] = -vector[2] / norm;
	if (list->content_size == 0)
	{
		ft_calc_int_sphere_light(list->content, light, norm_light, &(dist[0]));
	}
	else if (list->content_size == 1)
	{
		ft_calc_int_plane_light(list->content, light, norm_light, &(dist[0]));
	}
	else if (list->content_size == 2)
	{
		ft_calc_int_cylinder_light(list->content, light, norm_light, &(dist[0]));
	}
	else if (list->content_size == 3)
	{
		ft_calc_int_cone_light(list->content, light, norm_light, &(dist[0]));
	}
	if (dist[0] < norm)
		return (1);
	else
		return (0);

}
