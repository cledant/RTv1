/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:01:41 by cledant           #+#    #+#             */
/*   Updated: 2016/02/28 19:10:26 by cledant          ###   ########.fr       */
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
	return (color);
}
