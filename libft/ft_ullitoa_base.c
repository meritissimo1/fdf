/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:42:20 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/14 10:03:06 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ullitoa_base(unsigned long long int n, char *base)
{
	unsigned long long int	nbr;
	char					*a;
	int						b_len;
	int						size;

	b_len = ft_strlen(base);
	nbr = n;
	size = 1;
	n /= b_len;
	while (n && size++)
		n /= b_len;
	a = (char *)malloc(size + 1);
	if (!a)
		return (0);
	a[size--] = '\0';
	while (nbr > 0)
	{
		a[size--] = base[nbr % b_len];
		nbr /= b_len;
	}
	if (size == 0 && a[1] == '\0')
		a[0] = '0';
	return (a);
}
