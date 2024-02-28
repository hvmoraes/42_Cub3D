/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:41:44 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 10:26:01 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *str, const char *search, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (search[0] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (str[i] == search[j] && str[i] && i < len)
		{
			i++;
			j++;
		}
		if (!(search[j]))
			return ((char *)&str[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
