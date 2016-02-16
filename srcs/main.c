/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/02/16 09:32:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		main_part1(t_mlx *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
	{
		ft_putendl("Error");
		return (0);
	}
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Wolf_3D");
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

	if (main_part1(&e) == 0)
		return (0);
	e.render = 0;
	ft_init_scene(&e);
	mlx_key_hook(e.mlx, keyhook, &e);
	mlx_expose_hook(e.mlx, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
