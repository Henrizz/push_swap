/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:20:07 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/09 16:51:59 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	op_pa(t_stack **a, t_stack **b)
{
	if (*b == NULL)
		return ;
	push(b, a);
}

void	op_pb(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	push(a, b);
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (stack == NULL || (*stack)->next == NULL)
		return ;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	*stack = (*stack)->next;
	temp = temp->next;
	temp->next = NULL;
}

void	op_ra(t_stack **a)
{
	if (*a == NULL)
		return ;
	rotate(a);
}

void	op_rb(t_stack **b)
{
	if (*b == NULL)
		return ;
	rotate(b);
}
