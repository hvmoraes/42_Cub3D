/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:32:49 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/30 12:24:23 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (!str)
		return (0);
	if (start >= ft_strlen(str))
	{
		result = malloc(1);
		if (!result)
			return (0);
		*result = '\0';
		return (result);
	}
	if (len > ft_strlen(str))
		return (ft_strdup((char *)str + start));
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	while (j < len && i < ft_strlen(str))
		result[j++] = str[i++];
	result[j] = '\0';
	return (result);
}
