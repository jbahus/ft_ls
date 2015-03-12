/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 12:03:41 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/10 12:19:56 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_erase_lst(t_ls **ls)
{
	t_ls	*tmp;

	while (*ls)
	{
		tmp = (*ls)->next;
		free(*ls);
		*ls = tmp;
	}
}