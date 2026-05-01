/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 00:33:47 by amartel           #+#    #+#             */
/*   Updated: 2026/05/01 02:22:09 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d/cub3d.h"
# include <fcntl.h>
# include <stdbool.h>

bool	ft_valid_path(const char *filename);
bool	ft_parser(t_config *conf, const char *filename);

#endif