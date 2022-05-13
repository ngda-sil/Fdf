/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:04:28 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/13 15:21:36 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf *a)
{
	if (key == ESC)
	{
		mlx_destroy_window(a->mlx_ptr, a->win_ptr);
		if (a->map.coord)
			ft_double_free_tp(a->map.coord);
		if (a->map.iso)
			ft_double_free_tp(a->map.iso);
		exit(EXIT_SUCCESS);
	}
	if (key == LEFT)
		a->map.y0 -= 20;
	if (key == RIGHT)
		a->map.y0 += 20;
	if (key == UP)
		a->map.x0 -= 20;
	if (key == DOWN)
		a->map.x0 += 20;
	if (key == Z_UP)
		a->map.z_unit += 1;
	if (key == Z_DWN)
		a->map.z_unit -= 1;
	image(a);
	return (0);
}

int	deal_mouse(int button, int x, int y, t_fdf *a)
{
	(void) x;
	(void) y;
	if (button == SCROLL_UP)
		a->map.unit += 1;
	if (button == SCROLL_DWN && a->map.unit > 0)
		a->map.unit -= 1;
	image(a);
	return (0);
}

int	exit_button(t_fdf *a)
{
	mlx_destroy_window(a->mlx_ptr, a->win_ptr);
	if (a->map.coord)
		ft_double_free_tp(a->map.coord);
	if (a->map.iso)
		ft_double_free_tp(a->map.iso);
	exit(EXIT_SUCCESS);
}

void	deal_hook(t_fdf *a)
{
	mlx_hook(a->win_ptr, EXIT_BUTTON, 0, exit_button, a);
	mlx_key_hook(a->win_ptr, deal_key, a);
	mlx_mouse_hook(a->win_ptr, deal_mouse, a);
	mlx_loop(a->mlx_ptr);
}
