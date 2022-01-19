/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:20:26 by mtournay          #+#    #+#             */
/*   Updated: 2022/01/19 12:12:37 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_struct
{
	char	**list;
	t_list	**alst;
	t_list	**blst;
	t_list	**copy;
	t_list	*a_add;
	t_list	*b_add;
	t_list	*cpy_add;
	t_list	*temp;
	t_list	*temp2;
	int		moves;
	int		*ret;
	int		*ret_cpy;
	int		bool;
}				t_struct;

typedef struct s_sort
{
	int	max_bit;
	int	size;
	int	max_num;
	int	num;
	int	i;
	int	j;
}				t_sort;

void	swap_a(t_struct *v, int bool);
void	swap_b(t_struct *v, int bool);
void	swap_swap(t_struct *v);
void	push_a(t_struct *v);
void	push_b(t_struct *v);

int		init_1(t_struct *v, char **argv, int argc);
int		free_lst(t_struct *v, int bool);
void	rotate_a(t_struct *v, int bool);
void	rotate_b(t_struct *v, int bool);
void	rotate_a_b(t_struct *v);
t_list	*penultimate(t_list **lst);
void	reverse_rotate_a(t_struct *v, int bool);

void	reverse_rotate_b(t_struct *v, int bool);
void	rrr(t_struct *v);

int		sort(t_struct *v, int argc);
void	sort_stack_2(t_struct *v);
void	sort_stack_3(t_struct *v);
void	sort_list(t_struct *v);
int		sort_big_stack(t_struct *v);
void	sort_stack_5(t_struct *v);
void	sort_stack_4(t_struct *v);

int		clear_all_2(t_struct *v);
int		ft_strcmp(char *s1, char *s2);
int		is_sorted(t_struct *v);
void	sign_content(t_struct *v);
void	convert(const char *str, t_struct *v);
int		clear_all(t_struct *v);

#endif