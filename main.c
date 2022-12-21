/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:24:19 by yelaissa          #+#    #+#             */
/*   Updated: 2022/12/19 11:37:22 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/so_long.h"

int	main(void)
{
	t_list	*lst;
	t_list	*tmp;

	lst = NULL;
	tmp = ft_lstnew(ft_strdup("2"));
	ft_lstadd_front(&lst, tmp);
	while (lst != NULL)
	{
		ft_printf("%s", lst->content);
		lst = lst->next;
	}
	return (0);
}
