/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:40:56 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/15 15:09:02 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_info(t_info *info)
{
	info->mlx_ptr = NULL;
	info->window = NULL;
	info->mlx_img = NULL;
	info->set = -1;
	info->min_r = 0;
	info->max_r = 0;
	info->min_i = 0;
	info->max_i = 0;
	init_img(&info->img);
}

void	init_img(t_img *img)
{
	img->addr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->line_len = 0;
}
