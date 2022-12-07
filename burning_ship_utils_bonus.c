/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:00:55 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 17:06:22 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_init_bs(t_event *event)
{
	event->coo->zoom = 1.0;
	event->coo->render = 0;
	event->coo->offset_x = 2;
	event->coo->offset_y = 2;
	event->coo->move_x = 2;
	event->coo->move_y = 2;
}

int	bs_mouse_hook(int button, int x, int y, t_event *event)
{
	(void)x;
	(void)y;
	if (button == M_DOWN)
	{
		event->coo->zoom /= 0.9;
		bs_render(event);
	}
	if (button == M_UP)
	{
		event->coo->zoom *= 0.9;
		bs_render(event);
	}
	return (1);
}

int	bs_deal_key(int key, t_event *event)
{
	if (key == ESC)
		mlx_loop_end(event->mlx->init);
	if (key == 'c')
	{
		if (event->coo->render == 3)
			event->coo->render = 0;
		else
			event->coo->render++;
		bs_render(event);
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
		bs_render(event);
	}
	return (0);
}
