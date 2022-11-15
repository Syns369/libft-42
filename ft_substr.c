/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdarcour <jdarcour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:22:33 by jdarcour          #+#    #+#             */
/*   Updated: 2022/11/15 16:51:54 by jdarcour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(len + 1 * sizeof(char));
	if (ptr == NULL)
		return (0);
	while (len > 0)
	{
		ptr[i] = s[i + start];
		i++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
