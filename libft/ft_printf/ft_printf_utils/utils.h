/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:45:19 by yelaissa          #+#    #+#             */
/*   Updated: 2022/10/22 19:20:12 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr_base(long long unsigned n, char *base);
int		ft_basenblen(unsigned long long nb, char *base);
int		ft_put_itoa(long n);
int		ft_put_uitoa(unsigned int n);
int		ft_put_hexa(unsigned int n, char format);
int		ft_put_pointer(long unsigned int n);
size_t	ft_strlen(const char *str);

#endif