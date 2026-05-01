/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 05:37:44 by amartel           #+#    #+#             */
/*   Updated: 2026/05/01 07:11:07 by amartel          ###   ########.fr       */
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
	close(fd);
}

bool	char_to_color(char *c, int *element)
{
	char	*str;

	str = ft_substr(c, 0, 3);
	element[0] = ft_atoi(str);
	if (check_color(element[0]) == false)
		return (false);
	str = ft_substr(c, 4, 3);
	element[1] = ft_atoi(str);
	if (check_color(element[1]) == false)
		return (false);
	str = ft_substr(c, 8, 3);
	element[2] = ft_atoi(str);
	if (check_color(element[2]) == false)
		return (false);
	free(c);
	return (true);
}

t_config	*load_texture(char *filename)
{
	t_config	*config;

	config->no = get_line_from_id("NO", filename);
	config->so = get_line_from_id("SO", filename);
	config->we = get_line_from_id("WE", filename);
	config->ea = get_line_from_id("EA", filename);
	char_to_color(get_line_from_id("F", filename), config->c);
	char_to_color(get_line_from_id("C", filename), config->f);
	return (config);
}

bool	check_color(int c)
{
	if (c > 255 || c < 0)
		return (false);
	return (true);
}

bool	check_config(t_config *config)
{
	if (check_color(config->c) || check_color(config->f))
		return (false);
	if (!file_exist(config->no) || !file_exist(config->so)
		|| !file_exist(config->we) || !file_exist(config->ea))
		return (false);
	return (true);
}
