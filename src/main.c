/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:18:00 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/22 11:28:46 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	t_fdf	*a;
	a = malloc(sizeof(t_fdf));
	a->mlx_ptr = mlx_init();
	a->win_ptr = mlx_new_window(a->mlx_ptr, WIN_WIDTH, WIN_HEIGTH, "FDF");
	menu(a);
	image(a);
	deal_hook(a);
}
