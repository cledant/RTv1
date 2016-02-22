/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_has_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:31:01 by cledant           #+#    #+#             */
/*   Updated: 2016/02/22 20:00:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_plane_has_int(t_plane *plane, t_light *light, double cur_dir[3])
{
	double	norm;
	double	norm_vec[3];
	double	angle;

	norm = sqrt(plane->coord[0] * plane->coord[0] + plane->coord[1] *
			plane->coord[1] + plane->coord[2] * plane->coord[2]);
	norm_vec[0] = plane->coord[0] / norm;
	norm_vec[1] = plane->coord[1] / norm;
	norm_vec[2] = plane->coord[2] / norm;
	angle = norm_vec[0] * cur_dir[0] + norm_vec[1] * cur_dir[1] +
				norm_vec[1] * cur_dir[1];
	if(angle == 1 || angle == -1)
		return (1);
	else
		return (0);
}
