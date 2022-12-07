/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:05:33 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 15:55:16 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	ft_calcul(t_event *event)
{
	long double	tmp;
	long double	tmp_x;
	long double	tmp_y;
	t_color		color;

	color.iter = 0;
	color.z = 0;
	tmp_x = event->coo->x;
	tmp_y = event->coo->y;
	while (color.iter < ITERATION && color.z <= 4)
	{
		tmp = tmp_x * tmp_x - tmp_y * tmp_y + event->coo->value_x;
		tmp_y = 2 * tmp_x * tmp_y + event->coo->value_y;
		tmp_x = tmp;
		color.z = (tmp_x * tmp_x + tmp_y * tmp_y);
		color.z = absolute_value(color.z);
		color.iter++;
	}
	return (color);
}

int	render_julia(t_event *event)
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
			convert_mouse(event);
			color = ft_calcul(event);
			if (color.iter == ITERATION)
				pixel_img_put(event, x, y, CENTER_COLOR);
			else
				ft_bicolor(color, event, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window
		(event->mlx->init, event->mlx->win, event->mlx->img, 0, 0);
	return (0);
}

int	get_mouse(t_event *event)
{
	mlx_mouse_get_pos(event->mlx->init, event->mlx->win,
		&event->coo->mouse_x, &event->coo->mouse_y);
	render_julia(event);
	return (1);
}

void	ft_julia_loop(t_event *event)
{
	mlx_key_hook(event->mlx->win, deal_key, event);
	mlx_hook(event->mlx->win,
		DestroyNotify, StructureNotifyMask, ft_clean_exit, event);
	mlx_mouse_hook(event->mlx->win, mouse_hook_julia, event);
	mlx_loop_hook(event->mlx->init, get_mouse, event);
	render_julia(event);
	mlx_loop(event->mlx->init);
	ft_clean_exit(event);
}

void	ft_julia(void)
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
	event->coo->mouse_y = 0;
	event->coo->mouse_x = 0;
	event->mlx->init = mlx_init();
	if (event->mlx->init == NULL)
		ft_clean_exit(event);
	event->mlx->win = mlx_new_window(event->mlx->init, WIDTH, HEIGHT, "Julia");
	if (event->mlx->win == NULL)
		ft_clean_exit(event);
	event->mlx->img = mlx_new_image(event->mlx->init, WIDTH, HEIGHT);
	event->mlx->img_addr = mlx_get_data_addr
		(event->mlx->img, &(event->mlx->bits_per_px),
			&(event->mlx->line_len), &(event->mlx->endian));
	ft_julia_loop(event);
}
