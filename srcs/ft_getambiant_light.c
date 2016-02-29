/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getambiant_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:30:48 by cledant           #+#    #+#             */
/*   Updated: 2016/02/29 18:30:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		ft_getambiant_light(t_list *obj)
{
	int		color;

	if (obj->content_size == 0)
	{
		color = ft_sphere_ambiant(obj->content);
	}
	else if (obj->content_size == 1)
	{
		color = ft_plane_ambiant(obj->content);
	}
	else if (obj->content_size == 2)
	{
		color = ft_cylinder_ambiant(obj->content);
	}
	return (color);
}
