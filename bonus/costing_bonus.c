/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:16:27 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:20:09 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	find_min(t_stack **stack)
{
	t_stack	*small;

	small = *stack;
	(*stack)->min = small;
	while (small->next != NULL)
	{
		if (small->data < (*stack)->min->data)
			(*stack)->min = small;
		small = small->next;
	}
	if (small->data < (*stack)->min->data)
		(*stack)->min = small;
}

void	find_max(t_stack **stack)
{
	t_stack	*big;

	big = *stack;
	(*stack)->max = big;
	while (big->next != NULL)
	{
		if (big->data > (*stack)->max->data)
			(*stack)->max = big;
		big = big->next;
	}
	if (big->data > (*stack)->max->data)
		(*stack)->max = big;
}

void	set_cheapest(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	(*stack)->cheapest = *stack;
	while (temp != NULL)
	{
		if (temp->cost < (*stack)->cheapest->cost)
			(*stack)->cheapest = temp;
		temp = temp->next;
	}
}

int	is_bigger(int a, int b)
{
	if (a > b)
		return (a);
	else 
		return (b);
}

void	calculate_cost(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	while (temp != NULL)
	{
		if (temp->above_mer == 1)
		{
			if (temp->target->above_mer == 1)
				temp->cost = is_bigger(temp->index, temp->target->index);
			else
				temp->cost = temp->index + \
				ft_get_length(b) - temp->target->index;
		}
		else if (temp->above_mer == 0)
		{
			if (temp->target->above_mer == 1)
				temp->cost = ft_get_length(a) - temp->index \
				+ temp->target->index;
			else
				temp->cost = is_bigger((ft_get_length(a) - temp->index), \
				(ft_get_length(b) - temp->target->index));
		}
		temp = temp->next;
	}
}
