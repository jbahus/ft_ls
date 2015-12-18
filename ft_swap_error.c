/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:28:06 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/04 15:12:32 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		swap_order(t_error **tmp, t_error **next)
{
	int		error;
	char	*name;

	name = (*next)->name;
	error = (*next)->msg;
	(*next)->name = (*tmp)->name;
	(*next)->msg = (*tmp)->msg;
	(*tmp)->msg = error;
	(*tmp)->name = name;
}

void			ft_swap_error(t_error **error, int r)
{
	t_error *tmp;
	t_error *next;

	tmp = *error;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (r)
			{
				if (ft_strcmp(tmp->name, next->name) < 0)
					swap_order(&tmp, &next);
			}
			else if (ft_strcmp(tmp->name, next->name) > 0)
				swap_order(&tmp, &next);
			next = next->next;
		}
		tmp = tmp->next;
	}
}

void			ft_write_error(t_error *error, t_opt opt)
{
	t_error	*tmp;

	(void)opt;
	if (!error)
		return ;
	tmp = NULL;
	ft_swap_error(&error, 0);
	while (error)
	{
		tmp = error->next;
		ft_error(error->name, error->msg);
		free(error->name);
		free(error);
		error = tmp;
	}
}
