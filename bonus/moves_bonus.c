/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:17:06 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:20:45 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	move_node(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	if (temp->cheapest->above_mer == temp->cheapest->target->above_mer)
		move_together(a, b, temp->cheapest->above_mer);
	else if (temp->cheapest->above_mer > temp->cheapest->target->above_mer)
		move_separately_up_down(a, b);
	else if (temp->cheapest->above_mer < temp->cheapest->target->above_mer)
		move_separately_down_up(a, b);
	op_pb(a, b);
}

void	move_together(t_stack **a, t_stack **b, int mer)
{
	t_stack	*temp;

	temp = *a;
	if (mer == 1)
	{
		while (*a != temp->cheapest && *b != temp->cheapest->target)
			op_rr(a, b);
		while (*a == temp->cheapest && *b != temp->cheapest->target)
			op_rb(b);
		while (*a != temp->cheapest && *b == temp->cheapest->target)
			op_ra(a);
	}
	else if (mer == 0)
	{
		while (*a != temp->cheapest && *b != temp->cheapest->target)
			op_rrr(a, b);
		while (*a == temp->cheapest && *b != temp->cheapest->target)
			op_rrb(b);
		while (*a != temp->cheapest && *b == temp->cheapest->target)
			op_rra(a);
	}
}

void	move_separately_up_down(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	while (*a != temp->cheapest && *b != temp->cheapest->target)
	{
		op_ra(a);
		op_rrb(b);
	}
	while (*a == temp->cheapest && *b != temp->cheapest->target)
		op_rrb(b);
	while (*a != temp->cheapest && *b == temp->cheapest->target)
		op_ra(a);
}

void	move_separately_down_up(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	while (*a != temp->cheapest && *b != temp->cheapest->target)
	{
		op_rra(a);
		op_rb(b);
	}
	while (*a == temp->cheapest && *b != temp->cheapest->target)
		op_rb(b);
	while (*a != temp->cheapest && *b == temp->cheapest->target)
		op_rra(a);
}
