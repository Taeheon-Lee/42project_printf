/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:25:51 by tlee              #+#    #+#             */
/*   Updated: 2020/02/28 17:01:17 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t num)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		if (i == num)
			return (dst);
		dst[i] = src[i];
		i++;
	}
	while (i < num)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
