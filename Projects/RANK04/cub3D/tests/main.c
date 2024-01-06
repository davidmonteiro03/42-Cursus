/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:09:03 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/06 16:10:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*

	MAP
	-1----------1111----------11-------1-
	1S1--------100001------111001-1111101
	101-------10000001----100000010000001
	101--------1000001---100000000011111-
	101------110000001----10000000001----
	101-----100010000011110000000111-----
	101------101-1000000000000001--------
	1001------1--10000000000000001-------
	10001---------100000000000001--------
	100001111111110000000000000001-------
	100000000000000000000000000000111111-
	1000000000000000000000000000000000001
	111000000010001000100000000111111111-
	---1111111-111-111-11111111----------

*/

#define MAPWIDTH 37
#define MAPHEIGHT 14
#define SCREENWIDTH 700
#define SCREENHEIGHT 700
#define SENSIBILITY 20

char	*g_world_map[MAPHEIGHT] = {\
	"-1----------1111----------11-------1-",\
	"1S1--------100001------111001-1111101",\
	"101-------10000001----100000010000001",\
	"101--------1000001---100000000011111-",\
	"101------110000001----10000000001----",\
	"101-----100010000011110000000111-----",\
	"101------101-1000000000000001--------",\
	"1001------1--10000000000000001-------",\
	"10001---------100000000000001--------",\
	"100001111111110000000000000001-------",\
	"100000000000000000000000000000111111-",\
	"1000000000000000000000000000000000001",\
	"111000000010001000100000000111111111-",\
	"---1111111-111-111-11111111----------"\
};

typedef struct s_draw
{
	int	x;
	int	y_start;
	int	y_end;
}t_draw;

typedef struct s_img
{
	char			*addr;
	void			*img;
	int				width;
	int				height;
	unsigned int	**texture;
}t_img;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				map_x;
	int				map_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
	bool			key_w;
	bool			key_s;
	bool			key_a;
	bool			key_d;
	bool			key_left;
	bool			key_right;
	bool			key_esc;
	unsigned int	color;
	t_img			no;
	t_img			so;
	t_img			we;
	t_img			ea;
	char			c;
}t_data;

double	double_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ver_line(t_data *data, int x)
{
	if (data->draw_end < data->draw_start)
	{
		data->draw_start += data->draw_end;
		data->draw_end = data->draw_start - data->draw_end;
		data->draw_start -= data->draw_end;
	}
	if (data->draw_end < 0 || \
		data->draw_start >= SCREENHEIGHT || x < 0 || x >= SCREENWIDTH)
		return ;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_end >= SCREENWIDTH)
		data->draw_end = SCREENHEIGHT - 1;
	auto int aux_y = -1;
	auto int y = data->draw_start - 1;
	while (++aux_y < y + 1)
		mlx_pixel_put(data->mlx, data->win, x, aux_y, 0xCCCCCC);
	while (++y <= data->draw_end)
		mlx_pixel_put(data->mlx, data->win, x, y, data->color);
	while (y < SCREENHEIGHT)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, 0x333333);
		++y;
	}
}

void	part1(t_data *data, int x)
{
	data->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = pow(10.0, 30.0);
	else
		data->delta_dist_x = double_abs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = pow(10.0, 30.0);
	else
		data->delta_dist_y = double_abs(1 / data->ray_dir_y);
}

void	part2(t_data *data)
{
	data->hit = 0;
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - \
			data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - \
			data->pos_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - \
			data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - \
			data->pos_y) * data->delta_dist_y;
	}
}

void	part3(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (g_world_map[data->map_x][data->map_y] == '1')
			data->hit = 1;
	}
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
}

void	part4(t_data *data, int x)
{
	data->line_height = (int)(SCREENHEIGHT / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + SCREENHEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + SCREENHEIGHT / 2;
	if (data->draw_end >= SCREENHEIGHT)
		data->draw_end = SCREENHEIGHT - 1;
	if (data->side == 0)
	{
		if (data->step_x == -1)
			data->color = 0x00FF00;
		else
			data->color = 0xFF0000;
	}
	else
	{
		if (data->step_y == -1)
			data->color = 0x0000FF;
		else
			data->color = 0xFFFF00;
	}
	ver_line(data, x);
	data->move_speed = 0.05;
	data->rot_speed = 0.03;
}

void	raycast(t_data *data)
{
	auto int x = -1;
	while (++x < SCREENWIDTH)
	{
		part1(data, x);
		part2(data);
		part3(data);
		part4(data, x);
	}
}

void	update_angle(t_data *data, int angle)
{
	auto double oldDirX = data->dir_x;
	data->dir_x = data->dir_x * cos(data->rot_speed * angle) - \
		data->dir_y * sin(data->rot_speed * angle);
	data->dir_y = oldDirX * sin(data->rot_speed * angle) + \
		data->dir_y * cos(data->rot_speed * angle);
	auto double oldPlaneX = data->plane_x;
	data->plane_x = data->plane_x * cos(data->rot_speed * angle) - \
		data->plane_y * sin(data->rot_speed * angle);
	data->plane_y = oldPlaneX * sin(data->rot_speed * angle) + \
		data->plane_y * cos(data->rot_speed * angle);
}

void	move_player(t_data *data, double x, double y)
{
	if (g_world_map[(int)(data->pos_x + x)][(int)data->pos_y] != '1' && \
		g_world_map[(int)(data->pos_x + x)][(int)data->pos_y] != '-')
		data->pos_x += x;
	if (g_world_map[(int)data->pos_x][(int)(data->pos_y + y)] != '1' && \
		g_world_map[(int)data->pos_x][(int)(data->pos_y + y)] != '-')
		data->pos_y += y;
}

void	check_keys(t_data *data, int x, int y)
{
	(void)x;
	(void)y;
	printf("data->key_esc: %d\n", data->key_esc);
	printf("data->key_right: %d\n", data->key_right);
	printf("data->key_left: %d\n", data->key_left);
	printf("data->key_w: %d\n", data->key_w);
	printf("data->key_s: %d\n", data->key_s);
	printf("data->key_a: %d\n", data->key_a);
	printf("data->key_d: %d\n", data->key_d);
	if (data->key_esc)
		exit(0);
	if (data->key_right)
		update_angle(data, -1);
	if (data->key_left)
		update_angle(data, 1);
	if (data->key_w)
		move_player(data, data->dir_x * data->move_speed, \
			data->dir_y * data->move_speed);
	if (data->key_s)
		move_player(data, data->dir_x * -data->move_speed, \
			data->dir_y * -data->move_speed);
	if (data->key_a)
		move_player(data, data->dir_y * -data->move_speed, \
			data->dir_x * data->move_speed);
	if (data->key_d)
		move_player(data, data->dir_y * data->move_speed, \
			data->dir_x * -data->move_speed);
}

int	render(t_data *data)
{
	auto int x, y;
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	check_keys(data, x, y);
	raycast(data);
	// usleep(10000);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->key_w = true;
	else if (keycode == XK_s)
		data->key_s = true;
	else if (keycode == XK_a)
		data->key_a = true;
	else if (keycode == XK_d)
		data->key_d = true;
	else if (keycode == XK_Right)
		data->key_right = true;
	else if (keycode == XK_Left)
		data->key_left = true;
	else if (keycode == XK_Escape)
		data->key_esc = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->key_w = false;
	else if (keycode == XK_s)
		data->key_s = false;
	else if (keycode == XK_a)
		data->key_a = false;
	else if (keycode == XK_d)
		data->key_d = false;
	else if (keycode == XK_Right)
		data->key_right = false;
	else if (keycode == XK_Left)
		data->key_left = false;
	else if (keycode == XK_Escape)
		data->key_esc = false;
	return (0);
}

unsigned int	convert_to_rgb(int value)
{
	auto unsigned int r = (value >> 16) & 0xFF;
	auto unsigned int g = (value >> 8) & 0xFF;
	auto unsigned int b = value & 0xFF;
	return (r << 16 | g << 8 | b);
}

unsigned int	**read_xpm_file(t_data *data, char *filename)
{
	t_img			img;
	char			*img_data;

	img.img = mlx_xpm_file_to_image(data->mlx, filename, &img.width, &img.height);
	auto int bpp, size_line, endian;
	img_data = mlx_get_data_addr(img.img, &bpp, &size_line, &endian);
	img.texture = (unsigned int **)malloc(sizeof(unsigned int *) * img.height);
	auto int i = -1;
	while (++i < img.height)
		img.texture[i] = (unsigned int *)malloc(sizeof(unsigned int) * img.width);
	i = -1;
	while (++i < img.height)
	{
		auto int j = -1;
		while (++j < img.width)
			img.texture[j][i] = convert_to_rgb(*(int *)(img_data + \
				(i * img.width + j) * bpp / 8));
	}
	return (img.texture);
}

void	get_angle(t_data *data, char c)
{
	data->dir_x = 0;
	data->dir_y = -1;
	if (c == 'N')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	else if (c == 'S')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	else if (c == 'E')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	data->plane_x = data->dir_y * 0.66;
	data->plane_y = -data->dir_x * 0.66;
}

void	get_player_pos(t_data *data)
{
	auto int i = -1;
	while (++i < MAPHEIGHT)
	{
		auto int j = -1;
		while (++j < MAPWIDTH)
		{
			if (strchr("NSEW", g_world_map[i][j]))
			{
				data->pos_x = i + 0.5;
				data->pos_y = j + 0.5;
				data->c = g_world_map[i][j];
				return ;
			}
		}
	}
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREENWIDTH, SCREENHEIGHT, "Raycaster");
	get_player_pos(&data);
	get_angle(&data, data.c);
	data.key_left = false;
	data.key_right = false;
	data.key_w = false;
	data.key_s = false;
	data.key_a = false;
	data.key_d = false;
	data.key_esc = false;
	data.no.texture = read_xpm_file(&data, "./textures/wolfenstein/purple_stone.xpm");
	data.so.texture = read_xpm_file(&data, "./textures/wolfenstein/grey_stone.xpm");
	data.we.texture = read_xpm_file(&data, "./textures/wolfenstein/blue_stone.xpm");
	data.ea.texture = read_xpm_file(&data, "./textures/wolfenstein/red_brick.xpm");
	// mlx_mouse_move(data.mlx, data.win, SCREENHEIGHT / 2, SCREENWIDTH / 2);
	mlx_hook(data.win, KeyPress, KeyPressMask, &key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &key_release, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	return (0);
}
