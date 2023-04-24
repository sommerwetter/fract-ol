/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:59 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/24 23:27:53 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
	Setsup the Window
	make re && ./fractol m 255 255 0
	make re && ./fractol j 0.285 0.01 0 255 255
	norminette src && norminette libft && norminette includes 
*/
static void	setup_win(t_info *info)
{
	info->mlx_ptr = mlx_init();
	info->window = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	info->mlx_img = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT);
	info->img.addr = mlx_get_data_addr(info->mlx_img, &info->img.bpp,
			&info->img.line_len, &info->img.endian);
	mlx_key_hook(info->window, lisener, info);
	mlx_mouse_hook(info->window, zoom, info);
	mlx_hook(info->window, 17, 0, exit_ac, info);
}

/*
	Manages which fractal to render
*/
static void	render(t_info *info)
{
	if (info->type == 1)
	{
		setup_win(info);
		draw(info);
	}
	if (info->type == 2)
	{
		setup_win(info);
		draw(info);
	}
}

/*
	Input parser
*/
static int	check(t_info *info, char **av, int ac)
{
	init_info(info);
	if (!ft_strncmp(av[1], "m", 1) && ac == 5)
	{
		info->type = 1;
		info->color.r = ft_atoi(av[2]);
		info->color.g = ft_atoi(av[3]);
		info->color.b = ft_atoi(av[4]);
		return (0);
	}
	if (!ft_strncmp(av[1], "j", 1) && ac == 7)
	{
		info->type = 2;
		info->max_r = 2.0;
		info->min_i = -2.0;
		info->max_i = 2.0;
		info->k.r = ft_atod(av[2]);
		info->k.i = ft_atod(av[3]);
		info->color.r = ft_atoi(av[4]);
		info->color.g = ft_atoi(av[5]);
		info->color.b = ft_atoi(av[6]);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 5)
	{
		ft_putendl_fd("Wrong input\ne.g"
			"./fractol fractal(m or j) color(r g b)", 1);
		return (1);
	}
	if (check(&info, av, ac))
	{
		ft_putendl_fd("Wrong input\ne.g"
			"./fractol fractal(m or j) color(r g b)", 1);
		return (1);
	}
	render(&info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
