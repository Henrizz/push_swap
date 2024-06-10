/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:52:48 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/09 16:53:34 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	make_operation(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		op_ra(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		op_rb(b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		op_pb(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		op_pa(a, b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		op_rr(a, b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		op_rrr(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		op_rra(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		op_rrb(b);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		op_sa(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		op_sb(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		op_ss(a, b);
}

int	is_valid(char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0 || ft_strncmp(line, "rb\n", 3) == 0
		|| ft_strncmp(line, "pb\n", 3) == 0 || ft_strncmp(line, "pa\n", 3) == 0
		|| ft_strncmp(line, "rr\n", 3) == 0 || ft_strncmp(line, "rrr\n", 4) == 0
		|| ft_strncmp(line, "rra\n", 4) == 0 || ft_strncmp(line, "rrb\n", 4) == 0
		|| ft_strncmp(line, "sa\n", 3) == 0 || ft_strncmp(line, "sb\n", 3) == 0
		|| ft_strncmp(line, "ss\n", 3) == 0)
		return (0);
	else
		return (1);
}

void	read_and_make_operations(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = NULL;
		line = get_next_line(0);
		if (!line)
			return ;
		if (is_valid(line) == 1)
		{
			free_stack(*a);
			free_stack(*b);
			free(line);
			error_exit();
		}
		else
			make_operation(a, b, line);
		free(line);
	}
}
