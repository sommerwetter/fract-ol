/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:01:30 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/15 21:03:19 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	give_color(int n)
{
	if ((1 < n) && (n < 3))
		return(0x00FFFF);
	if ((3 <= n) && (n < 6))
		return(0x66CCCC);
	if ((6 <= n) && (n < 10))
		return(0x99CCCC);
	if ((10 <= n) &&( n < 30))
		return(0x99CCCC);
	if ((30 <= n) && (n < 60))
		return(0xCCCCCC);
	if ((60 <= n) && (n < 120))
		return(0xFFFFFF);
	return(BLACK);
}

static int	calc(t_info *info, int x, int y)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;
	int		is_in_set;

	zr = 0;
	zi = 0;
	n = -1;
	is_in_set = 1;
	while (++n < 120)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = 2 * zr * zi + info->comp.ci;
		zr = zr * zr - zi * zi + info->comp.cr;
		zi = tmp;
	}
	if (is_in_set == 1)
		put_p(BLACK, x, y, &info->img);
	else
		put_p(give_color(n), x, y, &info->img);
	return (n);
}

void	mandelbrot(t_info *info)
{
	int		x;
	int		y;

	info->comp.min_r = -2.0;
	info->comp.max_r = 1.0;
	info->comp.min_i = -1.5;
	info->comp.max_i = info->comp.min_i
		+ (info->comp.max_r - info->comp.min_r) * HEIGHT / WIDTH;
	y = -1;
	while (y++ < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			info->comp.cr = info->comp.min_r
				+ (double)x * (info->comp.max_r - info->comp.min_r) / WIDTH;
			info->comp.ci = info->comp.min_i
				+ (double)y * (info->comp.max_i - info->comp.min_i) / HEIGHT;
			calc(info, x, y);
		}
	}
	mlx_put_image_to_window(info->mlx_ptr, info->window, info->mlx_img, 0, 0);
}
