/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:36 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 10:26:50 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*cont;

	if (!lst)
		return (0);
	result = 0;
	while (lst)
	{
		cont = ft_lstnew(f(lst->content));
		if (!cont)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, cont);
		lst = lst->next;
	}
	return (result);
}

/*char	*ft_toupper2(char *str)
{
	char	*result;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] > 'a' && str[i] < 'z')
			result[i] = str[i] - 32;
	}
	return (result);
}
	
int	main()
{
	char	*str1 = "oi";
	char	*str2;
	t_list *list1 = ft_lstnew(str1);
	t_list *list2 = ft_lstmap(list1, ft_toupper2, ft_lstdelone);
	ft_putstr_fd(list2->content, 1);
}*/