/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:46:30 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:46:32 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates count * size bytes and sets them all to 0.
 *
 * @param count The number of objects to allocate.
 * @param size The size of each object to allocate.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*area;
	size_t	b_size;

	b_size = count * size;
	area = malloc(b_size);
	if (!area)
		return (NULL);
	ft_bzero(area, b_size);
	return (area);
}
