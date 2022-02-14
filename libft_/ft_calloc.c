/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:36:13 by user42            #+#    #+#             */
/*   Updated: 2021/06/21 16:24:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total_size;
	void	*allocated;

	total_size = nitems * size;
	allocated = malloc(total_size);
	if (allocated == NULL)
		return (NULL);
	ft_bzero(allocated, total_size);
	return (allocated);
}
