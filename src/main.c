/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 02:11:15 by amartel           #+#    #+#             */
/*   Updated: 2026/04/28 02:50:09 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d/cub3d.h"

int	ft_valid_path(char *filename)
{
	int	fd;

	if (!ft_strnstr(filename + ft_strlen(filename) - 4, ".cub", 4))
	{
		printf("Error\n");
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
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
