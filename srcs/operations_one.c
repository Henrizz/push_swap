/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:30:30 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:22:13 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	swap_stack(a);
	ft_printf("sa\n");
}

void	op_sb(t_stack **b)
{
	swap_stack(b);
	ft_printf("sb\n");
}

void	op_ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	ft_printf("ss\n");
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
