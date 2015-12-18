/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ind_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:28:42 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/16 16:31:24 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ind_stuff(t_ls *ls, t_ind *ind, t_uid *uid)
{
	char	*tmp;

	if (ind->nlink < ls->st.st_nlink)
		ind->nlink = ls->st.st_nlink;
	if (!uid)
	{
		tmp = ft_itoa(ls->st.st_uid);
		if (ind->uid < ft_strlen(tmp))
			ind->uid = ft_strlen(tmp);
		free(tmp);
	}
	else if (ind->uid < ft_strlen(uid->pw_name))
		ind->uid = ft_strlen(uid->pw_name);
}
