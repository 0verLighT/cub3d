/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 02:11:15 by amartel           #+#    #+#             */
/*   Updated: 2026/04/29 05:22:16 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d/parser.h"

char *get_line_from_id(char *id, char *file)
{
	char *line;
	int fd;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		if (ft_strncmp(line, id, ft_strlen(id)) == 0)
			return (line);
		free(line);
	}
}

int	*char_to_color(char *c)
{
	int		*color;
	char	*str;

	color = ft_calloc(3, sizeof(int));
	str = ft_substr(c, 0, 3);
	color[0] = ft_atoi(str);
	str = ft_substr(c, 4, 3);
	color[1] = ft_atoi(str);
	str = ft_substr(c, 8, 3);
	color[2] = ft_atoi(str);
	free(c);
	return (color);
}

t_config	*load_texture(char *filename)
{
	t_config	*config;

	config = ft_calloc(1, sizeof(t_config));
	config->no = get_line_from_id("NO", filename);
	config->so = get_line_from_id("SO", filename);
	config->we = get_line_from_id("WE", filename);
	config->ea = get_line_from_id("EA", filename);
	config->f = char_to_color(get_line_from_id("F", filename));
	config->c = char_to_color(get_line_from_id("C", filename));
	return (config);
}

int	check_color(int *c)
{
	if (c[0] > 255 || c[0] < 0)
		return (1);
	if (c[1] > 255 || c[1] < 0)
		return (1);
	if (c[2] > 255 || c[2] < 0)
		return (1);
	return (0);
}

int	file_exist(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	close(fd);
	return (0);
}

int	check_config(t_config *config)
{
	if (check_color(config->c) || check_color(config->f))
		return (1);
	if (file_exist(config->no) || file_exist(config->so) || file_exist(config->we) || file_exist(config->ea))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_config	*config;
	if (ac != 2)
	{
		printf("Error, wrong number of argumets\n");
		return (1);
	}
	ft_valid_path(av[1]);
	config = load_texture(av[1]);
	if (check_config(config))
		return 1;
	return (0);
}
