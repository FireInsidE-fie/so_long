/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:47:53 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:47:54 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strchr()
 * locates the first occurence of the character c inside of *s, and returns a
 * pointer to it.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
