/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_material.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:13:24 by cledant           #+#    #+#             */
/*   Updated: 2016/02/23 13:23:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_sphere_material(double amb, double diff, double spec, t_sphere *sph)
{
	sph->diffuse = diff;
	sph->ambiant = amb;
	sph->specular = spec;
}
