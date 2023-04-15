/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:33:06 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/15 21:06:01 by marmoral         ###   ########.fr       */
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

typedef struct	s_img
{
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_img;

typedef struct	s_complex
{
	double	cr;
	double	ci;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
}t_complex;

typedef struct s_info
{
	void		*mlx_ptr;
	void		*window;
	void		*mlx_img;
	int			type;
	int			set;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	t_img		img;
	t_complex	comp;
}t_info;

void	init_info(t_info *info);
void	init_img(t_img *img);
void	mandelbrot(t_info *info);
void	julia(t_info *info);
void	put_p(int color, int x, int y, t_img *img);

#endif