/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:11:31 by user42            #+#    #+#             */
/*   Updated: 2022/02/14 10:03:31 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*str;

	size = ft_strlen(s1) + 1;
	str = malloc(size);
	if (!str)
		return (NULL);
	while (size--)
	{
		((unsigned char *)str)[size] = ((unsigned char *)s1)[size];
	}
	return (str);
}
