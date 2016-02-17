/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:49:40 by cledant           #+#    #+#             */
/*   Updated: 2016/02/17 20:05:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_draw_image(t_mlx *e)
{
	int			counter[2];
	double		coord_int[3];
	double		cur_dir[3];
	t_camera	camera;
	t_sphere	sphere;
	char		*d_img;

	d_img = e->c_img;
	camera = e->cam;
	sphere = e->sph;
	counter[0] = 0;
	counter[1] = 1;
	while (counter[0] < WIN_Y)
	{
		while (counter[1] < WIN_X)
		{
			cur_dir[0] = camera.up_left_vec[0] + counter[1] * camera.x_inc *
				camera.right_vec[0] - counter[0] * camera.y_inc *
					camera.up_vec[0];
			cur_dir[1] = camera.up_left_vec[1] + counter[1] * camera.x_inc *
				camera.right_vec[1] - counter[0] * camera.y_inc *
					camera.up_vec[1];
			cur_dir[2] = camera.up_left_vec[2] + counter[1] * camera.x_inc *
				camera.right_vec[2] - counter[0] * camera.y_inc *
					camera.up_vec[2];
			if (ft_calc_int_sphere(e, cur_dir, &coord_int) == 1)
			{
				d_img = d_img + counter[1] * 4 + counter[0] * 4 * WIN_X;
				ft_memcpy(d_img, &sphere.color, sizeof(int));
			}
			counter[1]++;
		}
		counter[1] = 0;
		counter[0]++;
	}
}
