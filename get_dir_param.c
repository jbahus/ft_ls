/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:21:14 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/10 12:19:58 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swp_order(t_ls **tmp, t_ls **next)
{
	char	*yolo;

	yolo = (*next)->f_name;
	(*next)->f_name = (*tmp)->f_name;
	(*tmp)->f_name = yolo;
}

void	order(t_ls **ls, int r)
{
	t_ls *tmp;
	t_ls *next;

	tmp = *ls;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (r)
			{
				if (ft_strcmp(tmp->f_name, next->f_name) < 0)
					swp_order(&tmp, &next);
			}
			else if (ft_strcmp(tmp->f_name, next->f_name) > 0)
				swp_order(&tmp, &next);
			next = next->next;
		}
		tmp = tmp->next;
	}
}

int		get_dir_param(t_ls **dir, char **av, int i, t_opt opt)
{
	DIR		*directory;
	t_ls	*error;
	int		j;

	j = 0;
	error = NULL;
	while (av[i])
	{
		if (!(directory = opendir(av[i])))
		{
			error = new_tls(error);
			error->f_name = av[i++];
			j++;
		}
		else
		{
			*dir = new_tls(*dir);
			(*dir)->f_name = av[i++];
			closedir(directory);
		}
	}
	order(&error, 0);
	order(dir, opt.r1);
	while (error)
	{
		ft_error(error->f_name);
		error = error->next;
	}
	return (j);
}