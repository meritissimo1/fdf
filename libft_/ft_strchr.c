/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:26:34 by user42            #+#    #+#             */
/*   Updated: 2022/02/10 16:48:26 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		size;
	char	*str;

	size = ft_strlen(s);
	i = 0;
	str = (char *)s;
	while (i <= size)
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	return (0);
}
