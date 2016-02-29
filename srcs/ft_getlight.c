/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:01:41 by cledant           #+#    #+#             */
/*   Updated: 2016/02/29 18:29:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_getlight(t_list *obj, t_light *light, double int_coord[3],
			double norm_cur_dir[3])
{
	int		color;

	if (obj->content_size == 0)
	{
		color = ft_sphere_getlight(obj->content, light, int_coord,
				norm_cur_dir);
	}
	else if (obj->content_size == 1)
	{
		color = ft_plane_getlight(obj->content, light, int_coord,
				norm_cur_dir);
	}
	else if (obj->content_size == 2)
	{
		color = ft_cylinder_getlight(obj->content, light, int_coord,
				norm_cur_dir);
	}
	return (color);
}
