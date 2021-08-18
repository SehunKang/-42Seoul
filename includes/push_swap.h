/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:52:16 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/18 11:40:52 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	struct s_node	*next;
	int				num;
}			t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
	int		pa_cnt;
	int		pb_cnt;
	int		ra_cnt;
	int		rb_cnt;
	int		pv_1;
	int		pv_2;
}			t_list;

void	print_stack(t_list *A, t_list *B, int r);
void	select_shuffle(t_list *A, t_list *B);
void	select_swap(t_list *A, t_list *B, int r);
void	select_diverge(t_list *A, t_list *B, int r);
void	swap_two(t_list *A);
void	q_A_to_B(t_list *A, t_list *B, int r);
void	q_sort_A_to_B(t_list *A, t_list *B, int r);
void	q_B_to_A(t_list *A, t_list *B, int r);
void	q_sort_B_to_A(t_list *A, t_list *B, int r);
void	q_arrange(t_list *A, t_list *B, int racn, int rbcn);
t_list	*new_list(void);
int		get_pivot(t_list *list, int r, int pivot_number);
void	set_cnt(t_list *A, t_list *B);
void	add_first(t_list *list, int value);
void	add_last(t_list *list, int value);
void	delete_top(t_list *list);
void	free_list(t_list *list);
void	fill_stack(int argc, char **argv, t_list *list);
void	quick_sort(int *nums, int left, int right);
void	is_sorted(int *arr, t_list *list, int argc);
int		value_check(char *arg, int *nums, int index);
void	error_call_1(t_list *list);
void	error_call_2(int *nums, t_list *list);
void	free_all(t_list *A, t_list *B, int flag);
int		*list_arr(t_list *list, int r);
void	sa(t_list *list);
void	sb(t_list *list);
void	ss(t_list *list_A, t_list *list_B);
void	pa(t_list *list_A, t_list *list_B);
void	pb(t_list *list_A, t_list *list_B);
void	push(t_list *src, t_list *dest);
void	ra(t_list *list);
void	rb(t_list *list);
void	rr(t_list *A, t_list *B);
void	rra(t_list *list);
void	rrb(t_list *list);
void	rrr(t_list *A, t_list *B);
void	ft_1_3_2(t_list *A);
void	ft_2_3_1(t_list *A);
void	ft_2_1_3(t_list *A);
void	ft_3_1_2(t_list *A);
void	ft_3_2_1(t_list *A);
#endif
