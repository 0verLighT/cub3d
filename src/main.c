/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 02:11:15 by amartel           #+#    #+#             */
/*   Updated: 2026/04/29 00:26:36 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d/cub3d.h"

int	ft_valid_path(char *filename)
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
	return (fd);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		printf("Error\n");
		return (1);
	}
	fd = ft_valid_path(av[1]);
	close(fd);
	return (0);
}
