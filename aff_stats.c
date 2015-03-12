/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:05:16 by jbahus            #+#    #+#             */
/*   Updated: 2015/03/12 16:11:24 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	aff_mode(t_ls *ls)
{
	S_ISDIR(ls->st.st_mode) ? ft_putchar('d') : 0;
	S_ISLNK(ls->st.st_mode) ? ft_putchar('l') : 0;
	S_ISFIFO(ls->st.st_mode) ? ft_putchar('p') : 0;
	S_ISSOCK(ls->st.st_mode) ? ft_putchar('s') : 0;
	S_ISREG(ls->st.st_mode) ? ft_putchar('-') : 0;
	S_ISCHR(ls->st.st_mode) ? ft_putchar('c') : 0;
	S_ISBLK(ls->st.st_mode) ? ft_putchar('b') : 0;
	(S_IRUSR & ls->st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWUSR & ls->st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	(S_IXUSR & ls->st.st_mode) ? ft_putchar('x') : ft_putchar('-');
	(S_IRGRP & ls->st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWGRP & ls->st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	(S_IXGRP & ls->st.st_mode) ? ft_putchar('x') : ft_putchar('-');
	(S_IROTH & ls->st.st_mode) ? ft_putchar('r') : ft_putchar('-');
	(S_IWOTH & ls->st.st_mode) ? ft_putchar('w') : ft_putchar('-');
	(S_IXOTH & ls->st.st_mode) ? ft_putchar('x') : ft_putchar('-');
	ft_putchar(' ');
}

void	aff_stats(t_ls *ls, t_ind ind)
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
	ft_bzero(max, ft_strlen(max));
	free(max);
	ft_putchar(' ');
}