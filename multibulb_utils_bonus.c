/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibulb_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:57:15 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 18:22:01 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_multi_hook(int button, int x, int y, t_event *event)
{
	(void)x;
	(void)y;
	if (button == M_DOWN)
	{
		event->coo->zoom /= 0.9;
		render_multi(event);
	}
	if (button == M_UP)
	{
		event->coo->zoom *= 0.9;
		render_multi(event);
	}
	return (1);
}

void	ft_select_offset(int key, t_event *event)
{
	if (key == 'w')
		event->coo->offset_y += (event->coo->move_y * event->coo->zoom);
	if (key == 's')
		event->coo->offset_y -= (event->coo->move_y * event->coo->zoom);
	if (key == 'a')
		event->coo->offset_x += (event->coo->move_x * event->coo->zoom);
	if (key == 'd')
		event->coo->offset_x -= (event->coo->move_x * event->coo->zoom);
	render_multi(event);
}

int	bonus_deal_key(int key, t_event *event)
{
	if (key == ESC)
		mlx_loop_end(event->mlx->init);
	if (key == 'k')
	{
		event->coo->bulb++;
		render_multi(event);
	}
	if (key == 'j' && event->coo->bulb > 2)
	{
		event->coo->bulb--;
		render_multi(event);
	}
	if (key == 'c')
	{
		if (event->coo->render == 3)
			event->coo->render = 0;
		else
			event->coo->render++;
		render_multi(event);
	}
	if (key == 'w' || key == 's' || key == 'a' || key == 'd')
		ft_select_offset(key, event);
	return (0);
}

void	ft_init_value(t_event *event)
{
	event->coo->zoom = 1.0;
	event->coo->bulb = 2;
	event->coo->render = 0;
	event->coo->offset_x = 2;
	event->coo->offset_y = 2;
	event->coo->move_x = 2;
	event->coo->move_y = 2;
}
