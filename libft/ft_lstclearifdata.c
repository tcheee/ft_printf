/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclearifdata.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:48:13 by tdelabro          #+#    #+#             */
/*   Updated: 2018/11/21 19:15:55 by tdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_p1(t_list **lst, t_list **head, t_list **prev)
{
	t_list	*tmp;

	if (*head == *lst)
	{
		*lst = (*head)->next;
		ft_lstdelone(head, &ft_lstdelcontent);
		*head = *lst;
	}
	else
	{
		tmp = *head;
		*head = (*head)->next;
		(*prev)->next = *head;
		ft_lstdelone(&tmp, &ft_lstdelcontent);
	}
}

void		ft_lstclearifdata(t_list **lst, void *data)
{
	t_list	*head;
	t_list	*prev;

	head = *lst;
	while (head)
	{
		if (head->content == data)
			ft_p1(lst, &head, &prev);
		else
		{
			prev = head;
			head = head->next;
		}
	}
}
