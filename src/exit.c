/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:11:38 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/04 19:37:05 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_double_free_tp(t_p **coord)
{
	int	i;

	i = 0;
	while (coord[i])
	{
		free(coord[i++]);
	}
	free(coord);
}

void	ft_exit_simple(char *s)
{
	ft_putstr_fd(s, 2);
	exit (EXIT_FAILURE);
}

void	ft_exit_free(char *s, t_fdf *a)
{
	if (a->map.coord)
		ft_double_free_tp(a->map.coord);
	if (a->map.iso)
		ft_double_free_tp(a->map.iso);
	ft_putstr_fd(s, 2);
	exit (EXIT_FAILURE);
}
