/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:29:22 by mtournay          #+#    #+#             */
/*   Updated: 2022/01/10 10:11:07 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_b(t_struct *v, int bool)
{
	t_list	*penul;
	t_list	*last;

	if (*v->blst)
	{
		penul = penultimate(v->blst);
		last = ft_lstlast(*v->blst);
		ft_lstadd_front(v->blst, last);
		penul->next = NULL;
		if (bool)
		{
			write(1, "rrb\n", 4);
			v->moves++;
		}
	}
}

void	rrr(t_struct *v)
{
	reverse_rotate_a(v, 0);
	reverse_rotate_b(v, 0);
	write(1, "rrr\n", 4);
	v->moves++;
}
