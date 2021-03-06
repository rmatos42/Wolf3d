/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:02:12 by rmatos            #+#    #+#             */
/*   Updated: 2017/02/06 15:02:20 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>

typedef	struct	s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
}				t_keys;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bits;
	int			size_line;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_line
{
	t_point		*start;
	t_point		*end;
}				t_line;

typedef struct	s_dvect
{
	double		x;
	double		y;
}				t_dvect;

typedef struct	s_vect
{
	int			x;
	int			y;
}				t_vect;

typedef struct	s_wolf
{
	int			x;
	int			y;
	int			hit;
	int			side;
	int			line_len;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	int			tex_x;
	int			color;
	double		camera_x;
	double		wall_dist;
	double		time_tmp;
	double		time;
	double		frame_time;
	double		move_speed;
	double		rot_speed;
	double		wall_x;
	double		dist_wall;
	double		dist_player;
	double		current_dist;
	double		weight;
	t_dvect		*pos;
	t_dvect		*dir;
	t_dvect		*plane;
	t_vect		*step;
	t_dvect		*ray_pos;
	t_dvect		*ray_dir;
	t_vect		*map_loc;
	t_dvect		*side_dist;
	t_dvect		*delta_dist;
	t_dvect		*floor_wall;
	t_dvect		*cur_floor;
	t_vect		*floor_tex;
	t_line		*line;
}				t_wolf;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img_data;
	t_wolf		*wolf;
	int			height;
	int			width;
	int			half_height;
	int			half_width;
	int			**textures;
	int			**map;
	int			last_x;
	int			last_y;
	t_keys		*keys;
}				t_env;

typedef	struct	s_linevars
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err_tmp;
	int			cur_x;
	int			cur_y;
}				t_linevars;

t_img			*make_img(void *mlx, int x, int y);
t_env			*make_env(int x, int y);
t_point			*make_point(int x, int y);
t_line			*make_line(int x0, int y0, int x1, int y1);
int				line_len(int x0, int y0, int x1, int y1);
t_linevars		*get_linevars(t_line *line);
void			put_line(t_img *img_data, t_line *line, int color);
void			pixel_to_img(t_img *img_data, int x, int y, int color);
int				**make_textures(void);
t_wolf			*make_wolf(void);
t_vect			*make_vect(int x, int y);
t_dvect			*make_dvect(double x, double y);
void			floor_calc(t_env *env);
void			floor_cast(t_env *env);
int				wolf_mouse(int x, int y, t_env *env);
void			wolf_util(t_env *env);
void			wolf(t_env *env);
void			dda_util(t_env *env);
void			dda(t_env *env);
double			get_wall_dist(t_env *env);
void			texture_util(int **textures, int i, int j);
int				**make_textures(void);
void			line_calc(t_env *env);
void			draw_line(t_env *env);
void			draw_img(t_env *env);
void			set_speeds(t_env *env);
void			rot_dvect(t_dvect *vect, double theta);
void			line_calc(t_env *env);
void			draw_line(t_env *env);
void			texture_util(int **textures, int i, int j);
int				**make_textures(void);
void			dda_util(t_env *env);
void			dda(t_env *env);
void			draw_img(t_env *env);
int				key_pressed(int keycode, t_env *env);
int				key_released(int keycode, t_env *env);
int				**read_map(int fd);

#endif
