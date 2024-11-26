/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:47:48 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:47:49 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* clear_slices()
 * in case of an allocation error in the slice() function, this one will free
 * all slices contained inside of the **slices array of strings.
*/
static int	clear_slices(char **slices)
{
	int	i;

	i = 0;
	while (slices[i])
		free(slices[i++]);
	free(slices);
	return (0);
}

/* ft_strndup()
 * allocates and copies *s1 for n characters, then returns a pointer to the copy
*/
static char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;

	copy = malloc((n) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, n);
	copy[n - 1] = '\0';
	return (copy);
}

/* alloc_slices()
 * allocates slices according to the number of substrings that *s would make
 * if divided by the c character.
*/
static char	**alloc_slices(char const *s, char c)
{
	int		i;
	int		slice_count;
	char	**slices;

	slice_count = 0;
	i = 0;
	if (!(*s))
	{
		slices = malloc(sizeof(char *));
		if (!slices)
			return (NULL);
		*slices = NULL;
		return (slices);
	}
	while (s[i] == c)
		i++;
	while (s && s[i])
	{
		if (s[i] == c)
			i++;
		else if (++slice_count)
			while (s[i] && s[i] != c)
				i++;
	}
	return (malloc((slice_count + 1) * sizeof(char *)));
}

/* slice()
 * takes an array of strings (**slices) and cuts the string *s between c
 * characters, then puts each slice into **slices.
*/
static int	slice(char **slices, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s && s[i])
	{
		while (s[i] == c)
			i++;
		s += i;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i > 0)
		{
			*(slices + j) = ft_strndup(s, i + 1);
			if (!*(slices + j++) && !clear_slices(slices))
				return (-1);
		}
	}
	slices[j] = NULL;
	return (0);
}

/* ft_split()
 * splits the string *s between c characters, then returns an array of strings
 * containing all the newly created substrings.
*/
char	**ft_split(char const *s, char c)
{
	char	**slices;

	slices = alloc_slices(s, c);
	if (!slices)
		return (NULL);
	if (!*s)
		return (slices);
	if (slice(slices, s, c) == -1)
		return (NULL);
	return (slices);
}
/*
#include <stdio.h>

int	main(void)
{
	//char	*invalidReadCheck;
	//invalidReadCheck = malloc(sizeof(char));
	char	**slices = ft_split("", 'a');
	printf("%s\n", slices[0]);
}
*/
