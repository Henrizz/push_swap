/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:56:49 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:22:04 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' 
		|| c == '\v' || c == '\f' || c == '\r')
		return (0);
	else
		return (1);
}

int	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (is_space(*str) == 0)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		error_exit();
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			error_exit();
		result = (result * 10) + *str - '0';
		str++;
	}
	if (result * sign < INT_MIN || result * sign > INT_MAX)
		error_exit();
	return (result * sign);
}

t_stack	*ft_stcklast(t_stack **lst)
{
	t_stack	*temp;

	if (!*lst)
		return (NULL);
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	make_stack(int *input, t_stack **a, int argc)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (i < (argc - 1))
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			error_exit();
		new->data = input[i];
		new->next = NULL;
		ft_stckadd_back(a, new);
		i++;
	}
}

void	ft_stckadd_back(t_stack **a, t_stack *new)
{
	t_stack	*last;

	if (*a == NULL)
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_stcklast(a);
		last->next = new;
		new->prev = last;
	}
}
