/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:51:09 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/21 23:34:19 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_fdf *a)
{
	int	x;
	int	y;

	x = MENU_WIDTH - 1;
	while (--x >= 0)
	{
		y = 0;
		while (y != WIN_HEIGTH)
			mlx_pixel_put(a->mlx_ptr, a->win_ptr, x, y++, 0x161312);
	}
	mlx_string_put(a->mlx_ptr, a->win_ptr, 100, WIN_HEIGTH / 2, 0xFFFFFF,
		"MENU");
}
