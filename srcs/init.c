/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:30:01 by mtournay          #+#    #+#             */
/*   Updated: 2022/01/12 10:41:43 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	free_lst(t_struct *v, int bool)
{
	free(v->alst);
	free(v->blst);
	free(v->copy);
	if (bool == 1)
		free(v->ret);
	if (bool == 2)
	{
		free(v->ret);
		free(v->ret_cpy);
	}
	return (0);
}

int	init_4(t_struct *v, int i)
{
	*v->ret_cpy = *v->ret;
	v->a_add->next = ft_lstnew(v->ret);
	if (!v->a_add->next)
	{
		free(v->ret);
		free(v->ret_cpy);
		return (clear_all(v));
	}
	v->cpy_add->next = ft_lstnew(v->ret_cpy);
	if (!v->cpy_add->next)
	{
		free(v->ret_cpy);
		return (clear_all(v));
	}
	v->a_add = v->a_add->next;
	v->cpy_add = v->cpy_add->next;
	i++;
	return (i);
}

int	init_3(t_struct *v, char **argv, int argc, int i)
{
	v->cpy_add = *v->copy;
	i++;
	while (i < argc)
	{
		v->ret = malloc(sizeof(int));
		if (!v->ret)
			return (clear_all(v));
		v->ret_cpy = malloc(sizeof(int));
		if (!v->ret_cpy)
			return (clear_all(v));
		convert(argv[i], v);
		if (!v->bool)
		{
			free(v->ret);
			free(v->ret_cpy);
			return (clear_all(v));
		}
		i = init_4(v, i);
		if (!i)
			return (0);
	}
	v->a_add = *v->alst;
	v->cpy_add = *v->copy;
	return (1);
}

int	init_2(t_struct *v, char **argv, int argc, int i)
{
	v->ret = malloc(sizeof(int));
	if (!v->ret)
		return (free_lst(v, 0));
	v->ret_cpy = malloc(sizeof(int));
	if (!v->ret_cpy)
		return (free_lst(v, 1));
	convert(argv[i], v);
	if (!v->bool)
	{
		write(2, "Error, convert\n", 15);
		return (free_lst(v, 2));
	}
	*v->ret_cpy = *v->ret;
	*v->alst = ft_lstnew(v->ret);
	if (!*v->alst)
		return (free_lst(v, 1));
	*v->copy = ft_lstnew(v->ret_cpy);
	if (!*v->copy)
	{
		free(*v->alst);
		return (free_lst(v, 1));
	}
	v->a_add = *v->alst;
	return (init_3(v, argv, argc, i));
}

int	init_1(t_struct *v, char **argv, int argc)
{
	int		i;

	i = 0;
	v->bool = 1;
	v->alst = malloc(sizeof(t_list));
	if (!v->alst)
		return (0);
	v->blst = malloc(sizeof(t_list));
	if (!v->blst)
	{
		free(v->alst);
		return (0);
	}
	v->copy = malloc(sizeof(t_list));
	if (!v->copy)
	{
		free(v->alst);
		free(v->blst);
		return (0);
	}
	*v->alst = NULL;
	*v->blst = NULL;
	*v->copy = NULL;
	return (init_2(v, argv, argc, i));
}
