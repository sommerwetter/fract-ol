/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:59 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/15 15:08:20 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_p(int color, int x, int y, t_img *img)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

/*int	deal_key(int key, t_info	*info)
{
	static int x;

	if (key == 30)
	{
		if (x % 2 == 0)
		{
			ft_putnbr_fd(info->img.line_len, 1);
			put_p(0xFFFFFF, x++, 300, &info->img);
		}
		else
		{
			ft_putnbr_fd(key, 1);
			x++;
		}
	}
	mlx_put_image_to_window(info->mlx_ptr, info->window, info->mlx_img, 0, 0);
	return (0);
}*/

int	main()
{
	t_info info;
	int		x;
	int		y;
	/*double	min_x = -2.0;
	double	max_x = 1.0;
	double	min_i = -1.5;
	double	max_i = min_i + (max_x - min_x) * HEIGHT / WIDTH;*/
	int		tmp;

	x = 150;
	y = 150;
	tmp = x;
	init_info(&info);
	info.mlx_ptr = mlx_init();
	info.window = mlx_new_window(info.mlx_ptr, WIDTH, HEIGHT, "test");
	info.mlx_img = mlx_new_image(info.mlx_ptr, WIDTH, HEIGHT);
	info.img.addr = mlx_get_data_addr(info.mlx_img, &info.img.bpp, &info.img.line_len, &info.img.endian);
	ft_putnbr_fd(info.img.line_len, 1);
	//index = info.img.line_len * HEIGHT + WIDTH * (info.img.bpp / 8);
	while (x <= (tmp + 100))
		put_p(0xFFFFFF, x++, y, &info.img);
	x -= 101;
	tmp = y;
	while (y <= (tmp + 100))
		put_p(0xFFFFFF, x, y++, &info.img);
	tmp = x;
	while (x <= (tmp + 100))
		put_p(0xFFFFFF, x++, y, &info.img);
	tmp = y;
	while (y >= (tmp - 101))
		put_p(0xFFFFFF, x, y--, &info.img);
	//mlx_key_hook(info.window, deal_key, &info);
	mlx_put_image_to_window(info.mlx_ptr, info.window, info.mlx_img, 0, 0);
	mlx_loop(info.mlx_ptr);
	return (0);
}

/*static void	argCheck(char)
{
	
}

int main(int ac, char **av)
{
	
}*/

/*
	(Run make in mlx)
	gcc -g -Wall -Werror -Wextra -Imlx -c fractol.c -o fractol.o && gcc -g -Wall -Werror -Wextra -Imlx -c utils.c -o utils.o && gcc fractol.o utils.o -g -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit && ./a.out
	
*/