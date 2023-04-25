/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:45:13 by marmoral          #+#    #+#             */
/*   Updated: 2023/04/25 20:45:34 by marmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	check_sign(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-1);
	return (1);
}

static int	find_start(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i] == '+'
		|| str[i] == '-')
		i++;
	return (i);
}

double	ft_atod(char *str)
{
	int		i;
	double	nb;
	double	div;

	nb = 0;
	div = 0.1;
	i = find_start(str);
	if (!ft_isdigit(str[i]))
		return (1);
	while (ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (1);
	while (ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	return (nb * check_sign(str));
}

//make && ./fractol j -0.766667 -1.300 228 255 0