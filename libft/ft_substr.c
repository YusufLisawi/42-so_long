/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:18:10 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/23 14:50:02 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	size_t			slen;
	size_t			i;
	size_t			j;

	slen = ft_strlen(s);
	i = 0;
	if (!len || !slen || start >= slen)
		return (ft_strdup(""));
	while (i < len && s[i + start] != '\0')
		i++;
	dst = (char *)malloc((i + 1));
	if (!dst)
		return (NULL);
	j = 0;
	while (j < i)
		dst[j++] = s[start++];
	dst[j] = '\0';
	return (dst);
}
