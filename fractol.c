/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:59 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/08 20:44:25 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_p(int color, int x, int y, t_img *img)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	main()
{
	t_info info;
	t_img	img;
	int		x;
	int		y;
	int		tmp;

	x = 150;
	y = 150;
	tmp = x;
	init_info(&info);
	init_img(&img);
	info.mlx_ptr = mlx_init();
	info.window = mlx_new_window(info.mlx_ptr, WIDTH, HEIGHT, "test");
	info.mlx_img = mlx_new_image(info.mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(info.mlx_img, &img.bpp, &img.line_len, &img.endian);
	//ft_putnbr_fd(img->line_len, 1);
	//index = img->line_len * HEIGHT + WIDTH * (img->bpp / 8);
	while (x <= (tmp + 100))
		put_p(0xFFFFFF, x++, y, &img);
	x -= 101;
	tmp = y;
	while (y <= (tmp + 100))
		put_p(0xFFFFFF, x, y++, &img);
	tmp = x;
	while (x <= (tmp + 100))
		put_p(0xFFFFFF, x++, y, &img);
	tmp = y;
	while (y >= (tmp - 101))
		put_p(0xFFFFFF, x, y--, &img);
	//mlx_key_hook(info->window, deal_key, info);
	mlx_put_image_to_window(info.mlx_ptr, info.window, info.mlx_img, 0, 0);
	mlx_loop(info.mlx_ptr);
	return (0);
}

/*
	(Run make in mlx)
	gcc -g -Wall -Werror -Wextra -Imlx -c fractol.c -o fractol.o && gcc -g -Wall -Werror -Wextra -Imlx -c utils.c -o utils.o && gcc fractol.o utils.o -g -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit && ./a.out
	
*/