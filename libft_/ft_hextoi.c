/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 08:25:52 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/14 10:05:05 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexstrtoi(char *hex)
{
	int	val;
	int	byte;
	int	i;

	i = 0;
	val = 0;
	while (hex[i])
	{
		if (i == 0 && hex[i] == '0' && hex[i + 1] == 'x')
			i += 2;
		byte = hex[i];
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
		i++;
	}
	return (val);
}
