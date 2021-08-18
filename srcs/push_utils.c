/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:45:46 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/16 22:41:23 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *src, t_list *dest)
{
	t_node	*tmp;

	tmp = src->head;
	src->head = src->head->next;
	if (src->head == NULL)
		src->tail = NULL;
	tmp->next = dest->head;
	dest->head = tmp;
	if (dest->tail == NULL)
		dest->tail = tmp;
	src->size--;
	dest->size++;
}
