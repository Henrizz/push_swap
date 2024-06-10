/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:12:40 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/07 19:22:00 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 3)
		return (0);
	get_and_check_input(argc, argv, &a);
	if (argc < 5)
		sort_small(&a);
	else
		sort_big(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*next;

	temp = stack;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}

void	get_and_check_input(int argc, char **argv, t_stack **a)
{
	int	i;
	int	*input;

	i = 0;
	input = malloc((argc - 1) * sizeof(int));
	if (input == NULL)
		error_exit();
	while (i < (argc - 1))
	{
		input[i] = ft_atol(argv[i + 1]);
		i++;
	}
	check_doubles(input, argc);
	make_stack(input, a, argc);
	free(input);
	if (is_sorted(a) == 0)
		exit(EXIT_SUCCESS);
	if (is_sorted_circular(a) == 0)
	{
		put_min_on_top(a);
		exit(EXIT_SUCCESS);
	}
}

void	check_doubles(int *input, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (argc - 1))
	{
		j = i + 1;
		while (j < (argc - 1))
		{
			if (input[i] == input[j])
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	display_list(t_stack **a)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	while (temp->next != NULL)
	{
		ft_printf("%d, ", temp->data);
		temp = temp->next;
	}
	ft_printf("%d\n", temp->data);
}
