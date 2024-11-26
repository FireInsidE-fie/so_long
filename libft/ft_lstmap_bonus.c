/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:47:13 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:47:14 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_lstmap()
 * iterates through the list pointed to by *lst, applying the function f() to
 * each item's content and storing the result inside a newly created list
 * del() is used in case of a failure to allocate the new list
 * returns the newly created list with altered content
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;	
	t_list	*new_item;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_item = ft_lstnew(content);
		if (!new_item)
		{
			del(content);
			free(new_item);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_item);
		lst = lst->next;
	}
	return (new_lst);
}
