/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:55:36 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/07 20:23:50 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char*)malloc(sizeof(char*) * ft_strlen(s1));
	if (s2 == NULL)
		return (0);
	while (i <= ft_strlen(s1))
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
