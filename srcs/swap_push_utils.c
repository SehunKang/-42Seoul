/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:48:32 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/16 13:23:36 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list)
{
	t_node	*tmp;

	if (list->head->next)
	{
		tmp = list->head->next;
		list->head->next = list->head->next->next;
		tmp->next = list->head;
		list->head = tmp;
		if (tmp->next->next == NULL)
			list->tail = tmp->next;
	}
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list *list)
{
	t_node	*tmp;

	if (list->head->next)
	{
		tmp = list->head->next;
		list->head->next = list->head->next->next;
		tmp->next = list->head;
		list->head = tmp;
		if (tmp->next->next == NULL)
			list->tail = tmp->next;
	}
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list *list_A, t_list *list_B)
{
	t_node	*tmp;

	if (list_A->head->next)
	{
		tmp = list_A->head->next;
		list_A->head->next = list_A->head->next->next;
		tmp->next = list_A->head;
		list_A->head = tmp;
		if (tmp->next->next == NULL)
			list_A->tail = tmp->next;
	}
	if (list_B->head->next)
	{
		tmp = list_B->head->next;
		list_B->head->next = list_B->head->next->next;
		tmp->next = list_B->head;
		list_B->head = tmp;
		if (tmp->next->next == NULL)
			list_B->tail = tmp->next;
	}
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_list *list_A, t_list *list_B)
{
	if (list_B->head)
	{
		push(list_B, list_A);
	}
	list_A->pa_cnt++;
	list_B->pa_cnt++;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list *list_A, t_list *list_B)
{
	if (list_A->head)
	{
		push(list_A, list_B);
	}
	list_A->pb_cnt++;
	list_B->pb_cnt++;
	ft_putstr_fd("pb\n", 1);
}
