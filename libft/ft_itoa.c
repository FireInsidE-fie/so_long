/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:55:44 by estettle          #+#    #+#             */
/*   Updated: 2024/10/08 16:25:25 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* get_char_count()
 * takes an integer as parameter and returns the number of digits it is composed
 * of. if negative, the minus sign is counted as an additional digit.
 * as such, the max number of digits this function will return is the number of
 * digits for INT_MAX + 1.
*/
static int	get_char_count(int n)
{
	int	i;
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	i = 1;
	while (n / i >= 10)
	{
		count++;
		i *= 10;
	}
	return (count);
}

/* ft_itoa()
 * this function takes an integer as an argument and returns its translation as
 * a string. negative values are supported.
*/
char	*ft_itoa(int n)
{
	int		char_count;
	char	*str;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	char_count = get_char_count(n);
	str = malloc((char_count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[char_count] = '\0';
	is_negative = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		is_negative = 1;
	}
	while (char_count-- > (0 + is_negative))
	{
		str[char_count] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(1234));
	printf("%s\n", ft_itoa(-1234));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
}
*/
