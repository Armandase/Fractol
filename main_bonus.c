/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:45:43 by adamiens          #+#    #+#             */
/*   Updated: 2022/11/25 17:07:16 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	int	pars;

	pars = parsing(argc, argv);
	if (!pars)
		return (0);
	else if (pars == 1)
		ft_mandelbrot();
	else if (pars == 2)
		ft_julia();
	else if (pars == 3)
		ft_multibulb();
	else
		ft_bs();
	return (0);
}
