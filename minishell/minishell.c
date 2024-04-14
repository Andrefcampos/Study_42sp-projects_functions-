/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:46:41 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/11 19:08:55 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <unistd.h>


typedef struct s_list
{
	char			*content;
	struct s_list	*next;
	struct s_list	*prev;
} t_list;

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while(str[len])
		len++;
	return (len);
}

t_list	*create_node(char *data)
{
	t_list	*set;
	int		len_str;

	set = malloc(sizeof(t_list));
	if (!set)
		return (NULL);
	len_str = (int)ft_strlen(data);
	set->content = malloc(sizeof(char *) * (len_str + 1));
	if (!set->content)
		return (NULL);
	set->content = data;
	set->prev = NULL;
	set->next = NULL;
	return (set);
}

void	add_next_first(t_list **head, t_list *new_node)
{
	if (!new_node)
		return ;
	if (*head == NULL)
	{
		(*head)->prev = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
		return ;
	}
	new_node->next = *head;
	(*head)->prev = new_node;
	new_node->prev = NULL;
	*head = new_node;
}

void	add_next_last(t_list **head, t_list *new_node)
{
	t_list	*upd;

	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	upd = *head;
	while (upd->next)
		upd = upd->next;
	new_node->prev = upd;
	upd->next = new_node;
}

void	print_list(t_list **list)
{
	t_list *temp;

	if (!*list)
		return ;
	temp = *list;
	while (temp)
	{
		printf("nó: %s\n", temp->content);
		temp = temp->next;
	}
}

t_list	*last_list(t_list **lst)
{
	t_list	*head;

	if (!*lst)
		return (NULL);
	head = *lst;
	while (head && head->next)
		head = head->next;
	return (head);
}

void	exec_cmd(char **envp, t_list *lst, int pid)
{
	pid = fork();
	if (pid < 0)
		exit (EXIT_FAILURE);
	else if (pid == 0)
	{
//		execve();
	}
}

char	**parse_prompt(char *cmd)
{
	int	index;
	char	**matrix;

	index = 0;
	if (!cmd)
		return (NULL);
	matrix = ft_split(cmd, " ");
	return (matrix);
}

int	main(int ac, char **av, char **envp)
{
	char	*input;
	static t_list	*lst;
	static t_list	*last_node;
	int				pid;

	lst = NULL;
	last_node = NULL;
	while (1)
	{
		add_next_last(&lst, create_node(readline("minishell: ")));
		last_node = last_list(&lst);
		parse_prompt(last_node->content);
		add_history(last_node->content);
		if (strcmp(last_node->content, "exit") == 0)
			break;
	//	free(last_node->content);
	//	free(last_node);
	}
	print_list(&lst);
	rl_clear_history();
	return (0);
}
