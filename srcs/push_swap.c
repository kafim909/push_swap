/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 06:21:40 by mtournay          #+#    #+#             */
/*   Updated: 2022/01/19 12:13:11 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	arg_is_digit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	error_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		if (!arg_is_digit(argv[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		while (j < argc)
		{
			if (!ft_strcmp(argv[j], argv[i]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	clear_all_2(t_struct *v)
{
	ft_lstclear(v->alst, free);
	ft_lstclear(v->copy, free);
	free(v->alst);
	free(v->blst);
	free(v->copy);
	free(v);
	return (0);
}

int	free_split(t_struct *v, int bool)
{
	int	i;

	i = 0;
	while (v->list[i])
	{
		free(v->list[i]);
		i++;
	}
	free(v->list);
	if (bool)
	{
		free(v);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_struct	*v;
	int			i;

	if (argc > 2)
	{
		write(2, "put ARGS into quotes like this : \"1 8 4 6 7\"\n", 45);
		return (0);
	}
	i = 0;
	v = malloc(sizeof(t_struct));
	if (!v)
		return (0);
	v->list = ft_split(argv[1], ' ');
	if (!v->list)
		return (0);
	while (v->list[i])
		i++;
	if (!error_check(i, v->list))
		return (free_split(v, 1));
	if (!init_1(v, v->list, i))
		return (free_split(v, 1));
	free_split(v, 0);
	return (sort(v, i + 1));
}
