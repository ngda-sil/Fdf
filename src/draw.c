/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:39:00 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/10 19:42:58 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *a, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y < WIN_HEIGTH && y >= 0)
		*(int *)&a->i_addr[(y * a->i_size_line) + (x * (a->i_bpp / 8))] = color;
}

int	sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

int	ft_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

void	init_s_and_counter(t_draw *d, t_p p1, t_p p2)
{
	if (p1.x < p2.x)
		d->sx = 1;
	else
		d->sx = -1;
	if (p1.y < p2.y)
		d->sy = 1;
	else
		d->sy = -1;
	if (d->x > d->y)
		d->counter = d->x / 2;
	else
		d->counter = -(d->y / 2);
}

void	draw_line(t_p p1, t_p p2, t_fdf *a)
{
	t_draw	d;

	d.x = ft_abs(p2.x - p1.x);
	d.y = ft_abs(p2.y - p1.y);
	init_s_and_counter(&d, p1, p2);
	while (1)
	{
		put_pixel(a, p1.x, p1.y, BLUE);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		d.e = d.counter;
		if (d.e > d.x * -1)
		{
			d.counter -= d.y;
			p1.x += d.sx;
		}
		if (d.e < d.y)
		{
			d.counter += d.x;
			p1.y += d.sy;
		}
	}
}
