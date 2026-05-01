/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 00:33:47 by amartel           #+#    #+#             */
/*   Updated: 2026/05/01 02:45:50 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d/cub3d.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_config t_config;

bool	ft_valid_path(const char *filename);
bool	ft_parser(t_config *conf, const char *filename);

#endif