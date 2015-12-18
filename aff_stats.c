/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:02:10 by jbahus            #+#    #+#             */
/*   Updated: 2015/12/04 15:28:25 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		stuff_date(char *date, int i, time_t ls_mtime)
{
	if (ft_little_date(date, i, ls_mtime))
		return ;
	if (date[23] == '5')
	{
		while (i < 16)
			ft_putchar(date[i++]);
	}
	else
	{
		while (i < 24)
		{
			if (i < 11 || i > 18)
				ft_putchar(date[i]);
			i++;
		}
	}
}

static void	type_of_file(t_ls *ls)
{
	if (S_ISBLK(ls->st.st_mode) == 1)
		ft_putchar('b');
	else if (S_ISCHR(ls->st.st_mode) == 1)
		ft_putchar('c');
	else if (S_ISDIR(ls->st.st_mode) == 1)
		ft_putchar('d');
	else if (S_ISLNK(ls->st.st_mode) == 1)
		ft_putchar('l');
	else if (S_ISSOCK(ls->st.st_mode) == 1)
		ft_putchar('s');
	else if (S_ISFIFO(ls->st.st_mode) == 1)
		ft_putchar('p');
	else if (S_ISREG(ls->st.st_mode) == 1)
		ft_putchar('-');
}

static void	aff_mode(t_ls *ls)
{
	type_of_file(ls);
	(S_IRUSR & ls->st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWUSR & ls->st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	if (S_ISUID & ls->st.st_mode)
		(S_IXUSR & ls->st.st_mode) ? ft_putchar('s') : ft_putchar('S');
	else
		(S_IXUSR & ls->st.st_mode) ? ft_putchar('x') : ft_putchar('-');
	(S_IRGRP & ls->st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWGRP & ls->st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	if (S_ISGID & ls->st.st_mode)
		(S_IXGRP & ls->st.st_mode) ? ft_putchar('s') : ft_putchar('S');
	else
		(S_IXGRP & ls->st.st_mode) ? ft_putchar('x') : ft_putchar('-');
	(S_IROTH & ls->st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWOTH & ls->st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	if (S_ISVTX & ls->st.st_mode)
		(S_IXOTH & ls->st.st_mode) ? ft_putchar('t') : ft_putchar('T');
	else
		(S_IXOTH & ls->st.st_mode) ? ft_putchar('x') : ft_putchar('-');
	ft_putchar(' ');
}

static void	aff_time_size(t_ls *ls, t_ind ind)
{
	char	*date;
	int		i;

	if (!S_ISBLK(ls->st.st_mode) && !S_ISCHR(ls->st.st_mode))
	{
		if (ind.minor > 0)
			ft_space_device(ind);
		date = ft_ultoa(ls->st.st_size);
		i = ft_strlen(date);
		while (i <= ind.bytes)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putstr(date);
		free(date);
		ft_putchar(' ');
	}
	i = 4;
	date = ctime(&(ls->st.st_mtime));
	stuff_date(date, i, ls->st.st_mtime);
	ft_putchar(' ');
}

void		aff_stats(t_ls *ls, t_ind ind)
{
	int		i;
	char	*max;

	aff_mode(ls);
	max = ft_itoa(ls->st.st_nlink);
	i = ft_strlen(max);
	while (i <= ind.nlink)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(max);
	free(max);
	ft_putchar(' ');
	aff_uid_grp(ls, ind);
	if (S_ISBLK(ls->st.st_mode) || S_ISCHR(ls->st.st_mode))
		aff_min_maj(ls->st, ind);
	aff_time_size(ls, ind);
}
