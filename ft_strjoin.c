/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdarcour <jdarcour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:40:18 by jdarcour          #+#    #+#             */
/*   Updated: 2022/11/16 23:19:24 by jdarcour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		total_len;

	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	str = malloc(sizeof(char) * (total_len));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(str, s2, total_len);
	return (str);
}
