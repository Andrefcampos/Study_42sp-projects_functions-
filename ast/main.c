/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 02:39:49 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/28 03:04:51 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <strings.h>

int	is_space(char c)
{
	return (c != ' ' || c != '\t');
}

int	ft_strlen(char *str, char limiter)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != limiter || str[len] != '\0')
		len++;
	return (len);
}

static int get_word(char *input, char	*word, int	index, char limiter)
{
	int		i;
	
	word = malloc(ft_strlen(input, limiter) + 1);
	i = 0;
	while (input[index] != limiter)
	{
		word[i] = input[index];
		i++;
	}
	word[i] = '\0';
	return (index);
}

t_token	*build_tokens(char *input)
{
	t_token *token;
	char	limiter;
	int		index;

	if (!input)
		return (0);
	index = 0;
	limiter = '\0';
	while (input[index])
	{
		if (input[index] == '\'')
			limiter = '\'';
		else if (input[index] == '"')
			limiter = '"';
		else
		get_word(input, token->content, index, limiter);
		i++;
	}
	

	return (token);
}

int	main(void)
{
	t_token	*tokens;
	t_ast	*tree;
	char	*input;

	tokens = NULL;
	tree = NULL;

	while(1)
	{
		input = readline("minishell:");


	}
	return (0);
}
