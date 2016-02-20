/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 10:15:01 by cledant           #+#    #+#             */
/*   Updated: 2016/02/20 11:14:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_sphere	*ft_sphere_new(int coloration, double origin[3], double size)
{
	t_sphere	*sphere;

	if ((sphere = (t_sphere *)malloc(1 * sizeof(t_sphere))) == NULL)
		return (NULL);
	sphere->radius = size;
	sphere->color = coloration;
	sphere->coord[0] = origin[0];
	sphere->coord[1] = origin[1];
	sphere->coord[2] = origin[2];
	return (sphere);
}
