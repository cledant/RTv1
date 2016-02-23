/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:28:05 by cledant           #+#    #+#             */
/*   Updated: 2016/02/23 09:40:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_light		*ft_light_new(double loc[3], int coloration)
{
	t_light		*new;

	if ((new = (t_light *)malloc(1 * sizeof(t_light))) == NULL)
		return (NULL);
	new->coord[0] = loc[0];
	new->coord[0] = loc[0];
	new->coord[0] = loc[0];
	new->color = coloration;
	return (new);
}
