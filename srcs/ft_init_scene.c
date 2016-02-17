/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:25:57 by cledant           #+#    #+#             */
/*   Updated: 2016/02/17 14:39:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_init_scene(t_mlx *e)
{
	t_sphere	*sp_scene;
	t_camera	*cam_scene;

	cam_scene = e->cam;
	sp_scene = e->sph;
	sp_scene->total_sp = 1;
	sp_scene->coord[0] = 0;
	sp_scene->coord[1] = 0;
	sp_scene->coord[2] = 0;
	cam_scene->coord[0] = -250;
	cam_scene->coord[1] = 0;
	cam_scene->coord[2] = 0;
	cam_scene->camera_size[0] = 0.35;
	cam_scene->camera_size[1] = 0.5;
	cam_scene->camera_size[2] = 1;
	cam_scene->camera_look_at[0] = 0;
	cam_scene->camera_look_at[1] = 0;
	cam_scene->camera_look_at[2] = 0;
}
