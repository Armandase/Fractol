/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:45:43 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 15:09:11 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	int	pars;

	pars = parsing(argc, argv);
	if (!pars)
		return (0);
	else if (pars == 1)
		ft_mandelbrot();
	else
		ft_julia();
	return (0);
}
