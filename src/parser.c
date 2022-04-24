/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:04:17 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 21:27:34 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../Libft/incl/libft.h"

void	get_size(t_fdf *a, char *f_path)
{
	int 	fd;
	char 	*line;
	char	**tab;

	fd = open(f_path, O_RDONLY);
	a->map->x = 0;
	a->map->y = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("File empty\n", 2);
		exit(EXIT_FAILURE);
	}
	tab = ft_split(line, ' ');
	while (tab[a->map->x])
	{
		a->map->x++;
	}
	while (line)
	{
		line = get_next_line(fd);
		a->map->y++;
	}
}

void	double_malloc(t_fdf *a)
{
	int		i;

	i = a->map->y;
	a->map->coord = malloc((i + 1) * sizeof(int*));
	if (!a->map->coord)
	{
		ft_putstr_fd("malloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < a->map->y)
		a->map->coord[i] = malloc((a->map->x + 1) * sizeof(int));
}

void	load_coord(t_fdf *a, char *f_path)
{
	int 	fd;
	int	i;
	int	j;
	char	*line;
	char	**tab;

	i = -1;
	j = 0;
	fd = open(f_path, O_RDONLY);
	line = get_next_line(fd);
	tab = ft_split(line, ' ');
	while (++i < a->map->x)
		a->map->coord[j][i] = ft_atoi(tab[i]);
	while (++j < a->map->y)
	{
		i = -1;
		line = get_next_line(fd);
		tab = ft_split(line, ' ');
		while (++i < a->map->x)
			a->map->coord[j][i] = ft_atoi(tab[i]);
	}
}

void	init_map(t_fdf *a, char *f_path)
{
	get_size(a, f_path);
	double_malloc(a);
	load_coord(a, f_path);
}
