/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:39:00 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/27 15:08:08 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *a, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y < WIN_HEIGTH && y >= 0)
	{
		*(int *)&a->i_addr[(y * a->i_size_line) + (x * (a->i_bpp / 8))] = color;
		//printf(" x %d y %d i_addr %d\n", x, y, color);
	}
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

void	draw_line(t_p p1, t_p p2, int color, t_fdf *a)
{
	int	x;
	int	y;
	int	sx;
	int	sy;
	int	counter;
	int	e;

	x = abs(p2.x - p1.x);
	y = abs(p2.y - p1.y);
	if (p1.x < p2.x)
		sx = 1;
	else
		sx = -1;
	if (p1.y < p2.y)
		sy = 1;
	else
		sy = -1;
	if (x > y)
		counter = x / 2;
	else
		counter = -(y / 2);
	while (1)
	{
		put_pixel(a, p1.x, p1.y, color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e = counter;
		if (e > -x)
		{
			counter = counter - y;
			p1.x = p1.x + sx;
		}
		if (e < y)
		{
			counter = counter + x;
			p1.y = p1.y + sy;
		}
	}
}
