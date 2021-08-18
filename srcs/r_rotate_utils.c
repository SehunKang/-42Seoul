/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:36:52 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/09 10:56:31 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *list)
{
	t_node	*tmp_tail;

	if (list->head && list->head != list->tail)
	{
		tmp_tail = list->head;
		while (tmp_tail->next != list->tail)
			tmp_tail = tmp_tail->next;
		list->tail->next = list->head;
		list->head = list->tail;
		list->tail = tmp_tail;
		tmp_tail->next = NULL;
	}
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list *list)
{
	t_node	*tmp_tail;

	if (list->head && list->head != list->tail)
	{
		tmp_tail = list->head;
		while (tmp_tail->next != list->tail)
			tmp_tail = tmp_tail->next;
		list->tail->next = list->head;
		list->head = list->tail;
		list->tail = tmp_tail;
		tmp_tail->next = NULL;
	}
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list *A, t_list *B)
{
	t_node	*tmp_tail_A;
	t_node	*tmp_tail_B;

	if (A->head && A->head != A->tail)
	{
		tmp_tail_A = A->head;
		while (tmp_tail_A->next != A->tail)
			tmp_tail_A = tmp_tail_A->next;
		A->tail->next = A->head;
		A->head = A->tail;
		A->tail = tmp_tail_A;
		tmp_tail_A->next = NULL;
	}
	if (B->head && B->head != B->tail)
	{
		tmp_tail_B = B->head;
		while (tmp_tail_B->next != B->tail)
			tmp_tail_B = tmp_tail_B->next;
		B->tail->next = B->head;
		B->head = B->tail;
		B->tail = tmp_tail_B;
		tmp_tail_B->next = NULL;
	}
	ft_putstr_fd("rrr\n", 1);
}
