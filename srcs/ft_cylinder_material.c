/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_material.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 09:23:55 by cledant           #+#    #+#             */
/*   Updated: 2016/02/29 19:14:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_cylinder_material(double amb, double diff, double spec,
			t_cylinder *cyl)
{
	cyl->diffuse = diff;
	cyl->ambiant = amb;
	cyl->specular = spec;
}
