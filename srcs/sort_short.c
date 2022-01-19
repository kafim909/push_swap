/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:22:36 by mtournay          #+#    #+#             */
/*   Updated: 2022/01/12 10:10:46 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_2(t_struct *v)
{
	v->a_add = *v->alst;
	if (*(int *)v->a_add->content > *(int *)v->a_add->next->content)
		swap_a(v, 1);
}

void	sort_stack_3(t_struct *v)
{
	t_list	*i;

	i = *v->alst;
	if (*(int *)i->content > *(int *)i->next->content
		&& *(int *)i->content < *(int *)i->next->next->content)
		swap_a(v, 1);
	else if (*(int *)i->content > *(int *)i->next->content
		&& *(int *)i->next->content > *(int *)i->next->next->content)
	{
		swap_a(v, 1);
		reverse_rotate_a(v, 1);
	}
	else if (*(int *)i->content > *(int *)i->next->content
		&& *(int *)i->next->content < *(int *)i->next->next->content)
		rotate_a(v, 1);
	else if (*(int *)i->content < *(int *)i->next->content
		&& *(int *)i->content < *(int *)i->next->next->content)
	{
		swap_a(v, 1);
		rotate_a(v, 1);
	}
	else
		reverse_rotate_a(v, 1);
}

void	sort_stack_4(t_struct *v)
{
	int	k;

	k = 4;
	v->a_add = *v->alst;
	while (k)
	{
		if (*(int *)v->a_add->content < 2)
			push_b(v);
		else
		{
			rotate_a(v, 1);
		}
		k--;
	}
	v->b_add = *v->blst;
	v->a_add = *v->alst;
	if (*(int *)v->b_add->content == 0)
		swap_b(v, 1);
	if (*(int *)v->a_add->content == 3)
		swap_a(v, 1);
	push_a(v);
	push_a(v);
}

void	sort_list(t_struct *v)
{
	t_list	*i;
	t_list	*j;
	int		*temp;

	i = *v->copy;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (*(int *)i->content > *(int *)j->content)
			{
				temp = i->content;
				i->content = j->content;
				j->content = temp;
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	sort_stack_5(t_struct *v)
{
	int	k;

	k = 5;
	v->a_add = *v->alst;
	while (k)
	{
		if (*(int *)v->a_add->content < 2)
			push_b(v);
		else
		{
			rotate_a(v, 1);
		}
		k--;
	}
	if (!is_sorted(v))
		sort_stack_3(v);
	v->b_add = *v->blst;
	if (*(int *)v->b_add->content == 0)
		swap_b(v, 1);
	push_a(v);
	push_a(v);
}
