/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:26:41 by user42            #+#    #+#             */
/*   Updated: 2021/06/23 22:21:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char			current_char;
	unsigned int	i;

	if (src == NULL)
		return (0);
	if (size > 0)
	{
		i = 0;
		current_char = src[i];
		while (current_char != '\0' && i < (size - 1))
		{
			dst[i] = current_char;
			i++;
			current_char = src[i];
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
