/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/09 17:54:17 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double		ft_abs_double(double n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

double		d_power(double nb, int power)
{
	int		i;
	double	ret;

	if (power == 0)
		return (1);
	i = 1;
	ret = nb;
	while (i != power)
	{
		ret *= nb;
		i++;
	}
	return (ret);
}
