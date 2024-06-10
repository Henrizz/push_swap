/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:00:04 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:21:03 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	sort_small(t_stack **a)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	if (ft_get_length(a) == 2 && is_sorted(a) == 1)
		op_sa(a);
	while (ft_get_length(a) == 3 && is_sorted(a) == 1)
	{
		find_max(a);
		if (*a == (*a)->max)
			op_ra(a);
		else if ((*a)->next == (*a)->max)
			op_rra(a);
		else if ((*a)->data > (*a)->next->data && (*a)->max == (*a)->next->next)
			op_sa(a);
	}
	return ;
}

void	sort_big(t_stack **a, t_stack **b)
{
	op_pb(a, b);
	op_pb(a, b);
	while (ft_get_length(a) > 3 && is_sorted_circular(a) == 1)
	{
		make_targets(a, b);
		sorted_push(a, b);
	}
	if (ft_get_length(a) == 3)
		sort_small(a);
	while (ft_get_length(b) > 0)
	{
		make_reverse_targets(a, b);
		reverse_sorted_push(a, b);
	}
	put_min_on_top(a);
}

void	put_min_on_top(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	find_min(a);
	set_indexes_meridians(a);
	while (*a != temp->min)
	{
		if (temp->min->above_mer == 1)
			op_ra(a);
		if (temp->min->above_mer == 0)
			op_rra(a);
	}
}

void	sorted_push(t_stack **a, t_stack **b)
{
	set_indexes_meridians(a);
	set_indexes_meridians(b);
	calculate_cost(a, b);
	set_cheapest(a);
	move_node(a, b);
}

void	set_indexes_meridians(t_stack **stack)
{
	int		meridian;
	int		i;	
	t_stack	*temp;

	i = 0;
	temp = *stack;
	meridian = ft_get_length(stack) / 2;
	while (temp != NULL)
	{
		if (i <= meridian)
			temp->above_mer = 1;
		else
			temp->above_mer = 0;
		temp->index = i;
		i++;
		temp = temp->next;
	}
}
