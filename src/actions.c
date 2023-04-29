/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:59:55 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/29 12:03:35 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	Exiting the program safely.
*/
int	exit_ac(t_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->mlx_img);
	mlx_destroy_window(info->mlx_ptr, info->window);
	exit(0);
}

/*
	Modifies the edge values by 0.5x(zooms) and 2x(zooms out) and
	redraws the fractal.
*/
int	zoom(int key, int x, int y, t_info *info)
{
	double	center_i;
	double	center_r;
	double	z;

	(void) x;
	(void) y;
	center_i = info->max_i - info->min_i;
	center_r = (info->min_r - info->max_r);
	z = 0.0;
	if (key == K_PLUS || key == MWDOWN)
		z = 0.8;
	else if (key == K_MINUS || key == MWUP)
		z = 1.3;
	else
		return (0);
	info->min_r = info->max_r + (z * center_r);
	info->max_r = info->max_r + (center_r - (z * center_r)) / 2;
	info->max_i = info->min_i + (z * center_i);
	info->min_i = info->min_i + (center_i - (z * center_i)) / 2;
	draw(info);
	return (0);
}

/*
	Shifts x(for horizontal movement) and y(for vertical movement) edge values
	from the center of the coordinated system by 0.05 times. Then redraw the
	fractal.
*/
static void	arrows(int key, t_info *info)
{
	double	center_i;
	double	center_r;

	center_i = info->max_i - info->min_i;
	center_r = (info->min_r - info->max_r);
	if (key == R_ARROW)
	{
		info->min_r -= (center_r * 0.05);
		info->max_r -= (center_r * 0.05);
	}
	else if (key == L_ARROW)
	{
		info->min_r += (center_r * 0.05);
		info->max_r += (center_r * 0.05);
	}
	else if (key == UP_ARROW)
	{
		info->min_i -= (center_i * 0.05);
		info->max_i -= (center_i * 0.05);
	}
	else if (key == DW_ARROW)
	{
		info->min_i += (center_i * 0.05);
		info->max_i += (center_i * 0.05);
	}
}

/*
	Increases iteration value and redraws the fractal.
*/
static void	increaseit(int key, t_info *info)
{
	if (info->max_it >= 420 && key == Q_KEY)
		ft_putendl_fd("Max Iterations reached", 1);
	else
	{
		if (key == Q_KEY)
			info->max_it += 60;
		if (key == E_KEY)
			info->max_it -= 60;
		ft_putstr_fd("Iterations: ", 1);
		ft_putnbr_fd(info->max_it, 1);
		ft_putchar_fd('\n', 1);
		draw(info);
	}
}

/*
	Handles all key input actions.
*/
int	lisener(int key, t_info *info)
{
	if (key == K_ESC)
		exit_ac(info);
	else if (key == K_PLUS || key == K_MINUS)
		zoom(key, 0, 0, info);
	else if (key == R_ARROW || key == L_ARROW || key == UP_ARROW
		|| key == DW_ARROW)
	{
		arrows(key, info);
		draw(info);
	}
	else if (key == Q_KEY || key == E_KEY)
		increaseit(key, info);
	else
		return (0);
	return (0);
}
