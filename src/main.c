/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 02:11:15 by amartel           #+#    #+#             */
/*   Updated: 2026/05/01 07:14:25 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d/parser.h"

int	main(int ac, char **av)
{
	t_config	*config;
	if (ac != 2)
	{
		write(2, "Error, wrong number of argumets\n", 33);
		return (1);
	}
	config = ft_calloc(1, sizeof(t_config));
	if (!config || ft_parser(config, av[1]) == false)
	{
		free(config);
		return (1);
	}
	free(config);
	return (0);
}
