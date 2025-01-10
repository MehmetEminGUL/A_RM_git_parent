/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megul <megul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:09:20 by megul             #+#    #+#             */
/*   Updated: 2024/12/24 09:33:00 by megul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
            i++;
        return (i);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (((dstsize - 1) > i) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	if (0 < dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}