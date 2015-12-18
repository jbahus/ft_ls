/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:16:11 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/16 16:20:58 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_little_date(char *date, int i, time_t ls_mtime)
{
	if (ls_mtime > time(NULL) || ls_mtime < time(NULL) - 15778800)
	{
		while (i < 10)
			ft_putchar(date[i++]);
		if (date[i] != ' ')
			ft_putchar(date[i]);
		ft_putstr("  ");
		i = (ls_mtime > time(NULL)) ? 24 : 20;
		while (date[i] != '\n')
			ft_putchar(date[i++]);
		return (1);
	}
	return (0);
}
