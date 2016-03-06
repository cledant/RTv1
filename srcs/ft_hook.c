/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:27:39 by cledant           #+#    #+#             */
/*   Updated: 2016/03/06 12:39:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_error_routine(int type, t_mlx *e)
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
			ft_error_routine(1, e);
		ft_draw_image(e);
		if (gettimeofday(&(s_ms[1]), NULL) == -1)
			ft_error_routine(1, e);
		ms[0] = s_ms[0].tv_sec * 1000 + s_ms[0].tv_usec / 1000;
		ms[1] = s_ms[1].tv_sec * 1000 + s_ms[1].tv_usec / 1000;
		fps = ms[1] - ms[0];
		if ((s_fps = ft_itoa((int)fps)) == NULL)
			ft_error_routine(0, e);
		if ((disp_fps = ft_strjoin("RENDER TIME IN MS : ", s_fps)) == NULL)
		{
			ft_strdel(&s_fps);
			ft_error_routine(0, e);
		}
		e->render = 1;
		mlx_clear_window(e->mlx, e->win);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_string_put(e->mlx, e->win, WIN_X - 300, 50, 0x00FFFFFF, disp_fps);
		ft_strdel(&s_fps);
		ft_strdel(&disp_fps);
	}
	return (0);
}

int		key_hook(int keycode, t_mlx *e)
{
	t_camera	*camera;

	ft_putnbrendl(keycode);
	camera = e->cam;
	if (keycode == MLX_KEY_ESC)
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_window(e->mlx, e->win);
		if (e->cam != NULL)
			free(e->cam);
		if (e->obj_list != NULL)
			ft_lstdel(&(e->obj_list), &ft_lstfree_malloc);
		if (e->light_list != NULL)
			ft_lstdel(&(e->light_list), &ft_lstfree_malloc);
		free(e->mlx);
		exit(0);
	}
	else if (keycode == MLX_KEY_1)
	{
		if (e->cam != NULL)
			free(e->cam);
		e->cam = NULL;
		if (e->obj_list != NULL)
			ft_lstdel(&(e->obj_list), &ft_lstfree_malloc);
		if (e->light_list != NULL)
			ft_lstdel(&(e->light_list), &ft_lstfree_malloc);
		ft_init_scene(e);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_2)
	{
		if (e->cam != NULL)
			free(e->cam);
		e->cam = NULL;
		if (e->obj_list != NULL)
			ft_lstdel(&(e->obj_list), &ft_lstfree_malloc);
		if (e->light_list != NULL)
			ft_lstdel(&(e->light_list), &ft_lstfree_malloc);
		ft_init_scene_2(e);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_UP)
	{
		camera->coord[0] = camera->coord[0] + MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_DOWN)
	{
		camera->coord[0] = camera->coord[0] - MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_RIGHT)
	{
		camera->coord[1] = camera->coord[1] + MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_LEFT)
	{
		camera->coord[1] = camera->coord[1] - MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_PLUS)
	{
		camera->coord[2] = camera->coord[2] + MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_MINUS)
	{
		camera->coord[2] = camera->coord[2] - MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_W)
	{
		camera->camera_look_at[2] = camera->camera_look_at[2] + MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_S)
	{
		camera->camera_look_at[2] = camera->camera_look_at[2] - MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_A)
	{
		camera->camera_look_at[1] = camera->camera_look_at[1] + MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_D)
	{
		camera->camera_look_at[1] = camera->camera_look_at[1] - MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_Q)
	{
		camera->camera_look_at[0] = camera->camera_look_at[0] + MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	else if (keycode == MLX_KEY_E)
	{
		camera->camera_look_at[0] = camera->camera_look_at[0] - MLX_CAM_STEP;
		ft_camera_init(camera);
		e->render = 0;
		expose_hook(e);
	}
	return (0);
}
