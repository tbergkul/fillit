/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:22:06 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/18 11:31:39 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset_newline(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	if (len == 0)
		return (b);
	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		if (*ptr != '\n')
			*ptr = (unsigned char)c;
		ptr++;
		i++;
	}
	return (b);
}
