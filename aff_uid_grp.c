/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_uid_grp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:06:06 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/16 14:44:56 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_len_uid(t_uid *uid, t_ls *ls)
{
	int		i;
	char	*tmp;

	if (!uid)
	{
		tmp = ft_itoa(ls->st.st_uid);
		i = ft_strlen(tmp);
		ft_putnbr(ls->st.st_uid);
		free(tmp);
	}
	else
	{
		i = ft_strlen(uid->pw_name);
		ft_putstr(uid->pw_name);
	}
	return (i);
}

int		get_len_grp(t_grp *grp, t_ls *ls)
{
	int		i;
	char	*tmp;

	if (!grp)
	{
		tmp = ft_itoa(ls->st.st_gid);
		i = ft_strlen(tmp);
		ft_putnbr(ls->st.st_gid);
		free(tmp);
	}
	else
	{
		i = ft_strlen(grp->gr_name);
		ft_putstr(grp->gr_name);
	}
	return (i);
}

void	aff_uid_grp(t_ls *ls, t_ind ind)
{
	size_t	i;
	t_uid	*uid;
	t_grp	*grp;

	grp = getgrgid(ls->st.st_gid);
	uid = getpwuid(ls->st.st_uid);
	i = get_len_uid(uid, ls);
	while (i <= ind.uid)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(' ');
	i = get_len_grp(grp, ls);
	while (i < ind.grp)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(' ');
}
