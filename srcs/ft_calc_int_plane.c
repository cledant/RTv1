/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_int_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 13:54:53 by cledant           #+#    #+#             */
/*   Updated: 2016/02/27 18:59:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_calc_int_plane(t_plane *plane, t_camera *cam, double cur_dir[3],
			double *dist)
{
//	double	dee;
	double	sup;
	double	inf;
	double	result;
	double	norm;

	norm = sqrt(plane->factor[0] * plane->factor[0] +
			plane->factor[1] * plane->factor[1] +
				plane->factor[2] * plane->factor[2]);
//	dee = (-1 * plane->factor[0] * -plane->coord[0]) + 
//			(-1 * plane->factor[1] * -plane->coord[1]) + 
//				(-1 * plane->factor[2] * -plane->coord[2]);
	plane->factor[0] = plane->factor[0] / norm;
	plane->factor[1] = plane->factor[1] / norm;
	plane->factor[2] = plane->factor[2] / norm;
	sup = plane->factor[0] * -(cam->coord[0] - plane->coord[0]) +
			plane->factor[1] * -(cam->coord[1] - plane->coord[1]) +
				plane->factor[2] * -(cam->coord[2] - plane->coord[2]);
	inf = plane->factor[0] * cur_dir[0] + plane->factor[1] * cur_dir[1] +
			plane->factor[2] * cur_dir[2];
	if	(inf == 0)
		return (0);
	result = -(sup / inf);
	if (result < 0)
		return (0);
//	printf("DIST PLANE = %f\n", result);
	else if (result < *dist)
	{
		*dist = result;
		return (1);
	}
	return (0);
}
