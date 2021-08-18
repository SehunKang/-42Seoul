/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:31:05 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/12 21:23:09 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_list(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		error_call_1(new);
	new->head = NULL;
	new->tail = NULL;
	new->pa_cnt = 0;
	new->pb_cnt = 0;
	new->ra_cnt = 0;
	new->rb_cnt = 0;
	return (new);
}

void	add_first(t_list *list, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_call_1(list);
	new->num = value;
	if (list->head == NULL)
	{
		list->tail = new;
		list->head = new;
		new->next = NULL;
	}
	else
	{
		new->next = list->head;
		list->head = new;
	}
}

void	add_last(t_list *list, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_call_1(list);
	new->num = value;
	if (list->tail == NULL)
	{
		list->tail = new;
		list->head = new;
		new->next = NULL;
	}
	else
	{
		list->tail->next = new;
		list->tail = new;
	}
}

void	delete_top(t_list *list)
{
	t_node	*tmp;

	if (list->head)
	{
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
}

void	free_list(t_list *list)
{
	while (list->head)
		delete_top(list);
}
