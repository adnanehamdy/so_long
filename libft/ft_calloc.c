/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:45:50 by ahamdy            #+#    #+#             */
/*   Updated: 2021/11/12 11:59:32 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	size_t		f_s;

	f_s = size * count;
	if (f_s == 0)
		f_s += 1;
	ptr = malloc(f_s);
	if (ptr)
		ft_bzero(ptr, f_s);
	return (ptr);
}
