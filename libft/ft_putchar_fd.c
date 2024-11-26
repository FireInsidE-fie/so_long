/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:57:23 by estettle          #+#    #+#             */
/*   Updated: 2024/10/03 10:57:32 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_putchar_fd()
 * writes the c character to the fd file descriptor
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
