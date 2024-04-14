/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:51:46 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/04 20:16:39 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		n *= 10;
		n += (str[i] - '0');
		i++;
	}
	return (n);
}

void	ft_putnbr(int	nbr)
{
	char	c;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

void	tab_mult(char *str)
{
	int	i;

	i = 1;
	while (i < 10)
	{
		ft_putnbr(i);
		write(1, " x ", 4);
		ft_putnbr(ft_atoi(str));
		write(1, " = ", 4);
		ft_putnbr(ft_atoi(str) * i);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		tab_mult(av[1]);
	else
		write (1, "\n", 1);
	return (0);
}
