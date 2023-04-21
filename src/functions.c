/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:01:30 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/21 23:51:48 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(double cr, double ci)
{
	int			n;
	t_complex	z;
	double		tmp;
	int			is_in_set;

	z.r = 0;
	z.i = 0;
	n = -1;
	is_in_set = 1;
	while (++n < MAX_IT)
	{
		if ((pow(z.r, 2.0) + pow(z.i, 2.0)) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = (2 * z.r * z.i) + ci;
		z.r = pow(z.r, 2.0) - pow(z.i, 2.0) + cr;
		z.i = tmp;
	}
	if (n == MAX_IT)
		return (0);
	return (n);
}

int	julia(double zr, double zi, t_info *info)
{
	int		n;
	double	tmp;
	int		is_in_set;
	
	n = -1;
	is_in_set = 1;
	while (++n < MAX_IT)
	{
		if ((pow(zr, 2.0) + pow(zi, 2.0)) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = (2 * zr * zi) + info->k.i;
		zr = pow(zr, 2.0) - pow(zi, 2.0) + info->k.r;
		zi = tmp;
	}
	if (n == MAX_IT)
		return (0);
	return (n);
}
