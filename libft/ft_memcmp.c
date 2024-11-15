/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:41:37 by estettle          #+#    #+#             */
/*   Updated: 2024/09/27 21:44:54 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* ft_memcmp()
 * compares two memory areas *s1 and *s2 for n bytes and tries to find a
 * difference.
 * if found, it returns the size difference between both bytes as unsigned chars
 * if not, it returns 0.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
