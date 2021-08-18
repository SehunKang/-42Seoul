/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shuffle_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:44:03 by sehkang           #+#    #+#             */
/*   Updated: 2021/08/14 12:00:22 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_1_3_2(t_list *A)
{
	rra(A);
	sa(A);
}

void	ft_2_3_1(t_list *A)
{
	rra(A);
}

void	ft_2_1_3(t_list *A)
{
	sa(A);
}

void	ft_3_1_2(t_list *A)
{
	ra(A);
}

void	ft_3_2_1(t_list *A)
{
	sa(A);
	rra(A);
}
