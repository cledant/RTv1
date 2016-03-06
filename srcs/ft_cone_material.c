/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 10:06:34 by cledant           #+#    #+#             */
/*   Updated: 2016/03/06 10:06:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_cone_material(double amb, double diff, double spec,
			t_cone *cone)
{
	cone->diffuse = diff;
	cone->ambiant = amb;
	cone->specular = spec;
}
