/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:21:08 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:22:16 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
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
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	op_rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	op_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
