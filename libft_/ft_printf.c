/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:17:20 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/14 10:03:15 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_conversion(char *str, va_list ap)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i += print_c(str, va_arg(ap, int));
	else if (*str == '%')
		i += print_percent(str);
	else if (*str == 's')
		i += print_s(str, va_arg(ap, char *));
	else if (*str == 'd' || *str == 'i' || *str == 'u')
		i += print_d(str, va_arg(ap, int));
	else if (*str == 'x' || *str == 'X' || *str == 'p')
		i += print_x(str, va_arg(ap, unsigned long int));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			i += check_conversion((char *)++str, ap);
		else
		{
			write(1, str, 1);
			i++;
		}
		str++;
	}
	va_end(ap);
	return (i);
}
