/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:28:40 by mtournay          #+#    #+#             */
/*   Updated: 2022/01/10 10:10:49 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_struct *v, int bool)
{
	if (*v->alst)
	{
		v->temp = *v->alst;
		v->temp2 = v->temp->next;
		*v->alst = v->temp2;
		v->temp2 = ft_lstlast(v->temp2);
		v->temp2->next = v->temp;
		v->temp->next = NULL;
		v->a_add = *v->alst;
		if (bool)
		{
			write(1, "ra\n", 3);
			v->moves++;
		}
	}
}

void	rotate_b(t_struct *v, int bool)
{
	if (*v->blst)
	{
		v->temp = *v->blst;
		v->temp2 = v->temp->next;
		*v->blst = v->temp2;
		v->temp2 = ft_lstlast(v->temp2);
		v->temp2->next = v->temp;
		v->temp->next = NULL;
		v->b_add = *v->blst;
		if (bool)
		{
			write(1, "rb\n", 3);
			v->moves++;
		}
	}
}

void	rotate_a_b(t_struct *v)
{
	rotate_a(v, 0);
	rotate_b(v, 0);
	write(1, "rr\n", 3);
	v->moves++;
}

t_list	*penultimate(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *lst;
	temp2 = temp->next;
	while (temp2->next)
	{
		temp = temp2;
		temp2 = temp2->next;
	}
	return (temp);
}

void	reverse_rotate_a(t_struct *v, int bool)
{
	t_list	*penul;
	t_list	*last;

	if (*v->alst)
	{
		penul = penultimate(v->alst);
		last = ft_lstlast(*v->alst);
		ft_lstadd_front(v->alst, last);
		penul->next = NULL;
		if (bool)
		{
			write(1, "rra\n", 4);
			v->moves++;
		}
	}
}
