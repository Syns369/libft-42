/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdarcour <jdarcour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:42:53 by jdarcour          #+#    #+#             */
/*   Updated: 2022/11/19 16:03:18 by jdarcour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	len_src = ft_strlen((char *)src);
	len_dest = ft_strlen(dst);
	index = len_dest;
	j = 0;
	if (size <= len_dest)
		return (len_src + size);
	while (src[j] && index + 1 < size)
		dst[index++] = src[j++];
	dst[index] = '\0';
	return (len_dest + len_src);
}
