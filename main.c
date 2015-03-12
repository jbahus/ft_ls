/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 12:59:30 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/12 16:00:33 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_opt(char *av, t_opt *opt)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (av[i] != 'l' && av[i] != 'R' && av[i] != 'a' && av[i] != 'r' && av[i] != 't')
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(av[i]);
			ft_putchar('\n');
			ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
			exit(0);
		}
		i++;
	}
	if (ft_memchr(av, 'l', ft_strlen(av)))
		opt->l = 1;
	if (ft_memchr(av, 'R', ft_strlen(av)))
		opt->r2 = 1;
	if (ft_memchr(av, 'a', ft_strlen(av)))
		opt->a = 1;
	if (ft_memchr(av, 'r', ft_strlen(av)))
		opt->r1 = 1;
	if (ft_memchr(av, 't', ft_strlen(av)))
		opt->t = 1;
}

int		ft_ind(char *av, int ac, int i, int j)
{
	static int	ret;

	if ((ac - i) > 1|| ret)
	{
		ft_putstr(av);
		ft_putstr(":\n");
		ret = 1;
	}
	return (ac - (i + j));
}

void	ft_go_to(char *av, t_opt opt, int ret)
{
	t_ls	*ls;

	ls = get_name(av, opt);
	if (opt.t == 1 || opt.r2 == 1 || opt.l == 1)
			ls = get_stats(ls, opt);
	//if (opt.l == 1 || opt.R == 1 || opt.a == 1 || opt.r == 1 || opt.t == 1)
	//{
		//if (opt.t == 1)
		//	ft_t(ls);
		//if (opt.R == 1)
			//ft_R(av, tls, opt);
		//if (opt.l == 1)
			//ft_l(av);
	//}
	ft_ls(ls, opt);
	if (ret > 1)
		ft_putchar('\n');
	ft_erase_lst(&ls);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	t_opt	opt;
	t_ls	*dir;

	dir = NULL;
	i = 1;
	if (ac > 1)
	{
		while (av[i] && av[i][1] && (av[i][0] == '-') && (ft_strcmp(av[i], "--") != 0))
			get_opt(av[i++], &opt);
		if (ft_strcmp(av[i], "--") == 0)
			i++;
	}
	if (i >= ac)
		ft_go_to(NULL, opt, 0);
	else
	{
		j = get_dir_param(&dir, av, i, opt);
		while (dir)
		{
			ft_go_to(dir->f_name, opt, ft_ind(dir->f_name, ac, i, j));
			dir = dir->next;
			i++;
		}
	}
	ft_erase_lst(&dir);
	return (0);
}
