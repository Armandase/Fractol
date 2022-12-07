/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:15:35 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 15:17:26 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_bicolor(t_color color, t_event *event, int x, int y)
{
	long double	tmp;

	if (color.iter % 2 == 0)
		tmp = 0xf4a261;
	else
		tmp = 0x457b9d;
	pixel_img_put(event, x, y, tmp);
}

void	ft_check_color(t_color *color)
{
	if (color->red < 0)
		color->red = 0;
	if (color->green < 0)
		color->green = 0;
	if (color->blue < 0)
		color->blue = 0;
	if (color->red > 255)
		color->red = 255;
	if (color->green > 255)
		color->green = 255;
	if (color->blue > 255)
		color->blue = 255;
}

void	ft_log_color(t_color color, t_event *event, int x, int y)
{
	float		modulus;
	float		mu;

	modulus = sqrt (color.z);
	mu = (float)color.iter + 1.0 - (log(log(modulus))) / log(2.0);
	color.red = (COLOR / 256 / 256) - 256 / mu ;
	color.green = ((COLOR / 256) % 256) - 256 / mu;
	color.blue = (COLOR % 256) - 256 / mu;
	ft_check_color(&color);
	mu = ((color.red * 256 * 256) + (color.green * 256) + color.blue);
	pixel_img_put(event, x, y, mu);
}
