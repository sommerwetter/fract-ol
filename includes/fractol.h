/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:33:06 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/21 23:18:35 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "keys.h"

/*	size */
# define WIDTH 900
# define HEIGHT 900
# define MAX_IT 60

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}t_color;

typedef struct	s_img
{
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_img;

typedef struct	s_complex
{
	double	r;
	double	i;
}t_complex;

typedef struct s_info
{
	void		*mlx_ptr;
	void		*window;
	void		*mlx_img;
	int			type;
	int			*palette;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	t_img		img;
	t_color		color;
	t_complex	k;
}t_info;

void	init_info(t_info *info);
void	draw(t_info *info);
void	set_palette(t_info *info, int tr, int tg, int tb);
void	put_p(int color, int x, int y, t_img *img);
double	ft_atod(const char *str);
int		mandelbrot(double cr, double ci);
int		julia(double zr, double zi, t_info *info);
int		rgb2c(int r, int g, int b);

#endif