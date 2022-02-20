/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:29:30 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/12 21:28:44 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *list)
{
	t_node	*tmp_head;

	if (list->head && list->head != list->tail)
	{
		tmp_head = list->head->next;
		list->tail->next = list->head;
		list->head->next = NULL;
		list->tail = list->head;
		list->head = tmp_head;
	}
	list->ra_cnt++;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list *list)
{
	t_node	*tmp_head;

	if (list->head && list->head != list->tail)
	{
		tmp_head = list->head->next;
		list->tail->next = list->head;
		list->head->next = NULL;
		list->tail = list->head;
		list->head = tmp_head;
	}
	list->rb_cnt++;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list *A, t_list *B)
{
	t_node	*tmp_head_A;
	t_node	*tmp_head_B;

	if (A->head && A->head != A->tail)
	{
		tmp_head_A = A->head->next;
		A->tail->next = A->head;
		A->head->next = NULL;
		A->tail = A->head;
		A->head = tmp_head_A;
	}
	if (B->head && B->head != B->tail)
	{
		tmp_head_B = B->head->next;
		B->tail->next = B->head;
		B->head->next = NULL;
		B->tail = B->head;
		B->head = tmp_head_B;
	}
	A->ra_cnt++;
	A->rb_cnt++;
	B->ra_cnt++;
	B->rb_cnt++;
	ft_putstr_fd("rr\n", 1);
}
