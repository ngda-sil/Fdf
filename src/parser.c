/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:04:17 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/04 19:39:27 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../Libft/incl/libft.h"

void	get_size(t_fdf *a, char *f_path)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(f_path, O_RDONLY);
	if (fd == -1)
		ft_exit_simple("Problem opening file\n");
	a->map.x = 0;
	a->map.y = 0;
	line = get_next_line(fd);
	if (!line)
		ft_exit_simple("File empty\n");
	tab = ft_split(line, ' ');
	while (tab[a->map.x])
		a->map.x++;
	ft_double_free(tab);
	while (line)
	{
		line = get_next_line(fd);
		a->map.y++;
	}
	free(line);
	close(fd);
}

void	double_malloc(t_fdf *a)
{
	int		i;

	i = a->map.y;
	a->map.coord = malloc((i) * sizeof(t_p *));
	if (!a->map.coord)
		ft_exit_simple("Problem malloc coord 1\n");
	i = -1;
	while (++i < a->map.y)
	{
		a->map.coord[i] = malloc((a->map.x) * sizeof(t_p));
		if (!a->map.coord[i])
			ft_exit_free("Problem malloc coord 2\n", a);
	}
}

void	load_coord(t_fdf *a, char *f_path)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**tab;

	//i = -1;
	j = 0;
	fd = open(f_path, O_RDONLY);
	if (fd == -1)
		ft_exit_free("Problem opening file\n", a);
	/*line = get_next_line(fd);
	tab = ft_split(line, ' ');
	while (++i < a->map.x)
		a->map.coord[j][i].z = ft_atoi(tab[i]);*/
	while (++j < a->map.y)
	{
		i = -1;
		line = get_next_line(fd);
		tab = ft_split(line, ' ');
		while (++i < a->map.x)
			a->map.coord[j][i].z = ft_atoi(tab[i]);
	}
	ft_double_free(tab);
	free(line);
	close(fd);
}

void	init_map(t_fdf *a, char *f_path)
{
	get_size(a, f_path);
	double_malloc(a);
	load_coord(a, f_path);
}
