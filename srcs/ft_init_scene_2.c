/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:25:57 by cledant           #+#    #+#             */
/*   Updated: 2016/03/06 12:39:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init_scene_2(t_mlx *e)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;
	t_light		*light;
	t_list		*begin;
	t_list		*member;
	t_camera	*cam_scene;
	double		tmp_coord[3];
	double		tmp_vec[3];
	double		tmp_norm;

	if ((e->cam = (t_camera *)malloc(1 * sizeof(t_camera))) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	cam_scene = e->cam;
	if ((begin = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	e->light_list = begin;
	tmp_coord[0] = -5;
	tmp_coord[1] = 0;
	tmp_coord[2] = 5;
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
	tmp_coord[0] = -50;
	tmp_coord[1] = 0;
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
	tmp_coord[0] = -70;
	tmp_coord[1] = -20;
	tmp_coord[2] = 20;
	if ((sphere = ft_sphere_new(0x00AA00AA, tmp_coord, 3)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.25, 0.4, 0.8, sphere);
	sphere->shiny = 100;
	begin->content = sphere;
	begin->content_size = 0;
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -100;
	tmp_coord[1] = 0;
	tmp_coord[2] = 0;
	tmp_vec[0] = 1;
	tmp_vec[1] = 0;
	tmp_vec[2] = 0;
	if ((plane = ft_plane_new(0x00AA0000, tmp_coord, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_plane_material(0.25, 0.4, 0.8, plane);
	plane->shiny = 75;
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
	ft_plane_material(0.25, 0.4, 0.8, plane);
	plane->shiny = 75;
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
	tmp_coord[2] = 20;
	tmp_vec[0] = 0;
	tmp_vec[1] = 0;
	tmp_vec[2] = 1;
	if ((plane = ft_plane_new(0x0000AAAA, tmp_coord, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_plane_material(0.25, 0.4, 0.8, plane);
	plane->shiny = 75;
	member->content = plane;
	member->content_size = 1;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = 0;
	tmp_coord[1] = -100;
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
	ft_plane_material(0.25, 0.4, 0.8, plane);
	plane->shiny = 75;
	member->content = plane;
	member->content_size = 1;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -20;
	tmp_coord[1] = -20;
	tmp_coord[2] = 5;
	tmp_vec[0] = 0;
	tmp_vec[1] = 0;
	tmp_vec[2] = 1;
	tmp_norm = sqrt(tmp_vec[0] * tmp_vec[0] + tmp_vec[1] * tmp_vec[1] +
		tmp_vec[2] * tmp_vec[2]);
	tmp_vec[0] = tmp_vec[0] / tmp_norm;
	tmp_vec[1] = tmp_vec[1] / tmp_norm;
	tmp_vec[2] = tmp_vec[2] / tmp_norm;
	if ((cyl = ft_cylinder_new(0x00AA00AA, tmp_coord, 2, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_cylinder_material(0.25, 0.4, 0.8, cyl);
	cyl->shiny = 1000;
	member->content = cyl;
	member->content_size = 2;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -70;
	tmp_coord[1] = -20;
	tmp_coord[2] = 5;
	tmp_vec[0] = 0;
	tmp_vec[1] = 0;
	tmp_vec[2] = 1;
	tmp_norm = sqrt(tmp_vec[0] * tmp_vec[0] + tmp_vec[1] * tmp_vec[1] +
		tmp_vec[2] * tmp_vec[2]);
	tmp_vec[0] = tmp_vec[0] / tmp_norm;
	tmp_vec[1] = tmp_vec[1] / tmp_norm;
	tmp_vec[2] = tmp_vec[2] / tmp_norm;
	if ((cyl = ft_cylinder_new(0x00AA00AA, tmp_coord, 2, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_cylinder_material(0.25, 0.4, 0.8, cyl);
	cyl->shiny = 1000;
	member->content = cyl;
	member->content_size = 2;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -70;
	tmp_coord[1] = 20;
	tmp_coord[2] = 5;
	tmp_vec[0] = 0;
	tmp_vec[1] = 0;
	tmp_vec[2] = 1;
	tmp_norm = sqrt(tmp_vec[0] * tmp_vec[0] + tmp_vec[1] * tmp_vec[1] +
		tmp_vec[2] * tmp_vec[2]);
	tmp_vec[0] = tmp_vec[0] / tmp_norm;
	tmp_vec[1] = tmp_vec[1] / tmp_norm;
	tmp_vec[2] = tmp_vec[2] / tmp_norm;
	if ((cyl = ft_cylinder_new(0x00AA00AA, tmp_coord, 2, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_cylinder_material(0.25, 0.4, 0.8, cyl);
	cyl->shiny = 1000;
	member->content = cyl;
	member->content_size = 2;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -20;
	tmp_coord[1] = 20;
	tmp_coord[2] = 5;
	tmp_vec[0] = 0;
	tmp_vec[1] = 0;
	tmp_vec[2] = 1;
	tmp_norm = sqrt(tmp_vec[0] * tmp_vec[0] + tmp_vec[1] * tmp_vec[1] +
		tmp_vec[2] * tmp_vec[2]);
	tmp_vec[0] = tmp_vec[0] / tmp_norm;
	tmp_vec[1] = tmp_vec[1] / tmp_norm;
	tmp_vec[2] = tmp_vec[2] / tmp_norm;
	if ((cyl = ft_cylinder_new(0x00AA00AA, tmp_coord, 2, tmp_vec)) == NULL)
	{
		free(member);
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_cylinder_material(0.25, 0.4, 0.8, cyl);
	cyl->shiny = 1000;
	member->content = cyl;
	member->content_size = 2;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -20;
	tmp_coord[1] = 20;
	tmp_coord[2] = -10;
	if ((sphere = ft_sphere_new(0x00AA00AA, tmp_coord, 3)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.25, 0.4, 0.8, sphere);
	sphere->shiny = 100;
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -20;
	tmp_coord[1] = 20;
	tmp_coord[2] = 20;
	if ((sphere = ft_sphere_new(0x00AA00AA, tmp_coord, 3)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.25, 0.4, 0.8, sphere);
	sphere->shiny = 100;
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -70;
	tmp_coord[1] = 20;
	tmp_coord[2] = -10;
	if ((sphere = ft_sphere_new(0x00AA00AA, tmp_coord, 3)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.25, 0.4, 0.8, sphere);
	sphere->shiny = 100;
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -70;
	tmp_coord[1] = 20;
	tmp_coord[2] = 20;
	if ((sphere = ft_sphere_new(0x00AA00AA, tmp_coord, 3)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.25, 0.4, 0.8, sphere);
	sphere->shiny = 100;
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -20;
	tmp_coord[1] = -20;
	tmp_coord[2] = 20;
	if ((sphere = ft_sphere_new(0x00AA00AA, tmp_coord, 3)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.25, 0.4, 0.8, sphere);
	sphere->shiny = 100;
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -20;
	tmp_coord[1] = -20;
	tmp_coord[2] = -10;
	if ((sphere = ft_sphere_new(0x00AA00AA, tmp_coord, 3)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.25, 0.4, 0.8, sphere);
	sphere->shiny = 100;
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	if ((member = ft_lstnew(NULL, 0)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);
	}
	tmp_coord[0] = -70;
	tmp_coord[1] = -20;
	tmp_coord[2] = -10;
	if ((sphere = ft_sphere_new(0x00AA00AA, tmp_coord, 3)) == NULL)
	{
		ft_putendl("Not enough memory");
		key_hook(MLX_KEY_ESC, e);	
	}
	ft_sphere_material(0.25, 0.4, 0.8, sphere);
	sphere->shiny = 100;
	member->content = sphere;
	member->content_size = 0;
	ft_lstpushback(begin, member);
	//debut init camera
	cam_scene->coord[0] = 100;
	cam_scene->coord[1] = 0;
	cam_scene->coord[2] = 10;
	cam_scene->camera_look_at[0] = -20;
	cam_scene->camera_look_at[1] = 0;
	cam_scene->camera_look_at[2] = 5;
	ft_camera_init(cam_scene);
	//fim camera
}
