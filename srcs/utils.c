/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:21:59 by mtournay          #+#    #+#             */
/*   Updated: 2022/01/12 10:40:54 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	clear_all(t_struct *v)
{
	write(2, "Error\n", 6);
	ft_lstclear(v->alst, free);
	ft_lstclear(v->blst, free);
	ft_lstclear(v->copy, free);
	free(v->alst);
	free(v->blst);
	free(v->copy);
	return (0);
}

void	convert(const char *str, t_struct *v)
{
	unsigned long long int	nbr;
	int						minus;
	int						i;

	nbr = 0;
	minus = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			minus = -1;
	}
	while (ft_isdigit(str[i]))
	{
		nbr += str[i++] - 48;
		if (ft_isdigit(str[i]))
			nbr *= 10;
	}
	if ((nbr > 2147483647 && minus > 0) || (minus > 0 && i > 10))
		v->bool = 0;
	else if ((nbr > 2147483648 && minus < 0) || i > 11)
		v->bool = 0;
	nbr *= minus;
	*v->ret = nbr;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (!s1[i] && !s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_struct *v)
{
	t_list	*i;
	t_list	*j;

	i = *v->alst;
	j = i->next;
	while (j)
	{
		if (*(int *)i->content > *(int *)j->content)
			return (0);
		i = i->next;
		j = i->next;
	}
	return (1);
}

void	sign_content(t_struct *v)
{
	int		i;
	t_list	*a;
	t_list	*copy;

	a = *v->alst;
	while (a)
	{
		copy = *v->copy;
		i = 0;
		while (copy)
		{
			if (*(int *)a->content == *(int *)copy->content)
			{
				*(int *)a->content = i;
				break ;
			}
			copy = copy->next;
			i++;
		}
		a = a->next;
	}
}
