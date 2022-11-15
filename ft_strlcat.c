/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdarcour <jdarcour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:42:53 by jdarcour          #+#    #+#             */
/*   Updated: 2022/11/15 16:08:32 by jdarcour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	index;
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;

	len_src = ft_strlen((char *)src);
	len_dest = ft_strlen(dst);
	index = len_dest;
	j = 0;
	while (src[j] && index + 1 < size)
	{
		dst[index] = src[j];
		index++;
		j++;
	}
	dst[index] = '\0';
	if (size > len_dest)
	{
		return (len_dest + len_src);
	}
	else
	{
		return (len_src + size);
	}
}
