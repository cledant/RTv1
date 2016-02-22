/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_int_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:13:34 by cledant           #+#    #+#             */
/*   Updated: 2016/02/22 20:23:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_calc_int_pos(double dist, double cur_vec[3], double (*int_coord)[3])
{
	(*int_coord)[0] = cur_vec[0] * dist;
	(*int_coord)[1] = cur_vec[1] * dist;
	(*int_coord)[2] = cur_vec[2] * dist;
}
