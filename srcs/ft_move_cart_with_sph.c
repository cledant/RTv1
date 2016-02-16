/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cart_with_sph.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:48:53 by cledant           #+#    #+#             */
/*   Updated: 2016/02/16 19:59:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_move_cart_with_sph(double (*cart)[3], double radius,
			double angle[2])
{
	double	sin_phi;

	sin_phi = sin(angle[1]);
	(*cart)[0] = (*cart)[0] + radius * sin_phi * cos(angle[0]);
	(*cart)[1] = (*cart)[1] + radius * sin_phi * sin(angle[0]);
	(*cart)[2] = (*cart)[2] + radius * cos(angle[1]);
}
