/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:11:16 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 16:03:38 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_fdf *a)
{
	t_p	p0;
	t_p	p1;

	p0.y = a->map->y - 1;
	p1.y = a->map->y - 1;
	while (p1.y >= 0)
	{
		p0.x = a->map->x - 2;
 		p1.x = a->map->x - 2;
		while (--p1.x > -2)
		{
			draw_line((p0.x * 30) + 10, (p0.y * 30) + 10, (p1.x * 30) + 10, (p1.y * 30) + 10, 0xFFFFFF, a);
			//printf("x0 : %d, y0 : %d, x1 : %d, y1 : %d \n", p0.x, p0.y, p1.x, p1.y);
			p0.x--;
		}
		p0.y--;
		p1.y--;
	}
	p1.x++;
	while (p1.x < a->map->x)
	{
		p0.y = 0;
 		p1.y = 0;
		while (++p1.y < a->map->y)
		{
			draw_line((p0.x * 30) + 10, (p0.y * 30) + 10, (p1.x * 30) + 10, (p1.y * 30) + 10, 0xFFFFFF, a);
			p0.y++;
		}
		p0.x++;
		p1.x++;
	}
}
void	image(t_fdf *a)
{
	a->img_ptr = mlx_new_image(a->mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	a->i_addr = mlx_get_data_addr(a->img_ptr, &a->i_bpp, &a->i_size_line, &a->i_endian);
	draw_map(a);
	//draw_line(230, 300, 400, 600, 0xFFFFFF, a);
	mlx_put_image_to_window(a->mlx_ptr, a->win_ptr, a->img_ptr, MENU_WIDTH, 0);
}
