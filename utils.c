/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:40:56 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/08 20:33:12 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((count == SIZE_MAX && size > 1)
		|| (size == SIZE_MAX && count > 1))
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

static	long	reversenbr(int nb)
{
	int		b;
	long	r;
	long	nb2;

	r = 0;
	b = 0;
	nb2 = nb;
	if (nb2 < 0)
		nb2 *= -1;
	while (nb2 > 0)
	{
		b = (nb2 % 10);
		r = r * 10 + b;
		nb2 /= 10;
	}
	return (r);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int			b;
	long		a;

	a = reversenbr(nb);
	b = 0;
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
		write(fd, "-", 1);
	while (a > 0)
	{
		b = (a % 10) + '0';
		write (fd, &b, 1);
		a /= 10;
	}
	while ((nb % 10) == 0 && nb != 0)
	{
		write(fd, "0", 1);
		nb = nb / 10;
	}
}

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
}

void	init_img(t_img *img)
{
	img->addr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->line_len = 0;
}
