/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:42:45 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/05 12:16:21 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		len;
	char	temp;
	int		i;

	len = 0;
	while (str[len] != '\0')
		len++;
	i = -1;
	while (++i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
	return (str);
}

#include <stdio.h>

//char	*ft_strrev(char *str)
//{
//	int		len;
//	const char	*temp = str;
//	int		i;
//
//	len = 0;
//	while (str[len] != '\0')
//		len++;
//	i = 0;
//	while (--len)
//	{
//		printf("%d\n", len);
//		str[i++] = temp[len];
//		printf("%s\n", temp);
//	}
//	return (str);
//}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s\n", ft_strrev(av[1]));
	}
	return (0);
}
