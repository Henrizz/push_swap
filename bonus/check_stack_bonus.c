/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:45:03 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:19:59 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	ft_get_length(t_stack **lst)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *lst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	is_sorted(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

t_stack	*find_min_for_circular_check(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*min_sep;

	temp = *stack;
	min_sep = *stack;
	while (temp->next != NULL) 
	{
		if (temp->data < min_sep->data)
			min_sep = temp;
		temp = temp->next;
	}
	if (temp->data < min_sep->data)
		min_sep = temp;
	return (min_sep);
}

int	do_circular_check(t_stack **a, t_stack *temp, t_stack *min_sep)
{
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (1);
		temp = temp->next;
	}
	if (temp->data > (*a)->data)
		return (1);
	else 
		temp = *a;
	while (temp->next != min_sep)
	{
		if (temp->data > temp->next->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	is_sorted_circular(t_stack **a)
{
	t_stack	*temp;
	t_stack	*min_sep;

	min_sep = find_min_for_circular_check(a);
	temp = min_sep;
	if (min_sep == *a)
		return (is_sorted(a));
	else
	{
		if (do_circular_check(a, temp, min_sep) == 1)
			return (1);
	}
	return (0);
}
