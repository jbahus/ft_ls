/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 16:43:14 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/04 14:15:48 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_opt(char *av, t_opt *opt)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (av[i] != 'l' && av[i] != 'R' && av[i] != 'a'
			&& av[i] != 'r' && av[i] != 't' && av[i] != '1')
		{
			ft_putstr_fd("/bin/ls: illegal option -- ", 2);
			ft_putchar_fd(av[i], 2);
			ft_putchar_fd('\n', 2);
			ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmno", 2);
			ft_putendl_fd("pqrstuwx1] [file ...]", 2);
			exit(0);
		}
		i++;
	}
	opt->l = ft_memchr(av, 'l', ft_strlen(av)) ? 1 : 0;
	opt->r2 = ft_memchr(av, 'R', ft_strlen(av)) ? 1 : 0;
	opt->a = ft_memchr(av, 'a', ft_strlen(av)) ? 1 : 0;
	opt->r1 = ft_memchr(av, 'r', ft_strlen(av)) ? 1 : 0;
	opt->t = ft_memchr(av, 't', ft_strlen(av)) ? 1 : 0;
}

t_opt	do_opt(t_opt opt, char **av, int *i)
{
	while (av[*i] && av[*i][1] && (av[*i][0] == '-')
		&& (ft_strcmp(av[*i], "--") != 0))
	{
		get_opt(av[*i], &opt);
		*i += 1;
	}
	if (ft_strncmp(av[*i], "--", 2) == 0)
		*i += 1;
	return (opt);
}
