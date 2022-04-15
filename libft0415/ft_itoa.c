/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchong <cchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:30:04 by cchong            #+#    #+#             */
/*   Updated: 2022/04/15 13:47:36 by cchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Convert int to string with digits.
*/

static int	countmemory(int n)
{
	unsigned int	memorycount;

	memorycount = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		memorycount++;
	}
	while (n > 0)
	{
		n /= 10;
		memorycount++;
	}
	return (memorycount);
}

static void	putint(int n, char *str, int index)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[index--] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		memory;
	int		index;

	memory = countmemory(n);
	str = malloc(sizeof(char) * (memory + 1));
	if (str == NULL)
		return (NULL);
	str[memory] = '\0';
	index = memory - 1;
	putint(n, str, index);
	return (str);
}
