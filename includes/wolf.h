#ifndef WOLF_H
# define WOLF_H

#include "mlx.h"
#include "libft.h"
#include <math.h>
#include <pthread.h>

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

typedef struct	s_fvect
{
	double 		x;
	double		y;
}				t_fvect;

typedef struct	s_vect
{
	int			x;
	int			y;
}				t_vect;

typedef struct	s_wolf
{
	int			x;
	t_fvect		*pos;
	t_fvect		*dir;
	t_fvect		*plane;
	double		cameraX;
	t_fvect		*ray_pos;
	t_fvect		*ray_dir;
	t_vect		*map_loc;
	t_fvect		*side_dist;
	t_fvect		*delta_dist;
	double		perpWallDist;
	t_vect		*step;
	int			hit;
	int			side;
	int			line_len; //height of line
	int			draw_start;
	int			draw_end;
	t_line		*line;
	double 		time_tmp;
	double		time;
	double		frame_time;
	double		move_speed;
	double		rot_speed;
	int 		tex_num;
	double 		wall_x;
	int 		tex_x;
	int 		y;
	double		floorXWall;
	double 		floorYWall;
	double		distWall;
	double		distPlayer;
	double		currentDist;
	double		weight;
	double		currentFloorX;
	double		currentFloorY;
	int			floorTexX;
	int			floorTexY;
	int			color;
}				t_wolf;

typedef	struct	s_env
{
	void		*mlx;
	void 		*win;
	t_img 		*img_data;
	t_wolf		*wolf;
	int			height;
	int			width;
	int			half_height;
	int			half_width;
	int			**textures;
	int			last_x;
	int			last_y;
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
void	pixel_to_img(t_img *img_data, int x, int y, int color);
int		**make_textures(void);
t_wolf *make_wolf(void);
t_vect 	*make_vect(int x, int y);
t_fvect 	*make_fvect(double x, double y);
void 	floor_calc(t_env *env);
void 	floor_cast(t_env *env);
void 	move_camera(int keycode, t_env *env);
void 	rotate_camera(int keycode, t_env *env);
int 	wolf_keys(int keycode, t_env *env);
int		wolf_mouse(int x, int y, t_env *env);
int		map_value(int x, int y);
void 	wolf_util(t_env *env);
void 	wolf(t_env *env);
void 	dda_util(t_env *env);
void 	dda(t_env *env);
double get_wall_dist(t_env *env);
void 	texture_util(int **textures, int i, int j);
int		**make_textures(void);
void 	line_calc(t_env *env);
void 	draw_line(t_env *env);
void 	draw_img(t_env *env);
void 	set_speeds(t_env *env);
void 	rot_fvect(t_fvect *vect, double theta);
void 	line_calc(t_env *env);
void 	draw_line(t_env *env);
void 	texture_util(int **textures, int i, int j);
int		**make_textures(void);
void 	dda_util(t_env *env);
void 	dda(t_env *env);


#endif
