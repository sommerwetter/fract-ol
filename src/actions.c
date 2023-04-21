/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:59:55 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/22 00:00:17 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	exit_key(int key, t_info	*info)
{
	ft_putnbr_fd(key, 1);
	if (key == K_ESC)
	{
		mlx_destroy_image(info->mlx_ptr, info->mlx_img);
		mlx_destroy_window(info->mlx_ptr, info->window);
		exit(0);
	}
	mlx_put_image_to_window(info->mlx_ptr, info->window, info->mlx_img, 0, 0);
	return (0);
}