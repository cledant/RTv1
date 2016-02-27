/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_int_plane_light.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:20:19 by cledant           #+#    #+#             */
/*   Updated: 2016/02/27 21:45:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_calc_int_plane_light(t_plane *plane, t_light *cam, double cur_dir[3],
			double *dist)
{
	double	dee;
	double	sup;
	double	inf;
	double	result;

	dee = (-1 * plane->factor[0] * -plane->coord[0]) + 
			(-1 * plane->factor[1] * -plane->coord[1]) + 
				(-1 * plane->factor[2] * -plane->coord[2]);
	sup = plane->factor[0] * -(cam->coord[0] - plane->coord[0]) +
			plane->factor[1] * -(cam->coord[1] - plane->coord[1]) +
				plane->factor[2] * -(cam->coord[2] - plane->coord[2]) + dee;
	inf = plane->factor[0] * cur_dir[0] + plane->factor[1] * cur_dir[1] +
			plane->factor[2] * cur_dir[2];
	result = -(sup / inf);
	if (result < *dist)
	{
		*dist = result;
		return (1);
	}
	return (0);
}
