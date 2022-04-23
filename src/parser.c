/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:04:17 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 19:35:46 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../Libft/incl/libft.h"

void	get_size(t_fdf *a, char *f_path)
{
	int 	fd;
	char 	*line;

	fd = open(f_path, O_RDONLY);
	a->map->x = 0;
	a->map->y = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("File empty\n", 2);
		exit(EXIT_FAILURE);
	}
	a->map->x = ft_strlen(*ft_split(line, ' '));
	while (line)
	{
		line = get_next_line(fd);
		a->map->y++;
	}
}

void	double_malloc(t_fdf *a)
{
	int		i;
	int		j;

	i = a->map->x;
	j = a->map->y;
	a->map->line = malloc((j + 1) * sizeof(char*));
	if (a->map->line == NULL)
	{
		ft_putstr_fd("malloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	j = 0;
	while (a->map->line[j])
	{
		a->map->line[j] = malloc((i + 1) * sizeof(char));
		j++;
	}
}

void	load_line(t_fdf *a, char *f_path)
{
	int 	fd;
	int		i;
	int		j;
	char	*line;
	char	**tab;

	i = 0;
	j = 0;
	fd = open(f_path, O_RDONLY);
	line = get_next_line(fd);
	tab = ft_split(line, ' ');
	while (tab[i][0])
	{
		a->line[]
	}
	while (j < a->map->y)
	{
		i++;
		line = get_next_line(fd);
		a->map->line[i] = *ft_split(line, ' ');
		j++;
	}
	
}

void	init_map(t_fdf *a, char *f_path)
{
	get_size(a, f_path);
	double_malloc(a);
	load_line(a, f_path);
	int i = 0;
	while (i < 11)
	{   
		printf("%c \n", a->map->line[i][5]);
		i++;
	}
}
