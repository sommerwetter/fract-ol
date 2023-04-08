/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:33:06 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/08 20:36:56 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

/*	size */
# define WIDTH 900
# define HEIGHT 900

typedef struct s_info
{
	void	*mlx_ptr;
	void	*window;
	void	*mlx_img;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
}t_info;

typedef struct	s_img
{
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_img;

void	init_info(t_info *info);
void	init_img( t_img *img);
void	ft_putnbr_fd(int nb, int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);


#endif