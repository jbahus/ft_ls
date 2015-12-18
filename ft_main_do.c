/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:55:37 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/16 16:58:46 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_main_do(t_ls *path, t_opt opt, int i, int j)
{
	while (path)
	{
		if (path->next)
			ft_do(path->path, opt, 1, i);
		else if (j > 1)
			ft_do(path->path, opt, 0, i + 1);
		else
			ft_do(path->path, opt, 0, i);
		i++;
		path = ft_lst_del(path);
	}
}
