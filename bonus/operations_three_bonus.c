/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_three_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:21:08 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/09 16:52:05 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	op_rr(t_stack **a, t_stack **b)
{
	if (*b == NULL || *a == NULL)
		return ;
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack;
	last = *stack;
	if (stack == NULL || (*stack)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	while ((*stack)->next->next != NULL)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	last->next = temp;
	*stack = last;
}

void	op_rra(t_stack **a)
{
	if (*a == NULL)
		return ;
	reverse_rotate(a);
}

void	op_rrb(t_stack **b)
{
	if (*b == NULL)
		return ;
	reverse_rotate(b);
}

void	op_rrr(t_stack **a, t_stack **b)
{
	if (*b == NULL || *a == NULL)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
}
