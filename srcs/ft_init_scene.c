/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:25:57 by cledant           #+#    #+#             */
/*   Updated: 2016/03/04 10:10:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	ft_init_scene(t_mlx *e)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;
	t_cone		*cone;
	t_light		*light;
	t_list		*begin;
	t_list		*member;
	t_camera	*cam_scene;
	double		tmp_coord[3];
	double		tmp_vec[3];
	double		tmp_norm;

	cam_scene = e->cam;
	if ((begin = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	e->light_list = begin;
	tmp_coord[0] = 20;
	tmp_coord[1] = 20;
	tmp_coord[2] = 10;
	if ((light = ft_light_new(tmp_coord, 0x00FFFFFF)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	begin->content = light;
	begin->content_size = 0;
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -3;
	tmp_coord[1] = -3;
	tmp_coord[2] = 5;
	if ((light = ft_light_new(tmp_coord, 0x00FFFFFF)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	member->content = light;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((begin = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	e->obj_list = begin;
	tmp_coord[0] = 0;
	tmp_coord[1] = 0;
	tmp_coord[2] = 0;
	if ((sphere = ft_sphere_new(0x00FF0000, tmp_coord, 1)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.4, 1, 1, sphere);
	sphere->shiny = 100;
	begin->content = sphere;
	begin->content_size = 0;
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = 0;
	tmp_coord[2] = 8;
	if ((sphere = ft_sphere_new(0x0000FF00, tmp_coord, 2)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.4, 1, 1, sphere);
	sphere->shiny = 100;
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 8;
	tmp_coord[1] = 0;
	tmp_coord[2] = 0;
	if ((sphere = ft_sphere_new(0x000000FF, tmp_coord, 2)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.4, 1, 1, sphere);
	sphere->shiny = 100;
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = 8;
	tmp_coord[2] = 0;
	if ((sphere = ft_sphere_new(0x00FF00FF, tmp_coord, 2)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.4, 1, 1, sphere);
	sphere->shiny = 100;
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -10;
	tmp_coord[1] = 0;
	tmp_coord[2] = 0;
	tmp_vec[0] = 1;
	tmp_vec[1] = 0;
	tmp_vec[2] = 0;
	if ((plane = ft_plane_new(0x00AAAAAA, tmp_coord, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_plane_material(0.7, 1, 0.1, plane);
	plane->shiny = 1000;
	member->content = plane;
	member->content_size = 1;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = 0;
	tmp_coord[2] = -10;
	tmp_vec[0] = 0;
	tmp_vec[1] = 0;
	tmp_vec[2] = 1;
	if ((plane = ft_plane_new(0x0000AAAA, tmp_coord, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_plane_material(0.7, 1, 0.1, plane);
	plane->shiny = 1000;
	member->content = plane;
	member->content_size = 1;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = -10;
	tmp_coord[2] = 0;
	tmp_vec[0] = 0;
	tmp_vec[1] = 1;
	tmp_vec[2] = 0;
	if ((plane = ft_plane_new(0x00AAAA00, tmp_coord, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_plane_material(0.7, 1, 1, plane);
	plane->shiny = 1000;
	member->content = plane;
	member->content_size = 1;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 8;
	tmp_coord[1] = 0;
	tmp_coord[2] = 5;
	tmp_vec[0] = 0;
	tmp_vec[1] = 0;
	tmp_vec[2] = 1;
	tmp_norm = sqrt(tmp_vec[0] * tmp_vec[0] + tmp_vec[1] * tmp_vec[1] +
		tmp_vec[2] * tmp_vec[2]);
	tmp_vec[0] = tmp_vec[0] / tmp_norm;
	tmp_vec[1] = tmp_vec[1] / tmp_norm;
	tmp_vec[2] = tmp_vec[2] / tmp_norm;
	if ((cyl = ft_cylinder_new(0x00AA00AA, tmp_coord, 1, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_cylinder_material(0.7, 1, 1, cyl);
	cyl->shiny = 1000;
	member->content = cyl;
	member->content_size = 2;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = 5;
	tmp_coord[2] = 5;
	tmp_vec[0] = 0;
	tmp_vec[1] = 0;
	tmp_vec[2] = 1;
	tmp_norm = sqrt(tmp_vec[0] * tmp_vec[0] + tmp_vec[1] * tmp_vec[1] +
		tmp_vec[2] * tmp_vec[2]);
	tmp_vec[0] = tmp_vec[0] / tmp_norm;
	tmp_vec[1] = tmp_vec[1] / tmp_norm;
	tmp_vec[2] = tmp_vec[2] / tmp_norm;
	if ((cone = ft_cone_new(0x00AAAA00, tmp_coord, 0, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_cone_angle(20, cone);
	ft_cone_material(0.7, 1, 1, cone);
	cone->shiny = 1000;
	member->content = cone;
	member->content_size = 3;
	ft_lstpushback(begin, member);
	//debut init camera
	cam_scene->coord[0] = 100;
	cam_scene->coord[1] = 100;
	cam_scene->coord[2] = 10;
	cam_scene->camera_look_at[0] = 0;
	cam_scene->camera_look_at[1] = 0;
	cam_scene->camera_look_at[2] = 0;
	ft_camera_init(cam_scene);
	//fim camera
}
