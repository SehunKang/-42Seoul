/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:09:30 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/18 11:40:57 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_swap(t_list *A, t_list *B, int r)
{
	int	*arr;
	int	i;
	int	j;

	arr = list_arr(A, r);
	if (!arr)
		free_all(A, B, 1);
	i = 1;
	j = 0;
	while (i < r)
	{
		if (arr[j] > arr[i])
			j = i;
		i++;
	}
	if (2 < j)
		while (j++ < r)
			rra(A);
	else
		while (j--)
			ra(A);
	pb(A, B);
	free(arr);
	r--;
	select_diverge(A, B, r);
}

void	select_shuffle(t_list *A, t_list *B)
{
	if (A->head->num < A->head->next->num)
	{
		if (A->tail->num < A->head->next->num)
		{
			if (A->head->num < A->tail->num)
				ft_1_3_2(A);
			else
				ft_2_3_1(A);
		}
	}
	else
	{
		if (A->head->next->num < A->tail->num)
		{
			if (A->head->num < A->tail->num)
				ft_2_1_3(A);
			else
				ft_3_1_2(A);
		}
		else
			ft_3_2_1(A);
	}
	while (B->head)
		pa(A, B);
}

void	select_diverge(t_list *A, t_list *B, int r)
{
	if (r == 3)
		select_shuffle(A, B);
	else
		select_swap(A, B, r);
}

void	swap_two(t_list *A)
{
	if (A->head->num > A->tail->num)
		sa(A);
}

int	main(int argc, char **argv)
{
	t_list	*stack_A;
	t_list	*stack_B;

	if (argc == 1)
		return (0);
	stack_A = new_list();
	fill_stack(argc, argv, stack_A);
	stack_B = new_list();
	if (argc == 2)
		swap_two(stack_A);
	else if (argc == 4)
		select_shuffle(stack_A, stack_B);
	else if (4 < argc && argc < 25)
		select_swap(stack_A, stack_B, argc - 1);
	else
		q_A_to_B(stack_A, stack_B, argc - 1);
	free_all(stack_A, stack_B, 0);
	return (0);
}
