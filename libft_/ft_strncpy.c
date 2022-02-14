/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:04:46 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/14 10:04:33 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*start;
	unsigned int	count;

	count = 0;
	start = dest;
	while ((src[count] != '\0') && count < n)
	{
		*start = src[count];
		start++;
		count++;
	}
	while (count < n)
	{
		*start = '\0';
		start++;
		count++;
	}
	return (dest);
}
