/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:04:28 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/21 22:20:29 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf *a)
{
	if (key == ESC)
	{
		mlx_destroy_window(a->mlx_ptr, a->win_ptr);
		free(a);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	exit_button(t_fdf *a)
{
	mlx_destroy_window(a->mlx_ptr, a->win_ptr);
	free(a);
	exit(EXIT_SUCCESS);
}

void	deal_hook(t_fdf *a)
{
	mlx_hook(a->win_ptr, EXIT_BUTTON, 0, exit_button, a);
	mlx_key_hook(a->win_ptr, deal_key, a);
	mlx_loop(a->mlx_ptr);
}
