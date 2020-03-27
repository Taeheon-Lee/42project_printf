/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:28:45 by tlee              #+#    #+#             */
/*   Updated: 2020/02/28 17:01:40 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (!arr)
		return (NULL);
	while (i <= size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
