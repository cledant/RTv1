/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:27:39 by cledant           #+#    #+#             */
/*   Updated: 2016/02/16 09:32:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_error_routine(int type)
{
	if (type == 1)
		ft_putendl("Error getting time");
	else
		ft_putendl("Error : not enough memory");
	key_hook(MLX_KEY_ESC, e);
}

int				expose_hook(t_mlx *e)
{
	struct timeval	s_ms[2];
	long int		ms[2];
	double			fps;
	char			*s_fps;
	char			*disp_fps;

	if (e->render == 0)
	{
		if (gettimeofday(&(s_ms[0]), NULL) == -1)
			ft_error_routine(1);
		ft_draw_image(e);
		if (gettimeofday(&(s_ms[1]), NULL) == -1)
			ft_error_routine(1);
		ms[0] = s_ms[0].tv_sec * 1000 + s_ms[0].tv_usec / 1000;
		ms[1] = s_ms[1].tv_sec * 1000 + s_ms[1].tv_usec / 1000;
		fps = ms[1] - ms[0];
		if ((s_fps = ft_itoa((int)fps)) == NULL)
			ft_error_routine(0);
		if ((disp_fps = ft_strjoin("RENDER TIME IN MS : ", s_fps)) == NULL)
		{
			ft_strdel(&s_fps);
			ft_error_routine(0);
		}
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_string_put(e->mlx, e->win, WIN_X - 200, 50, 0x00FFFFFF, disp_fps);
		ft_strdel(&s_fps);
		ft_strdel(&disp_fps);
	}
	return (0);
}

int		key_hook(int keycode, t_mlx *e)
{
	if (keycode == MLX_KEY_ESC)
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_window(e->mlx, e->win);
		free(e->mlx);
		exit(0);
	}
	return (0);
}
