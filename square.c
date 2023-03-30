/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:55:57 by marmoral          #+#    #+#             */
/*   Updated: 2023/03/30 11:33:45 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

/*
	this draws a square
*/
int	main()
{
	void	*mlx_ptr;
	void	*window;
	int		tmp;
	int		x;
	int		y;

	x = 150;
	y = 150;
	tmp = x;
	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 500, 500, "test");
	while (x <= (tmp + 100))
		mlx_pixel_put(mlx_ptr, window, x++, y, 0xFFFFFF);
	x -= 101;
	tmp = y;
	while (y <= (tmp + 100))
		mlx_pixel_put(mlx_ptr, window, x, y++, 0xFFFFFF);
	tmp = x;
	while (x <= (tmp + 100))
		mlx_pixel_put(mlx_ptr, window, x++, y, 0xFFFFFF);
	tmp = y;
	while (y >= (tmp - 101))
		mlx_pixel_put(mlx_ptr, window, x, y--, 0xFFFFFF);
	mlx_loop(mlx_ptr);
	return (0);
}

/*
	(Run make in mlx)
	gcc -g -Wall -Werror -Wextra -Imlx -c square.c -o square.o && gcc square.o -g -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit && ./a.out
	
*/
