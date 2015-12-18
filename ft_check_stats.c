/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:48:39 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/03 05:57:38 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			stuff_check(char **blk)
{
	ft_putstr("total ");
	ft_putendl(*blk);
	free(*blk);
}

static void		nbofspace(t_ind *ind)
{
	char			*str;

	str = ft_itoa(ind->nlink);
	ind->nlink = ft_strlen(str);
	free(str);
	str = ft_ultoa(ind->bytes);
	ind->bytes = ft_strlen(str);
	free(str);
}

static void		ind_space(t_ls *ls, t_ind *ind)
{
	t_grp	*grp;
	t_uid	*uid;
	char	*tmp;

	tmp = NULL;
	grp = getgrgid(ls->st.st_gid);
	uid = getpwuid(ls->st.st_uid);
	ft_ind_stuff(ls, ind, uid);
	if (!grp)
	{
		tmp = ft_itoa(ls->st.st_gid);
		if (ind->grp < ft_strlen(tmp))
			ind->uid = ft_strlen(tmp);
		free(tmp);
	}
	else if (ind->grp < ft_strlen(grp->gr_name))
		ind->grp = ft_strlen(grp->gr_name);
	if (ind->bytes < ls->st.st_size)
		ind->bytes = ls->st.st_size;
}

void			check_stats(t_ls *ls, t_ind *ind, t_opt opt, int ok)
{
	unsigned long	block;
	char			*blk;

	block = 0;
	ft_ind_init(ind);
	blk = NULL;
	while (ls)
	{
		if ((ls->fname[0] != '.' && !opt.a) || opt.a)
		{
			block += ls->st.st_blocks;
			ind_space(ls, ind);
			ft_check_min_maj(ls->st, ind);
		}
		ls = ls->next;
	}
	blk = ft_ultoa(block);
	if (ok)
		stuff_check(&blk);
	nbofspace(ind);
}
