/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:44:38 by andrefil          #+#    #+#             */
/*   Updated: 2024/04/02 19:39:35 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char	bit;
	i = 8;
	bit = 0;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char	result;

	result = 0;
	i = 0;
	while (i++ < 8)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	return (result);
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int	main(void)
{
	unsigned char octet;

	octet = 30;
	print_bits(octet);
	printf("\n");
	print_bits(reverse_bits(octet));
	printf("\n");
	print_bits(swap_bits(octet));
	return (0);
}
