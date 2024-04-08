/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:24:17 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/03/16 16:18:27 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *str, void (*f)(int, char *))
{
	int	i;

	if (!str || !f)
		return ;
	i = 0;
	while (str[i])
	{
		f(i, str + i);
		i++;
	}
}