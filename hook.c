/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:04:28 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/10 19:42:56 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 5 + 4 -
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
	if (key == 126)
		a->map.y0 -= 20;
	if (key == 125)
		a->map.y0 += 20;
	if (key == 123)
		a->map.x0 -= 20;
	if (key == 124)
		a->map.x0 += 20;
	if (key == 69)
		a->map.z_unit += 2;
	if (key == 78)
		a->map.z_unit -= 2;
	image(a);
	return (0);
}

int	deal_mouse(int button, int x, int y, t_fdf *a)
{
	(void) x;
	(void) y;
	if (button == 5)
		a->map.unit += 1;
	if (button == 4 && a->map.unit > 0)
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
