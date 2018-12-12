/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:21:00 by tcherret          #+#    #+#             */
/*   Updated: 2018/11/20 11:45:46 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*cont;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	cont = f(lst);
	if (!(new = ft_lstnew(cont->content, cont->content_size)))
		return (NULL);
	first = new;
	lst = lst->next;
	while (lst)
	{
		cont = f(lst);
		if (!(new->next = ft_lstnew(cont->content, cont->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
