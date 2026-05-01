/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <amartel@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 00:33:47 by amartel           #+#    #+#             */
/*   Updated: 2026/05/01 07:52:47 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d/cub3d.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_config t_config;

bool	ft_valid_path(const char *filename);
bool		ft_parser(t_config *conf, const char *filename);
bool		file_exist(const char *filename);
char		*get_line_from_id(char *id, char *file);
bool		char_to_color(char *c, int *element);
t_config	*load_texture(char *filename);
bool		check_color(int c);
bool		check_config(t_config *config);

#endif