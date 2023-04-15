/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:40:56 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/15 19:29:45 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_info(t_info *info)
{
	info->mlx_ptr = NULL;
	info->window = NULL;
	info->mlx_img = NULL;
	info->type = 0;
	info->set = -1;
	info->min_r = 0;
	info->max_r = 0;
	info->min_i = 0;
	info->max_i = 0;
	info->img.addr = NULL;
	info->img.bpp = 0;
	info->img.endian = 0;
	info->img.line_len = 0;
	info->comp.cr = 0.0;
	info->comp.ci = 0.0;
	info->comp.min_r = 0.0;
	info->comp.max_r = 0.0;
	info->comp.min_i = 0.0;
	info->comp.max_i = 0.0;
}

void	init_img(t_img *img)
{
	img->addr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->line_len = 0;
}

void	put_p(int color, int x, int y, t_img *img)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}