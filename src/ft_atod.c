/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:45:13 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/21 23:35:51 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	double	check_sign(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		return (-1.0);
	return (1.0);
}

static	int	find_start(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] == '-' || str[n] == '+' || str[n] == ' ' || str[n] == '\n'
		|| str[n] == '\f' || str[n] == '\r' || str[n] == '\t' || str[n] == '\v')
	{
		if ((str[n] == '-' || str[n] == '+') && !ft_isdigit(str[n + 1]))
			return (-1);
		n++;
	}
	return (n);
}
 /*
	Have to fix value if there is a zero between numbers
 */
double	ft_atod(const char *str)
{
	int		x;
	double	nbr;
	double	result;
	int		count;

	nbr = 0.0;
	result = 0.0;
	count = -1;
	x = find_start(str);
	if (x == -1)
		return (0);
	while (ft_isdigit(str[x]))
	{
		nbr = str[x] - '0';
		result = (result * 10.0) + nbr;
		x++;
		if (str[x] == '.')
			x++;
		count++;
	}
	while (count > 0)
	{
		result /= 10;
		count--;
	}
	return (check_sign(str) * result);
}

//make && ./fractol j -0.766667 -1.300 228 255 0