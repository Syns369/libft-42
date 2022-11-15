/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdarcour <jdarcour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:23:51 by jdarcour          #+#    #+#             */
/*   Updated: 2022/11/15 17:26:11 by jdarcour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	size_t	srclen;
	char	*ptr;

	srclen = ft_strlen((char *)s) + 1;
	ptr = malloc(srclen * sizeof(char));
	if (ptr == NULL)
		return (0);
	ft_strlcpy(ptr, s, srclen);
	return (ptr);
}
