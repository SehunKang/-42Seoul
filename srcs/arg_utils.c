/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:21:49 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/18 11:43:12 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value_check(char *arg, int *nums, int index)
{
	long long	val;
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(arg);
	if (len == 0)
		return (0);
	if (arg[1] && (arg[0] == '-' || arg[0] == '+'))
		i++;
	while (i < len)
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	val = ft_atoi(arg);
	if (val < -2147483648 || 2147483647 < val)
		return (0);
	nums[index] = val;
	if (index != 0)
		while (0 <= --index)
			if (nums[index] == val)
				return (0);
	return (1);
}

void	fill_stack(int argc, char **argv, t_list *list)
{
	int	i;
	int	j;
	int	*nums;

	nums = (int *)malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		if (!value_check(argv[i], nums, i - 1))
			error_call_2(nums, list);
		i++;
	}
	list->size = argc - 1;
	j = 0;
	while (j < argc - 1)
	{
		add_last(list, nums[j]);
		j++;
	}
	is_sorted(nums, list, argc - 1);
	free(nums);
}

void	quick_sort(int *nums, int left, int right)
{
	int	i;
	int	j;
	int	tmp;

	i = left;
	j = right;
	while (i <= j)
	{
		while (nums[i] < nums[(left + right) / 2])
			i++;
		while (nums[j] > nums[(left + right) / 2])
			j--;
		if (i <= j)
		{
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j)
		quick_sort(nums, left, j);
	if (i < right)
		quick_sort(nums, i, right);
}

int	get_pivot(t_list *list, int r, int pivot_number)
{
	int		*arr;
	int		pivot_1;
	int		pivot_2;

	arr = list_arr(list, r);
	if (!arr)
		return (0);
	quick_sort(arr, 0, r - 1);
	pivot_1 = (r - 1) / 3;
	pivot_1 = arr[pivot_1];
	if (r == 2)
		pivot_2 = arr[1];
	else
	{
		pivot_2 = (r - 1) / 1.5;
		pivot_2 = arr[pivot_2];
	}
	free(arr);
	arr = NULL;
	if (pivot_number == 1)
		return (pivot_1);
	else
		return (pivot_2);
}

void	is_sorted(int *arr, t_list *list, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (arr[i - 1] < arr[i])
			i++;
		else
			return ;
	}
	free_list(list);
	free(list);
	free(arr);
	exit(1);
}
