/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:20:21 by htalhaou          #+#    #+#             */
/*   Updated: 2022/12/04 15:01:51 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_RESET   "\x1b[0m"

# define ERR_BER	"Invalid map file (.ber)"
# define ERR_ELMS	"The map must contain 1 (E), at least 1 (C), and 1 (P)."
# define ERR_RECT	"The map must be rectangular."
# define ERR_WALL	"The map must be closed/surrounded by walls."

# include <stdio.h>
# include <errno.h>
# include "get_map.h"
# include "libft/libft.h"

int	throw_err(char *type);

#endif