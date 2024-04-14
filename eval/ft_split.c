/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:19:05 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/04 17:13:41 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	size_word(const char *str, char limiter)
{
	int	i;
	int	counter;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == limiter)
		i++;
	counter = 0;
	while (str[i] != limiter && str[i] != '\0')
	{
		counter++;
		i++;
	}
	return (counter);
}

int	count_words(const char *str, char limiter)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == limiter)
			i++;
		if (str[i] != '\0')
		{
			count++;
			i += size_word(str, limiter);
		}
	}
	return (count);
}

char	*alloc_and_copy_str(const char *str, char limiter)
{
	char	*string;
	int		count;
	int		i;
	int		j;
	
	if (!str)
		return (NULL);
	count = size_word(str, limiter);
	string = malloc(count + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (str[i] == limiter)
		i++;
	j = 0;
	while (str[i] != limiter || str[i] != '\0')
	{
		string[j] = str[i];
		j++;
		i++;
	}
	string[j] = '\0';
	return (string);
}

char	**ft_split(char *str, char limiter)
{
	char **matrix;
	int		count;
	int		i;
	int		j;

	count = count_words(str, limiter);
	matrix = malloc(sizeof(char) * count + 1);
	if (!matrix)
		return (NULL);
	i = 0;
	j = 0;
	while (count--)
	{
		matrix[j] = alloc_and_copy_str(&str[i], limiter);
		while (str[i] == limiter)
			i++;
		j++;
		i += size_word(&str[i], limiter);
	}
	matrix[j] = NULL;
	return (matrix);
}

int	main(int ac, char **av)
{
	char **matrix;
	int		i;

	matrix = ft_split(av[1], ' ');
	printf ("\n%d\n", size_word(av[1], 32));

	return (0);
}
