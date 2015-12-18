/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 12:40:09 by jbahus            #+#    #+#             */
/*   Updated: 2015/11/24 17:50:49 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*new_lst(t_ls *lst)
{
	t_ls	*new_lst;

	new_lst = (t_ls*)malloc(sizeof(t_ls));
	new_lst->fname = NULL;
	new_lst->next = lst;
	return (new_lst);
}
