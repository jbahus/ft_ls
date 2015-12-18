/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 12:20:32 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/15 17:58:32 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		little_check(char *str, t_opt opt)
{
	t_stat	st;

	lstat(str, &st);
	if (S_ISLNK(st.st_mode) && opt.l)
		return (1);
	return (0);
}
