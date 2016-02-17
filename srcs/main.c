/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/02/17 19:47:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

static int		main_part1(t_mlx *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "RT_v1");
	if (e->win == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	if (e->img == NULL)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_putendl("Error");
		return (0);
	}
	return (1);
}

int				main(void)
{
	t_mlx		e;
	int			var[3];

	if (main_part1(&e) == 0)
		return (0);
	e.render = 0;
	e.dist_to_proj_plane = (WIN_X / 2) / (tan((M_PI * (FOV / 
						(double)2) / (double)180)));
	e.c_img = mlx_get_data_addr(e.img, &(var[0]), &(var[1]), &(var[2]));
	ft_init_scene(&e);
	mlx_key_hook(e.mlx, key_hook, &e);
	mlx_expose_hook(e.mlx, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
