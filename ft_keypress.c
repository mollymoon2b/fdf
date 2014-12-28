/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 13:21:10 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/12/28 14:28:02 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_colorchoice3(t_env *e, int keycode)
{
	if (keycode == 121 && (e->y = 0xcc))
	{
		e->b = 0;
		e->g = 0xff;
		e->r = 0xff;
	}
	if (keycode == 103 && (e->g = 0xcc))
	{
		e->r = 0x00;
		e->b = 0x00;
		e->g = 0xff;
	}
	ft_draw(e);
}

void		ft_colorchoice2(t_env *e, int keycode)
{
	if (keycode == 98 && (e->b = 0xe9))
	{
		e->r = 0x00;
		e->g = 0x00;
		e->b = 0xff;
	}
	if (keycode == 99 && (e->c = 0xcc))
	{
		e->r = 66;
		e->b = 0;
		e->g = 33;
	}
	ft_draw(e);
}

void		ft_colorchoice(t_env *e, int keycode)
{
	if (keycode == 32 || keycode == 100)
	{
		e->r = 0xcc;
		e->g = 0xcc;
		e->b = 0xcc;
		e->y = 0xcc;
		e->p = 0xcc;
	}
	if (keycode == 114 && (e->r = 0xcc))
	{
		e->g = 0;
		e->b = 0;
	}
	if (keycode == 112 && (e->p = 0xcc))
	{
		e->g = 0;
		e->b = 99;
		e->r = 0xff;
	}
	ft_draw(e);
}

int			ft_exposehook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int			ft_keypress(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 112 || keycode == 114 || keycode == 100)
		ft_colorchoice(e, keycode);
	if (keycode == 99 || keycode == 98)
		ft_colorchoice2(e, keycode);
	if (keycode == 121 || keycode == 103)
		ft_colorchoice3(e, keycode);
	ft_draw(e);
	return (0);
}
