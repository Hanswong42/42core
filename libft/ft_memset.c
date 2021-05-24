/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:55:39 by wding-ha          #+#    #+#             */
/*   Updated: 2021/05/25 03:08:37 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!s || !n)
		return ;
	while (i < n)
	{
		((char *)s)[i] = (char)c;
		i++;
	}
}
