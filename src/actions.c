/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:59:55 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/23 21:41:17 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	exit_key(int key, t_info *info)
{
	ft_putnbr_fd(key, 1);
	if (key == K_ESC)
	{
		mlx_destroy_image(info->mlx_ptr, info->mlx_img);
		mlx_destroy_window(info->mlx_ptr, info->window);
		exit(0);
	}
	if (key == 30) //zoom in
	{
		double	center_i;
		double	center_r;

		center_i = info->max_i - info->min_i;
		center_r = (info->min_r - info->max_r);
		info->min_r = info->max_r + 0.5 * center_r;
		info->max_r = info->max_r + (center_r - 0.5 * center_r) / 2;
		info->max_i = info->min_i + 0.5 * center_i;
		info->min_i = info->min_i + (center_i - 0.5 * center_i) / 2;
		draw(info);
	}
	if (key == 44) // zoom out
	{
		double	center_i;
		double	center_r;

		center_i = info->max_i - info->min_i;
		center_r = (info->min_r - info->max_r);
		info->min_r = info->max_r + 2 * center_r;
		info->max_r = info->max_r + (center_r - 2 * center_r) / 2;
		info->max_i = info->min_i + 2 * center_i;
		info->min_i = info->min_i + (center_i - 2 * center_i) / 2;
		draw(info);
	}
	if (key == 124)// right 124 left 123
	{
		double	center;

		center = (info->min_r - info->max_r);
		info->min_r = info->min_r - (center * 0.05);
		info->max_r = info->max_r - (center * 0.05);
		draw(info);
	}
	if (key == 123)
	{
		double	center;

		center = (info->min_r - info->max_r);
		info->min_r = info->min_r + (center * 0.05);
		info->max_r = info->max_r + (center * 0.05);
		draw(info);
	}
	return (0);
}

int	zoom(int key, t_info *info)
{
	if (key == 30)
	{
		info->min_r += 1;
		info->max_r -= 1;
		info->min_i += 1.5;
		draw(info);
	}
	return (0);
}