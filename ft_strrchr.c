/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdarcour <jdarcour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:31:21 by jdarcour          #+#    #+#             */
/*   Updated: 2022/11/15 19:14:37 by jdarcour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen((char *)s);
	while (s_len + 1 > 0)
	{
		if (s[s_len] == (unsigned char)c)
			return ((char *)s + s_len);
		s_len--;
	}
	return (NULL);
}
