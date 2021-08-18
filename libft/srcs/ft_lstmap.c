/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:59:06 by sehkang           #+#    #+#             */
/*   Updated: 2021/07/31 20:33:42 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret_lst;

	if (!lst)
		return (NULL);
	ret_lst = ft_lstnew(f(lst->content));
	if (!ret_lst)
	{
		ft_lstclear(&ret_lst, del);
		return (NULL);
	}
	ret_lst->next = ft_lstmap(lst->next, f, del);
	return (ret_lst);
}
