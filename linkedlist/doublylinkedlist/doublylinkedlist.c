#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

t_dlist	*ft_lstdnew(void *content)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return ((void *)0x00);
	new->content = content;
	new->next = (void *)0x00;
	new->prev = (void *)0x00;
	return (new);
}

size_t	ft_lstdsize(t_dlist *lst)
{
	size_t		i;
	t_dlist		*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_dlist	*ft_lstdlast(t_dlist *lst)
{
	if (!lst)
		return ((void *)0x00);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstditer(t_dlist *lst, void (*f)(void *))
{
	if (!f)
		return ;
	if (lst)
	{
		while (lst != NULL)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

void	ft_lstddelone(t_dlist *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		free(lst->content);
		free(lst);
	}
}

void	ft_lstdclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*temp;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		temp = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(temp);
	}
	*lst = (void *)0x00;
}

void	ft_lstdadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*temp;

	temp = *lst;
	if (temp)
	{
		temp->prev = new;
		new->next = temp;
		*lst = new;
		return ;
	}
	*lst = new;
}

void	ft_lstdadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	last = ft_lstdlast(*lst);
	if (last)
	{
		last->next = new;
		new->prev = last;
		return ;
	}
	*lst = new;
}

int main(void)
{
	t_dlist *head;
	t_dlist *temp;

	head = (void *)0x00;

	int *a = (int *)malloc(sizeof(int)); *a = 10;
	int *b = (int *)malloc(sizeof(int)); *b = 20;
	int *c = (int *)malloc(sizeof(int)); *c = 30;
	

	ft_lstdadd_back(&head, ft_lstdnew(a));
	ft_lstdadd_back(&head, ft_lstdnew(b));
	ft_lstdadd_back(&head, ft_lstdnew(c));

	temp = head;
	while (temp)
	{
		printf("%d\n", *((int *)temp->content));
		temp = temp->next;
	}
	ft_lstdclear(&head, free);
}
