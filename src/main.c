/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:18:00 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 19:33:20 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*a;

	if (ac != 2)
	{
		ft_putstr_fd("error nb args\n", 2);
		return (0);
	}
	a = malloc(sizeof(t_fdf));
	a->map = malloc(sizeof(t_map));
	init_map(a, av[1]);
	a->mlx_ptr = mlx_init();
	a->win_ptr = mlx_new_window(a->mlx_ptr, WIN_WIDTH, WIN_HEIGTH, "FDF");
	menu(a);
	image(a);
	deal_hook(a);
}
