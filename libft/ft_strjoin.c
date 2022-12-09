/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:48:13 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/07 11:52:02 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	*ft_strcat(char *dest, char *src)
// {
// 	int	dstlen;
// 	int	j;

// 	j = 0;
// 	dstlen = ft_strlen(dest);
// 	while (src[j])
// 	{
// 		dest[dstlen + j] = src[j];
// 		j++;
// 	}
// 	dest[dstlen + j] = 0;
// 	return (dest);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
// 	if (!(str))
// 		return (NULL);
// 	*str = 0;
// 	ft_strcat(str, (char *)s1);
// 	ft_strcat(str, (char *)s2);
// 	str[ft_strlen(str)] = '\0';
// 	return (str);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
