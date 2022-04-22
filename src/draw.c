/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:39:00 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/22 12:26:42 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *a, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y < WIN_HEIGTH && y >= 0)
		*(int *)&a->i_addr[(y * a->i_size_line) + (x * (a->i_bpp / 8))] = color;
}

void	draw_line(int x1, int y1, int x2, int y2, int color, t_fdf *a)
{
	int	dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dx = x2 - x1;
	dy = y2 - y1;
	sx = -1;
	sy = -1;
	if (dx < 0)
		dx *= -1;
	if (dy > 0)
		dy *= -1;
	if (x1 < x2)
		sx = 1;
	if (y1 < y2)
		sy = 1;
	err = dx + dy;
	e2 = 2 * err;
	while (1)
	{
		put_pixel(a, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break;
		if ( e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}
		if ( e2 * err <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}
