/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:40:56 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/22 00:28:53 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	Initializes the structure
*/
void	init_info(t_info *info)
{
	info->mlx_ptr = NULL;
	info->window = NULL;
	info->mlx_img = NULL;
	info->type = 0;
	info->palette = 0;
	info->min_r = -2.0;
	info->max_r = 1.0;
	info->min_i = -1.5;
	info->max_i = info->min_i + (info->max_r - info->min_r) * HEIGHT / WIDTH;
	info->img.addr = NULL;
	info->img.bpp = 0;
	info->img.endian = 0;
	info->img.line_len = 0;
	info->color.r = 0;
	info->color.g = 0;
	info->color.b = 0;
	info->k.r = 0;
	info->k.i = 0;
}

/*
	Like mlx_put_pixel but for images
*/
void	put_p(int color, int x, int y, t_img *img)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

/*
	Turns rgb values to an int color value
*/
int	rgb2c(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

/*int	get_rgb (int color)
{
	(void) color;
	return (0);
}*/

/*
	Sets the color shade of the palette
*/
void	set_palette(t_info *info, int tr, int tg, int tb)
{
	t_color black;
	int	step_size;
	int	i;

	black.r = 0;
	black.g = 0;
	black.b = 0;
	step_size = 9;
	i = -1;
	while (++i <= MAX_IT)
	{
		black.r += step_size;
		if (black.r > tr)
			black.r = tr;
		black.g += step_size;
		if (black.g > tg)
			black.g = tg;
		black.b += step_size;
		if (black.b > tb)
			black.b = tb;
		info->palette[i] = rgb2c(black.r, black.g, black.b);
	}
	info->palette[MAX_IT + 1] = 0;
}

/*
	draws fractal, gets pixel location
*/
void	draw(t_info *info)
{
	int			x;
	int			y;
	t_complex	c;

	y = -1;
	c.r = 0;
	c.i = 0;
	x = -1;
	info->palette = ft_calloc((MAX_IT + 1), sizeof(int));
	set_palette(info, info->color.r, info->color.g, info->color.b);
	while (y++ < HEIGHT)
	{
		while (++x < WIDTH)
		{
			c.r = info->min_r + (double)x * (info->max_r - info->min_r) / WIDTH;
			c.i = info->min_i + (double)y * (info->max_i - info->min_i)
				/ HEIGHT;
			if (info->type == 1)
				put_p(info->palette[mj(c.r, c.i, info)], x, y, &info->img);
			else if (info->type == 2)
				put_p(info->palette[mj(c.r, c.i, info)], x, y, &info->img);
		}
		x = -1;
	}
	free(info->palette);
	mlx_put_image_to_window(info->mlx_ptr, info->window, info->mlx_img, 0, 0);
}
