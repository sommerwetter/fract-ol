/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:01:30 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/22 00:33:30 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	changevalues(t_complex *z, t_info *info, double *cr, double *ci)
{
	z->r = *cr;
	z->i = *ci;
	*cr = info->k.r;
	*ci = info->k.i;
}

/*
	Function to calculate fractal of Mandelbrot and Julia. Only changes
	starting values if it's supposed to calculate Julia. Otherwise is the
	same principle.
*/
int	mj(double cr, double ci, t_info *info)
{
	int			n;
	t_complex	z;
	double		tmp;
	int			is_in_set;

	z.r = 0;
	z.i = 0;
	n = -1;
	is_in_set = 1;
	if (info->type == 2)
		changevalues(&z, info, &cr, &ci);
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

/*
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
*/
