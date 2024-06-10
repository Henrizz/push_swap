/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:48:18 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:22:25 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_sorted_push(t_stack **a, t_stack **b)
{
	set_indexes_meridians(a);
	set_indexes_meridians(b);
	calculate_cost(b, a);
	set_cheapest(b);
	reverse_move_node(a, b);
}

void	reverse_move_together(t_stack **a, t_stack **b, int mer)
{
	t_stack	*temp;

	temp = *b;
	if (mer == 1)
	{
		while (*b != temp->cheapest && *a != temp->cheapest->target)
			op_rr(a, b);
		while (*b == temp->cheapest && *a != temp->cheapest->target)
			op_ra(a);
		while (*b != temp->cheapest && *a == temp->cheapest->target)
			op_rb(b);
	}
	else if (mer == 0)
	{
		while (*b != temp->cheapest && *a != temp->cheapest->target)
			op_rrr(a, b);
		while (*b == temp->cheapest && *a != temp->cheapest->target)
			op_rra(a);
		while (*b != temp->cheapest && *a == temp->cheapest->target)
			op_rrb(b);
	}
}

void	reverse_move_node(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	if (temp->cheapest->above_mer == temp->cheapest->target->above_mer)
		reverse_move_together(a, b, temp->cheapest->above_mer);
	else if (temp->cheapest->above_mer > temp->cheapest->target->above_mer)
		reverse_move_separately_up_down(a, b);
	else if (temp->cheapest->above_mer < temp->cheapest->target->above_mer)
		reverse_move_separately_down_up(a, b);
	op_pa(a, b);
}

void	reverse_move_separately_up_down(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	while (*b != temp->cheapest && *a != temp->cheapest->target)
	{
		op_rb(b);
		op_rra(a);
	}
	while (*b == temp->cheapest && *a != temp->cheapest->target)
		op_rra(a);
	while (*b != temp->cheapest && *a == temp->cheapest->target)
		op_rb(b);
}

void	reverse_move_separately_down_up(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	while (*b != temp->cheapest && *a != temp->cheapest->target)
	{
		op_rrb(b);
		op_ra(a);
	}
	while (*b == temp->cheapest && *a != temp->cheapest->target)
		op_ra(a);
	while (*b != temp->cheapest && *a == temp->cheapest->target)
		op_rrb(b);
}
