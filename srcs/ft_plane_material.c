/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_material.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:22:34 by cledant           #+#    #+#             */
/*   Updated: 2016/02/23 09:39:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_plane_materiel(double amb, double diff, double spec, t_plane *plane)
{
	plane->diffuse = diff;
	plane->ambiant = amb;
	plane->specular = spec;
}
