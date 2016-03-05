/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_norm_vec_cylinder.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 19:26:46 by cledant           #+#    #+#             */
/*   Updated: 2016/03/05 20:03:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_calc_norm_vec_cylinder(t_cylinder *obj, double (*norm_vec)[2][3],
			double int_coord[3], double light_coord[3])
{
	double	vector[3];
	double	norm;
	double	tmp_norm;

	vector[0] = int_coord[0] - light_coord[0];
	vector[1] = int_coord[1] - light_coord[1];
	vector[2] = int_coord[2] - light_coord[2];
	norm = sqrt(vector[0] * vector[0] + vector[1] * vector[1] +
			vector[2] * vector[2]);
	(*norm_vec)[0][0] = vector[0] / norm;
	(*norm_vec)[0][1] = vector[1] / norm;
	(*norm_vec)[0][2] = vector[2] / norm;
	tmp_norm = (((*norm_vec)[0][0] * obj->dir[0] * norm + (*norm_vec)[0][1] *
			obj->dir[1] * norm + (*norm_vec)[0][2] * obj->dir[2] * norm)) +
			(((light_coord[0] - obj->coord[0]) * obj->dir[0]) +
			((light_coord[1] - obj->coord[1]) * obj->dir[1]) +
			((light_coord[2] - obj->coord[2]) * obj->dir[2]));
	(*norm_vec)[1][0] = int_coord[0] - obj->coord[0] - (obj->dir[0] * tmp_norm);
	(*norm_vec)[1][1] = int_coord[1] - obj->coord[1] - (obj->dir[1] * tmp_norm);
	(*norm_vec)[1][2] = int_coord[2] - obj->coord[2] - (obj->dir[2] * tmp_norm);
	ft_normalize_vec(norm_vec[1]);
}
