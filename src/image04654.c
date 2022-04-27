/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:11:16 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/25 22:14:28 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_p	iso(t_p *p)
{
	int p_x;
	int p_y;

	p_x = p->x;
	p_y = p->y;
	p->x = (p_x + p_y) * tan(0.523598775);
	p->y = (p_y + 1);
	return(*p);	
}

void	draw_map(t_fdf *a)
{
	(void) a;
	t_p	p0;
	t_p	p1;
	int	unit;

	/*if (a->map->x > a->map->y)
		unit = WIN_HEIGTH / a->map->x;
	else
		unit = WIN_HEIGTH / a->map->y;*/
	unit = 50;
	p0.y = 0;
	p1.y = 0;
	int i = 0;
	int j = 0;
	while ( j <= 10)
	{
		p0.x = 0;
 		p1.x = 1;
		i = 0;
		while (i <= 10)
		{
		
			draw_line(((p0.x - p0.y) * unit * cos(0.523599)) + 500, ((p0.x + p0.y) * (unit/2) * sin(0.523599)) + 500, ((p1.x - p1.y) * (unit) * cos(0.523599)) + 500, ((p1.x + p1.y) * (unit/2) * sin(0.523599)) + 500, 0xFFFFFF, a);
			p0.x++;
			p1.x++;
			i++;
		}
		p0.y++;
		p1.y++;
		j++;
	}
	i = 0;
   	j = 0;
	while ( j <= 10)
	{
		p0.x = 0;
 		p1.x = 1;
		i = 0;
		while (i <= 10)
		{
		
			draw_line(((p0.x - p0.y) * unit * cos(0.523599)) + 500, ((p0.x + p0.y) * (unit/2) * sin(0.523599)) + 500, ((p1.x - p1.y) * (unit) * cos(0.523599)) + 500, ((p1.x + p1.y) * (unit/2) * sin(0.523599)) + 500, 0xFFFFFF, a);
			p0.x--;
			p1.x--;
			i++;
		}
		p0.y++;
		p1.y++;
		j++;
	}	
}

void	image(t_fdf *a)
{
	a->img_ptr = mlx_new_image(a->mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	a->i_addr = mlx_get_data_addr(a->img_ptr, &a->i_bpp, &a->i_size_line, &a->i_endian);
	draw_map(a);
	mlx_put_image_to_window(a->mlx_ptr, a->win_ptr, a->img_ptr, MENU_WIDTH, 0);
}
