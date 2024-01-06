/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:09:03 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/05 22:56:11 by dcaetano         ###   ########.fr       */
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

#define MAPWIDTH 24
#define MAPHEIGHT 24
#define SCREENWIDTH 700
#define SCREENHEIGHT 700
#define TEXTUREWIDTH 64
#define TEXTUREHEIGHT 64
#define MOVE_SPEED 0.05
#define ROT_SPEED 0.03

int	g_world_map[MAPWIDTH][MAPHEIGHT] = {\
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, \
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} \
};

typedef struct s_img
{
	char			*addr;
	void			*img;
	int				width;
	int				height;
	unsigned int	*texture;
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
	t_img			no;
	t_img			so;
	t_img			we;
	t_img			ea;
}t_data;

double	double_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	part1(t_data *data, int x)
{
	data->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	data->delta_dist_x = sqrt(1 + (data->ray_dir_y * data->ray_dir_y) / \
		(data->ray_dir_x * data->ray_dir_x));
	data->delta_dist_y = sqrt(1 + (data->ray_dir_x * data->ray_dir_x) / \
		(data->ray_dir_y * data->ray_dir_y));
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
		if (g_world_map[data->map_x][data->map_y] > 0)
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
	auto double wall_x;
	if (data->side == 0)
		wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
	wall_x -= floor(wall_x);
	auto int tex_x = (int)(wall_x * (double)TEXTUREWIDTH);
	if (data->side == 0 && data->ray_dir_x > 0)
		tex_x = TEXTUREWIDTH - tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		tex_x = TEXTUREWIDTH - tex_x - 1;
	auto double step = 1.0 * TEXTUREHEIGHT / data->line_height;
	auto double tex_pos = (data->draw_start - SCREENHEIGHT / 2 + \
		data->line_height / 2) * step;
	auto int aux_y = -1;
	while (++aux_y < data->draw_start)
		mlx_pixel_put(data->mlx, data->win, x, aux_y, 0xCCCCCC);
	int y = data->draw_start - 1;
	while (++y < data->draw_end) {
		int tex_y = (int)tex_pos & (TEXTUREHEIGHT - 1);
		tex_pos += step;

		unsigned int color;
		if (data->side == 0 && data->ray_dir_x > 0)
			color = data->ea.texture[TEXTUREWIDTH * tex_y + tex_x];
		else if (data->side == 0 && data->ray_dir_x < 0)
			color = data->we.texture[TEXTUREWIDTH * tex_y + tex_x];
		else if (data->side == 1 && data->ray_dir_y > 0)
			color = data->so.texture[TEXTUREWIDTH * tex_y + tex_x];
		else
			color = data->no.texture[TEXTUREWIDTH * tex_y + tex_x];
		mlx_pixel_put(data->mlx, data->win, x, y, color);
	}
	while (y < SCREENHEIGHT)
		mlx_pixel_put(data->mlx, data->win, x, y++, 0x333333);
}

void	raycast(t_data *data, int x)
{
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
	data->dir_x = data->dir_x * cos(ROT_SPEED * angle) - \
		data->dir_y * sin(ROT_SPEED * angle);
	data->dir_y = oldDirX * sin(ROT_SPEED * angle) + \
		data->dir_y * cos(ROT_SPEED * angle);
	auto double oldPlaneX = data->plane_x;
	data->plane_x = data->plane_x * cos(ROT_SPEED * angle) - \
		data->plane_y * sin(ROT_SPEED * angle);
	data->plane_y = oldPlaneX * sin(ROT_SPEED * angle) + \
		data->plane_y * cos(ROT_SPEED * angle);
}

void	move_player(t_data *data, double x, double y)
{
	auto int mouse_x, mouse_y;
	mlx_mouse_get_pos(data->mlx, data->win, &mouse_x, &mouse_y);
	if (g_world_map[(int)(data->pos_x + x)][(int)data->pos_y] == false)
		data->pos_x += x;
	if (g_world_map[(int)data->pos_x][(int)(data->pos_y + y)] == false)
		data->pos_y += y;
}

void	check_keys(t_data *data, int x, int y)
{
	if ((data->key_right || (x > 500 && x < 700 && y > 0 && y < 700)) && \
		!(data->key_left || (x > 0 && x < 200 && y > 0 && y < 700)))
		update_angle(data, -1);
	if ((data->key_left || (x > 0 && x < 200 && y > 0 && y < 700)) && \
		!(data->key_right || (x > 500 && x < 700 && y > 0 && y < 700)))
		update_angle(data, 1);
	if (data->key_w && !data->key_s && !data->key_a && !data->key_d)
		move_player(data, data->dir_x * MOVE_SPEED * 1, \
			data->dir_y * MOVE_SPEED * 1);
	if (data->key_s && !data->key_w && !data->key_a && !data->key_d)
		move_player(data, data->dir_x * MOVE_SPEED * -1, \
			data->dir_y * MOVE_SPEED * -1);
	if (data->key_a && !data->key_w && !data->key_s && !data->key_d)
		move_player(data, data->dir_y * MOVE_SPEED * -1, \
			data->dir_x * MOVE_SPEED * 1);
	if (data->key_d && !data->key_w && !data->key_s && !data->key_a)
		move_player(data, data->dir_y * MOVE_SPEED * 1, \
			data->dir_x * MOVE_SPEED * -1);
}

int	render(t_data *data)
{
	auto int x, y;
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	check_keys(data, x, y);
	raycast(data, -1);
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
		exit(0);
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
	return (0);
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
	data->plane_x = (0 + data->dir_y) * 0.66;
	data->plane_y = (0 - data->dir_x) * 0.66;
}

unsigned int	convert_to_rgb(int value)
{
	auto unsigned int r = (value >> 16) & 0xFF;
	auto unsigned int g = (value >> 8) & 0xFF;
	auto unsigned int b = value & 0xFF;
	return (r << 16 | g << 8 | b);
}

unsigned int	*read_xpm_file(t_data *data, char *filename)
{
	t_img			img;
	char			*img_data;

	img.img = mlx_xpm_file_to_image(data->mlx, filename, &img.width, &img.height);
	auto int bpp, size_line, endian;
	img_data = mlx_get_data_addr(img.img, &bpp, &size_line, &endian);
	img.texture = (unsigned int *)malloc(sizeof(unsigned int) * img.height * img.width);
	auto int x = -1;
	while (++x < img.width)
	{
		auto int y = -1;
		while (++y < img.height)
		{
			auto int color = *(unsigned int *)(img_data + (x * bpp / 8) + (y * size_line));
			img.texture[y * img.width + x] = convert_to_rgb(color);
		}
	}
	return (img.texture);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREENWIDTH, SCREENHEIGHT, "Raycaster");
	data.pos_x = 12;
	data.pos_y = 12;
	get_angle(&data, 'N');
	data.key_left = false;
	data.key_right = false;
	data.key_w = false;
	data.key_s = false;
	data.key_a = false;
	data.key_d = false;
	data.no.texture = read_xpm_file(&data, "./textures/wolfenstein/purple_stone.xpm");
	data.so.texture = read_xpm_file(&data, "./textures/wolfenstein/grey_stone.xpm");
	data.we.texture = read_xpm_file(&data, "./textures/wolfenstein/blue_stone.xpm");
	data.ea.texture = read_xpm_file(&data, "./textures/wolfenstein/red_brick.xpm");
	mlx_mouse_move(data.mlx, data.win, SCREENHEIGHT / 2, SCREENWIDTH / 2);
	mlx_hook(data.win, KeyPress, KeyPressMask, &key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &key_release, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	return (0);
}
