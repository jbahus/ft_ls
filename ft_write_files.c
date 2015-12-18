/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 12:14:07 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/02 23:56:09 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	aff_link(t_ls *ls, t_opt opt)
{
	char	*str;

	str = NULL;
	if (opt.l && S_ISLNK(ls->st.st_mode))
	{
		str = malloc(sizeof(char) * 2000);
		if (readlink(ls->fname, str, 2000) > 0)
		{
			ft_putstr(" -> ");
			ft_putstr(str);
			ft_bzero(str, ft_strlen(str));
		}
		free(str);
	}
}

void	ft_write_files(t_ls *lst, t_opt opt, t_ls *path)
{
	t_ind	ind;

	if (!lst)
		return ;
	if (opt.t)
		ft_time_sort(&lst, opt.r1);
	else
		ft_ascii_sort(&lst, opt.r1);
	while (lst)
	{
		if (opt.l)
		{
			check_stats(lst, &ind, opt, 0);
			aff_stats(lst, ind);
		}
		ft_putstr(lst->fname);
		if (opt.l)
			aff_link(lst, opt);
		ft_putendl("");
		lst = ft_lst_del(lst);
	}
	if (path)
		ft_putendl("");
}
