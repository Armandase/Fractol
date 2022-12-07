/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:05:33 by adamiens          #+#    #+#             */
/*   Updated: 2022/12/05 09:24:52 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	convert_plan(int x, int y, t_event *event)
{
	long double	pixel_x;
	long double	pixel_y;
	long double	tmp;

	event->coo->x = (long double)x;
	event->coo->y = (long double)y;
	if (WIDTH > HEIGHT)
	{
		pixel_y = 4.0 / HEIGHT;
		pixel_x = pixel_y;
		tmp = pixel_y * (WIDTH / 2 - (HEIGHT / 2));
		event->coo->x = pixel_x * event->coo->x - 2 - tmp;
		event->coo->y = pixel_y * event->coo->y - 2;
	}
	else
	{
		pixel_x = 4.0 / WIDTH;
		pixel_y = pixel_x;
		tmp = pixel_x * (HEIGHT / 2 - (WIDTH / 2));
		event->coo->x = pixel_x * event->coo->x - 2;
		event->coo->y = pixel_y * event->coo->y - 2 - tmp;
	}
	event->coo->x = pixel_x + (event->coo->x * (long double)(event->coo->zoom));
	event->coo->y = pixel_y + (event->coo->y * (long double)(event->coo->zoom));
}

t_color	calcul(t_coo coo)
{
	long double	tmp;
	long double	tmp_x;
	long double	tmp_y;
	t_color		color;

	color.iter = 0;
	color.z = 0;
	tmp_x = 0;
	tmp_y = 0;
	while (color.iter < ITERATION && color.z <= 10)
	{
		tmp = tmp_x * tmp_x - tmp_y * tmp_y + coo.x;
		tmp_y = 2 * tmp_x * tmp_y + coo.y;
		tmp_x = tmp;
		color.z = (tmp_x * tmp_x + tmp_y * tmp_y);
		color.z = absolute_value(color.z);
		color.iter++;
	}
	if (color.iter == ITERATION)
		return (color);
	else
		return (color);
}

int	render(t_event *event)
{
	int		x;
	int		y;
	t_color	color;

	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			convert_plan(x, y, event);
			color = calcul(*event->coo);
			if (color.iter == ITERATION)
				pixel_img_put(event, x, y, CENTER_COLOR);
			else
				ft_log_color(color, event, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window
		(event->mlx->init, event->mlx->win, event->mlx->img, 0, 0);
	return (0);
}

void	ft_mandel_loop(t_event *event)
{
	mlx_key_hook(event->mlx->win, deal_key, event);
	mlx_hook(event->mlx->win,
		DestroyNotify, StructureNotifyMask, ft_clean_exit, event);
	mlx_mouse_hook(event->mlx->win, mouse_hook, event);
	render(event);
	mlx_loop(event->mlx->init);
	ft_clean_exit(event);
}

void	ft_mandelbrot(void)
{
	t_event	*event;

	event = malloc(sizeof(t_event));
	if (!event)
		exit(1);
	(event->coo) = malloc(sizeof(t_coo));
	if (!event->coo)
		ft_clean_exit(event);
	(event->mlx) = malloc(sizeof(t_mlx));
	if (!event->mlx)
		ft_clean_exit(event);
	event->coo->zoom = 1.0;
	event->mlx->init = mlx_init();
	if (event->mlx->init == NULL)
		ft_clean_exit(event);
	event->mlx->win = mlx_new_window
		(event->mlx->init, WIDTH, HEIGHT, "Mandelbrot");
	if (event->mlx->win == NULL)
		ft_clean_exit(event);
	event->mlx->img = mlx_new_image(event->mlx->init, WIDTH, HEIGHT);
	event->mlx->img_addr = mlx_get_data_addr
		(event->mlx->img, &(event->mlx->bits_per_px),
			&(event->mlx->line_len), &(event->mlx->endian));
	ft_mandel_loop(event);
}
