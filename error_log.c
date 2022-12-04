/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:45:28 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/04 15:07:54 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	throw_err(char *type)
{
	ft_printf(COLOR_RED "Error:\n"COLOR_RESET "%s\n", type);
	return (0);
}
