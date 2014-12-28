/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 13:20:45 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/12/28 14:57:08 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swapptr(t_pt **a, t_pt **b)
{
	t_pt	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_draw_first_case(t_pt *a, t_pt *b, t_env *e)
{
	double	x;

	x = a->x_2d;
	while (x < b->x_2d)
	{
		ft_putpixel(x, a->y_2d + ((b->y_2d - a->y_2d) * (x - a->x_2d))
					/ (b->x_2d - a->x_2d), e);
		++x;
	}
}

void	ft_draw_second_case(t_pt *a, t_pt *b, t_env *e)
{
	double	y;

	y = a->y_2d;
	while (y < b->y_2d)
	{
		ft_putpixel(a->x_2d + ((b->x_2d - a->x_2d) * (y - a->y_2d))
					/ (b->y_2d - a->y_2d), y, e);
		++y;
	}
}

void	ft_drawline(t_pt *a, t_pt *b, t_env *e)
{
	if (ABS(b->x_2d - a->x_2d) > ABS(b->y_2d - a->y_2d))
	{
		if (a->x_2d >= b->x_2d)
			ft_swapptr(&a, &b);
		ft_draw_first_case(a, b, e);
	}
	else
	{
		if (a->y_2d >= b->y_2d)
			ft_swapptr(&a, &b);
		ft_draw_second_case(a, b, e);
	}
}
