/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 00:36:00 by amartel           #+#    #+#             */
/*   Updated: 2026/04/29 05:13:13 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d/parser.h"

void	ft_valid_path(const char *filename)
{
	int	fd;

	if (!ft_strnstr(filename + ft_strlen(filename) - 4, ".cub", 4))
	{
		printf("Error, wrong extension\n");
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	close(fd);
}