/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:11:16 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/04 19:37:10 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	proj_iso(t_fdf *a)
{
	int	i;
	int	j;
	int	unit;

	unit = WIN_HEIGTH / (a->map.y + 10);
	if (a->map.x > a->map.y)
		unit = WIN_HEIGTH / (a->map.x + 10);
	i = -1;
	a->map.iso = (t_p **)malloc(a->map.y * sizeof(t_p));
	if (!a->map.iso)
		ft_exit_free("Problem malloc iso 1\n", a);
	while (++i < a->map.y)
	{
		a->map.iso[i] = (t_p *)malloc(a->map.x * sizeof(t_p));
		if (!a->map.iso[i])
			ft_exit_free("Problem malloc iso 2\n", a);
		j = -1;
		while (++j < a->map.x)
		{
			a->map.iso[i][j].x = (WIN_HEIGTH / 2 + MENU_WIDTH) + j * cos(DEG)
				* unit - i * cos(DEG) * unit;
			a->map.iso[i][j].y = 150 + j * sin(DEG) * unit + i * sin(DEG) * unit
				- a->map.coord[i][j].z * Z_H;
			a->map.iso[i][j].z = a->map.coord[i][j].z;
		}
	}
}

void	draw_map(t_fdf *a)
{
	int	i;
	int	j;

	i = a->map.y;
	while (--i > 0)
	{
		j = a->map.x;
		while (--j > 0)
		{
			draw_line(a->map.iso[i][j], a->map.iso[i][j - 1], a);
			draw_line(a->map.iso[i][j], a->map.iso[i - 1][j], a);
		}
	}
	i = 0;
	while (i < a->map.y - 1)
	{
		j = 0;
		while (j < a->map.x - 1)
		{
			draw_line(a->map.iso[i][j], a->map.iso[i][j + 1], a);
			draw_line(a->map.iso[i][j], a->map.iso[i + 1][j], a);
			j++;
		}
		i++;
	}
}

void	image(t_fdf *a)
{
	a->img_ptr = mlx_new_image(a->mlx_ptr, WIN_WIDTH, WIN_HEIGTH);
	a->i_addr = mlx_get_data_addr(a->img_ptr, &a->i_bpp, &a->i_size_line,
			&a->i_endian);
	proj_iso(a);
	draw_map(a);
	mlx_put_image_to_window(a->mlx_ptr, a->win_ptr, a->img_ptr, MENU_WIDTH, 0);
}
