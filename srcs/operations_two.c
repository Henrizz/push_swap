/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:20:07 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:22:19 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	op_pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
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
	rotate(a);
	ft_printf("ra\n");
}

void	op_rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}
