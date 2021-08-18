/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:30:24 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/16 22:40:42 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/*error in new_list*/
void	error_call_1(t_list *list)
{
	ft_putstr_fd("Error\n", 2);
	free_list(list);
	free(list);
	exit(1);
}

	/*error in fill_stack*/
void	error_call_2(int *nums, t_list *list)
{
	ft_putstr_fd("Error\n", 2);
	free(nums);
	free_list(list);
	free(list);
	exit(1);
}

void	free_all(t_list *A, t_list *B, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	free_list(A);
	free_list(B);
	free(A);
	free(B);
	exit (0);
}

int	*list_arr(t_list *list, int r)
{
	int		*arr;
	t_node	*tmp;
	int		i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * r);
	if (!arr)
		return (NULL);
	tmp = list->head;
	while (i < r)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

void	set_cnt(t_list *A, t_list *B)
{
	A->ra_cnt = 0;
	A->rb_cnt = 0;
	A->pa_cnt = 0;
	A->pb_cnt = 0;
	B->ra_cnt = 0;
	B->rb_cnt = 0;
	B->pa_cnt = 0;
	B->pb_cnt = 0;
	A->pv_1 = 0;
	A->pv_1 = 0;
	B->pv_2 = 0;
	B->pv_2 = 0;
}
