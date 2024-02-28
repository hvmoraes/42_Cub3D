/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:29:14 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/28 10:19:09 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	temp;

	temp = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == temp)
			return ((char *)s);
		s++;
	}
	if (temp == '\0')
		return ((char *)s);
	return (0);
}
