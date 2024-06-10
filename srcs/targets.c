/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:15:04 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:22:35 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_targets(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	find_min(b);
	find_max(b);
	temp = *a;
	while (temp != NULL)
	{
		find_target_b(temp, b);
		temp = temp->next;
	}
}

void	find_target_b(t_stack *temp, t_stack **b)
{
	t_stack	*find;
	t_stack	*closest_smaller;

	find = *b;
	closest_smaller = NULL;
	while (find != NULL)
	{
		if (find->data < temp->data)
		{
			if (closest_smaller == NULL || find->data > closest_smaller->data)
			{
				closest_smaller = find;
			}
		}
		find = find->next;
	}
	if (closest_smaller == NULL)
		closest_smaller = (*b)->max;
	temp->target = closest_smaller;
}

void	make_reverse_targets(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	find_min(a);
	find_max(a);
	temp = *b;
	while (temp != NULL)
	{
		find_target_a(temp, a);
		temp = temp->next;
	}
}

void	find_target_a(t_stack *temp, t_stack **a)
{
	t_stack	*find;
	t_stack	*closest_bigger;

	find = *a;
	closest_bigger = NULL;
	while (find != NULL)
	{
		if (find->data > temp->data)
		{
			if (closest_bigger == NULL || find->data < closest_bigger->data)
			{
				closest_bigger = find;
			}
		}
		find = find->next;
	}
	if (closest_bigger == NULL)
		closest_bigger = (*a)->min;
	temp->target = closest_bigger;
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
