/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:07:22 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/16 22:08:09 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	q_A_to_B(t_list *A, t_list *B, int r)
{
	int	racn;
	int	rbcn;
	int	pbcn;

	set_cnt(A, B);
	if (r < 3)
	{
		if (r)
		{
			if (A->head->next && A->head->num > A->head->next->num)
				sa(A);
		}
		return ;
	}
	q_sort_A_to_B(A, B, r);
	racn = A->ra_cnt;
	rbcn = B->rb_cnt;
	pbcn = B->pb_cnt;
	q_arrange(A, B, racn, rbcn);
	q_A_to_B(A, B, racn);
	q_B_to_A(A, B, rbcn);
	q_B_to_A(A, B, pbcn - rbcn);
}

void	q_sort_A_to_B(t_list *A, t_list *B, int r)
{
	A->pv_1 = get_pivot(A, r, 1);
	A->pv_2 = get_pivot(A, r, 2);
	while (0 < r--)
	{
		if (A->head->num < A->pv_2)
		{
			pb(A, B);
			if (B->head->num > A->pv_1)
			{
				if (A->head->num < A->pv_2)
					rb(B);
				else if (1 < r)
				{
					rr(A, B);
					r--;
				}
				else
					rb(B);
			}
		}
		else
			ra(A);
	}
}

void	q_arrange(t_list *A, t_list *B, int racn, int rbcn)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < racn && i < rbcn)
	{
		rrr(A, B);
		i++;
		j++;
	}
	while (i++ < racn)
		rra(A);
	while (j++ < rbcn)
		rrb(B);
}

void	q_B_to_A(t_list *A, t_list *B, int r)
{
	int	racn;
	int	rbcn;
	int	pacn;

	set_cnt(A, B);
	if (r < 3)
	{
		if (r == 2)
		{
			if (B->head->next && B->head->num < B->head->next->num)
				sb(B);
			pa(A, B);
		}
		if (r != 0)
			pa(A, B);
		return ;
	}
	q_sort_B_to_A(A, B, r);
	racn = A->ra_cnt;
	rbcn = B->rb_cnt;
	pacn = B->pa_cnt;
	q_A_to_B(A, B, pacn - racn);
	q_arrange(A, B, racn, rbcn);
	q_A_to_B(A, B, racn);
	q_B_to_A(A, B, rbcn);
}

void	q_sort_B_to_A(t_list *A, t_list *B, int r)
{
	B->pv_1 = get_pivot(B, r, 1);
	B->pv_2 = get_pivot(B, r, 2);
	while (0 < r--)
	{
		if (B->head->num > B->pv_1)
		{
			pa(A, B);
			if (A->head->num < B->pv_2)
			{
				if (B->head->num > B->pv_1)
					ra(A);
				else if (1 < r)
				{
					rr(A, B);
					r--;
				}
				else
					ra(A);
			}
		}
		else
			rb(B);
	}
}
