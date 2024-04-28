/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:51:03 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/28 16:49:17 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

enum	e_type
{
	NONE = 10,
	WORD,
	FILENAME,
	CMD,
	OPERATOR,
};

enum	e_token
{
	STRING = 1,
	LESS,
	DLESS,
	GREAT,
	DGREAT,
	PIPE,
};

typedef struct s_token_node	t_token;
struct	s_token_node
{
	void	*content;
	int		type;
	t_token	*next;
	t_token	*prev;
};

typedef struct s_ast	t_ast;
struct s_ast
{
	int	type;
	t_token	*node;
	t_ast	*left;
	t_ast	*right;
};

#endif // ! AST_H
