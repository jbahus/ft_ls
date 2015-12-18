/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ind_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 02:40:36 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/03 02:45:04 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ind_init(t_ind *ind)
{
	ind->uid = 0;
	ind->grp = 0;
	ind->nlink = 0;
	ind->bytes = 0;
	ind->minor = 0;
	ind->major = 0;
}