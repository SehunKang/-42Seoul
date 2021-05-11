/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:05:35 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/11 21:08:39 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_lst;

	if (!(new_lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}
