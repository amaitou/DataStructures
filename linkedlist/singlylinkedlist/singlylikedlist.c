
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list *ft_lstnew(void *content)
{
	t_list	*node;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ((void *)0);
	node->content = content;
	node->next = (void *)0;
	return (node);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int ft_lstsize(t_list *lst)
{
	t_list *temp;
	temp = lst;
	int	i = 0;
	while (temp)
	{
		temp = temp->next;
		++i;
	}
	return (i);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;
	temp = *lst;
	if (*lst)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
}

t_list *ft_lstlast(t_list *lst)
{
	t_list *temp;
	if (lst)
	{
		temp = lst;
		while (temp->next)
			temp = temp->next;
		return temp;
	}
	return ((void *)0);
}

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	t_list	*temp;
	if (lst)
	{
		temp = lst;
		del(lst->content);
		free(temp);
	}
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!del)
		return ;
	t_list *temp;
	while (*lst)
	{
		temp = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(temp);
	}
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

void editer(void *p)
{
	int	*i = (int *)p;
	*i *= 10;
}

void delete(void *p)
{
	free(p);
}

void *alter(void *p)
{
	int	*i = (int *)p;
	*i += 10;
	return (p);
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list 	*result;
	if (!lst)
		return ((void *)0);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
		return ((void *)0);
	result = temp;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (!temp)
			ft_lstclear(&lst, del);
		lst = lst->next;
		temp = temp->next;
	}
	return (result);
}

void ft_lsttravers(t_list *lst)
{
	t_list *temp;
	temp = lst;
	if (lst)
	{
		printf("[ ");
		while (temp)
		{
			printf("%d ", *((int *)temp->content));
			temp = temp->next;
		}
		printf("]\n");
	}
}

void ft_lstremoveat(t_list *lst, int p)
{
	t_list *temp;
	t_list *prev;
	int	i;
	i = 0;
	temp = lst;
	if (temp)
	{
		if (p == 0)
		{
			lst = lst->next;
			ft_lstdelone(temp, delete);
			return ;
		}
		while (temp && i < p)
		{
				prev = temp;
				i++;
				temp = temp->next;
		}
		if (temp)
		{
			prev->next = temp->next;
			ft_lstdelone(temp, delete);
		}
	}
}

int main(void)
{
	t_list *head;
	t_list *node;

	// set the header to NULL (avoid segmentation fault)
	head = NULL;

	// allocation the content of nodes
	int *a = malloc(sizeof(int)); *a = 10;
	int *b = malloc(sizeof(int)); *b = 20;
	int *c = malloc(sizeof(int)); *c = 30;
	int *d = malloc(sizeof(int)); *d = 40;
	int *e = malloc(sizeof(int)); *e = 50;

	// add nodes to the linked list
	ft_lstadd_back(&head, ft_lstnew(a));
	ft_lstadd_back(&head, ft_lstnew(b));
	ft_lstadd_back(&head, ft_lstnew(c));
	ft_lstadd_back(&head, ft_lstnew(d));
	ft_lstadd_back(&head, ft_lstnew(e));

	// loop over the LL and print each node's content
	ft_lsttravers(head);

	// create a new edited linked list based on the previous one
	node = ft_lstmap(head, alter, delete);

	// loop over the new LL and print each node's content;
	ft_lsttravers(node);

	return (0);
}
