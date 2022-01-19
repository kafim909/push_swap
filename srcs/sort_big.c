/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:16:44 by mtournay          #+#    #+#             */
/*   Updated: 2022/01/12 10:10:20 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_core(t_sort *s, t_struct *v)
{
	while (s->max_num >> s->max_bit)
		s->max_bit++;
	while (s->i < s->max_bit)
	{
		s->j = 0;
		while (s->j < s->size)
		{
			s->num = *(int *)v->a_add->content;
			if (((s->num >> s->i) & 1) == 0)
				push_b(v);
			else
				rotate_a(v, 1);
			s->j++;
		}
		while (v->b_add)
			push_a(v);
		s->i++;
	}
}

int	sort_big_stack(t_struct *v)
{
	t_sort	*s;

	s = malloc(sizeof(t_sort));
	if (!s)
		return (0);
	s->i = 0;
	v->a_add = *v->alst;
	s->size = ft_lstsize(v->a_add);
	s->max_num = s->size - 1;
	v->a_add = *v->alst;
	s->max_bit = 0;
	sort_core(s, v);
	free (s);
	return (1);
}

int	sort(t_struct *v, int argc)
{
	sort_list(v);
	sign_content(v);
	if (!is_sorted(v))
	{
		if (argc == 3)
			sort_stack_2(v);
		if (argc == 4)
			sort_stack_3(v);
		if (argc == 5)
			sort_stack_4(v);
		else if (argc == 6)
			sort_stack_5(v);
		else if (argc > 6)
			if (!sort_big_stack(v))
				return (clear_all_2(v));
	}
	return (clear_all_2(v));
}
