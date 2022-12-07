/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:51:04 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 18:15:19 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	julia_deal_key(int key, t_event *event)
{
	if (key == ESC)
		mlx_loop_end(event->mlx->init);
	if (key == 'c')
	{
		if (event->coo->render == 3)
			event->coo->render = 0;
		else
			event->coo->render++;
		render(event);
	}
	if (key == 'w' || key == 's' || key == 'a' || key == 'd')
	{
		if (key == 'w')
			event->coo->offset_y += (event->coo->move_y * event->coo->zoom);
		if (key == 's')
			event->coo->offset_y -= (event->coo->move_y * event->coo->zoom);
		if (key == 'a')
			event->coo->offset_x += (event->coo->move_x * event->coo->zoom);
		if (key == 'd')
			event->coo->offset_x -= (event->coo->move_x * event->coo->zoom);
		render_julia(event);
	}
	return (0);
}

int	mouse_hook_julia(int button, int x, int y, t_event *event)
{
	(void)x;
	(void)y;
	if (button == M_DOWN)
	{
		event->coo->zoom /= 0.9;
		render_julia(event);
	}
	if (button == M_UP)
	{
		event->coo->zoom *= 0.9;
		render_julia(event);
	}
	return (1);
}

void	ft_init_julia(t_event *event)
{
	event->coo->zoom = 1.0;
	event->coo->render = 0;
	event->coo->offset_x = 2;
	event->coo->offset_y = 2;
	event->coo->move_x = 2;
	event->coo->move_y = 2;
}

int	get_mouse(t_event *event)
{
	mlx_mouse_get_pos(event->mlx->init, event->mlx->win,
		&event->coo->mouse_x, &event->coo->mouse_y);
	render_julia(event);
	return (1);
}
