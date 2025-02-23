/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:11:29 by imatouil          #+#    #+#             */
/*   Updated: 2025/02/21 20:49:26 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.imagi * z.imagi;
	result.imagi = 2 * z.real * z.imagi;
	return (result);
}

t_complex	complex_add(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imagi = z1.imagi + z2.imagi;
	return (result);
}

double	complex_magnitude(t_complex z)
{
	double	res;

	res = sqrt(z.real * z.real + z.imagi * z.imagi);
	return (res);
}
