/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:18:02 by mtournay          #+#    #+#             */
/*   Updated: 2022/01/10 10:10:18 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_struct *v, int bool)
{
	int		*temp;
	t_list	*lst;

	v->a_add = *v->alst;
	lst = v->a_add->next;
	temp = v->a_add->content;
	v->a_add->content = lst->content;
	lst->content = temp;
	if (bool)
	{
		write(1, "sa\n", 3);
		v->moves++;
	}
}

void	swap_b(t_struct *v, int bool)
{
	int		*temp;
	t_list	*lst;

	v->b_add = *v->blst;
	lst = v->b_add->next;
	temp = v->b_add->content;
	v->b_add->content = lst->content;
	lst->content = temp;
	if (bool)
	{
		write(1, "sb\n", 3);
		v->moves++;
	}
}

void	swap_swap(t_struct *v)
{
	swap_a(v, 0);
	swap_b(v, 0);
	write(1, "ss\n", 3);
	v->moves++;
}

void	push_a(t_struct *v)
{
	int	bool;

	bool = 0;
	if (!*v->alst)
		bool = 1;
	if (*v->blst)
	{
		v->temp = *v->blst;
		v->temp2 = v->temp->next;
		ft_lstadd_front(v->alst, v->temp);
		v->b_add = v->temp2;
		*v->blst = v->b_add;
		v->a_add = *v->alst;
		if (bool)
			v->a_add->next = NULL;
		write(1, "pa\n", 3);
		v->moves++;
	}
}

void	push_b(t_struct *v)
{
	int	bool;

	bool = 0;
	if (!*v->blst)
		bool = 1;
	if (*v->alst)
	{
		v->temp = *v->alst;
		v->temp2 = v->temp->next;
		ft_lstadd_front(v->blst, v->temp);
		v->a_add = v->temp2;
		*v->alst = v->a_add;
		v->b_add = *v->blst;
		if (bool)
			v->b_add->next = NULL;
		write(1, "pb\n", 3);
		v->moves++;
	}
}
