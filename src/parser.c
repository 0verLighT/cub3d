/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 00:36:00 by amartel           #+#    #+#             */
/*   Updated: 2026/05/01 02:46:31 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d/parser.h"

bool	ft_valid_path(const char *filename)
{
	int	fd;

	if (!ft_strnstr(filename + ft_strlen(filename) - 4, ".cub", 4))
	{
		printf("Error, wrong extension\n");
		return (false);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (false);
	}
	close(fd);
	return (true);
}

bool	ft_parser(t_config *conf, const char *filename)
{
	if (ft_valid_path(filename) == false)
		return (false);
	(void)conf;
	return (true);
}