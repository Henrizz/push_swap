/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:12:40 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/05/09 16:53:47 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	get_and_check_input_bonus(argc, argv, &a);
	read_and_make_operations(&a, &b);
	if (is_sorted(&a) == 0 && b == NULL)
		write(1, "OK\n", 3);
	else 
		write(1, "KO\n", 3);
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

void	get_and_check_input_bonus(int argc, char **argv, t_stack **a)
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
