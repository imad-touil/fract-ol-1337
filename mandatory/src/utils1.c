/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:02:37 by imatouil          #+#    #+#             */
/*   Updated: 2025/03/22 01:04:23 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	check_double(char *str, int i)
{
	if (str[i])
	{
		ft_putstr("Invalid Args\n");
		exit(1);
	}
}

double	ft_atof(char *str)
{
	double	res;
	double	dec;
	int		i;
	int		s;

	res = 0.0;
	dec = 0.1;
	i = 0;
	s = 1;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
		res = res * 10 + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res += (str[i++] - '0') * dec;
		dec /= 10;
	}
	check_double(str, i);
	return (res * s);
}
