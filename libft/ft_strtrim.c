/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:43:42 by estettle          #+#    #+#             */
/*   Updated: 2024/10/04 10:40:50 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* get_prefix_nb()
 * counts the number of characters that are in the set from the beginning of the
 * s1 string, and returns it
*/
static int	get_prefix_nb(char const *s1, char const *set)
{
	int	prefix_nb;
	int	i;

	prefix_nb = -1;
	while (s1[++prefix_nb])
	{
		i = -1;
		while (set[++i])
		{
			if (s1[prefix_nb] == set[i])
			{
				i = 0;
				break ;
			}
		}
		if (!set[i])
			break ;
	}
	return (prefix_nb);
}

/* get_suffix_nb()
 * counts the number of characters that are in the set starting from the end of
 * the s1 string, and returns it
*/
static int	get_suffix_nb(char const *s1, char const *set)
{
	int	i;
	int	suffix_nb;
	int	s1_length;

	suffix_nb = -1;
	s1_length = ft_strlen(s1);
	if (!s1_length)
		return (0);
	while (s1[s1_length - ++suffix_nb - 1])
	{
		i = -1;
		while (set[++i])
		{
			if (s1[s1_length - suffix_nb - 1] == set[i])
			{
				i = 0;
				break ;
			}
		}
		if (!set[i])
			break ;
	}
	return (suffix_nb);
}

/* ft_strtrim()
 * removes any character from the set from both tips of string s1
 * returns the modified string
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		s1_length;
	int		prefix_nb;
	int		suffix_nb;

	s1_length = ft_strlen(s1);
	prefix_nb = get_prefix_nb(s1, set);
	suffix_nb = get_suffix_nb(s1, set);
	if (s1_length - prefix_nb <= 0 && s1_length - suffix_nb <= 0)
	{
		trimmed = malloc(sizeof(char));
		if (!trimmed)
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = malloc((s1_length - prefix_nb - suffix_nb + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + prefix_nb, s1_length - prefix_nb - suffix_nb + 1);
	trimmed[ft_strlen(trimmed)] = '\0';
	return (trimmed);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("[Test 4] : %s\n", ft_strtrim("            ", " "));
}
*/
