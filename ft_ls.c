/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:45:38 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/12 16:11:06 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_stats(t_ls *ls, t_ind *ind)
{
	char	*str;
	while (ls)
	{
		if (ind->nlink < ls->st.st_nlink)
			ind->nlink = ls->st.st_nlink;
		ls = ls->next;
	}
	str = ft_itoa(ind->nlink);
	ind->nlink = ft_strlen(str);
	free(str);
}

void	ft_ls(t_ls *ls, t_opt opt)
{
	t_ind	ind;

	check_stats(ls, &ind);
	while (ls)
	{
		if (!opt.a)
		{
			if (ls->f_name[0] != '.')
			{
				if (opt.l)
					aff_stats(ls, ind);
				ft_putendl(ls->f_name);
			}
		}
		else
		{
			if (opt.l)
				aff_stats(ls, ind);
			ft_putendl(ls->f_name);
		}
		ls = ls->next;
	}
}