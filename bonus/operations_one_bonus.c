/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:30:30 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/09 16:54:35 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (stack == NULL || (*stack)->next == NULL)
		return ;
	else
	{
		*stack = (*stack)->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
	}
}

void	op_sa(t_stack **a)
{
	if (*a == NULL)
		return ;
	swap_stack(a);
}

void	op_sb(t_stack **b)
{
	if (*b == NULL)
		return ;
	swap_stack(b);
}

void	op_ss(t_stack **a, t_stack **b)
{
	if (*b == NULL || *a == NULL)
		return ;
	swap_stack(a);
	swap_stack(b);
}

void	push(t_stack **take, t_stack **put)
{
	t_stack	*temp;

	if (take == NULL)
		return ;
	temp = (*take)->next;
	(*take)->next = *put;
	*put = *take;
	*take = temp;
}
