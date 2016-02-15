/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:33:23 by cledant           #+#    #+#             */
/*   Updated: 2016/02/15 17:39:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# define MLX_KEY_ESC 53
# define WIN_X 1280
# define WIN_Y 720
# define FOV 90

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		render;
	int		y_max;
	int		x_max;
	double	alpha;
	double	inc_alpha;
	double	rad_alpha;
	double	cos_rad_alpha;
	double	sin_rad_alpha;
	double	x_player;
	double	y_player;
	double	z_player;
	size_t	dist_to_proj_plane;
}				t_mlx;

void			ft_mlx_c_to_c_cpy_pixel(char *dest_i, char *src_i,
					int coord[2][2], int sizeline[2]);
int				expose_hook(t_mlx *e);
int				key_hook(int keycode, t_mlx *e);
int				mouse_motion(int x, int y, t_mlx *e);
size_t			ft_lstseek_max_x(t_list *list);
int				**ft_fill_int_tab2(t_list *list, int x, int y);
int				ft_lstsplit_whitespaces_content(t_list *list);
int				ft_what_faces_ray(double alpha);
int				ft_what_faces_ray_for_verti(double alpha);
int				ft_check_wall(t_mlx *e, int r_x, int r_y);
double			ft_horizontal_intersection(t_mlx *e, double alpha[8],
					int *wall_type, double (*int_coord)[2]);
double			ft_vertical_intersection(t_mlx *e, double alpha[8],
					int *wall_type, double (*int_coord)[2]);
double			ft_ray_lenght(int *begin, double *end, double angle[8]);
double			ft_select_ray(t_mlx *e, double angle[8], int *wall_type,
					double (*int_coord)[2]);
void			ft_draw_image(t_mlx *e);
int				ft_check_collision(t_mlx *e, double angle, size_t d_collision,
					int keycode);
int				ft_load_texture(t_mlx *e);
void			ft_clear_texture(t_mlx *e);
void			ft_clear_texture_2(t_mlx *e);
void			ft_draw_texture(t_mlx *e, int counter[4], int limit[2],
					double coord[2]);
void			ft_draw_ceiling_floor(t_mlx *e, int disp_i_col, int limit[2][2],
					double angle[8]);
void			ft_alloc_img_char(t_mlx *e);
void			ft_alloc_img_char_2(t_mlx *e);
void			ft_change_anim(t_mlx *e);
void			ft_init_struct(t_mlx *e);
void			ft_free_all(t_mlx *e);

#endif
