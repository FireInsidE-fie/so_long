/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:55:12 by estettle          #+#    #+#             */
/*   Updated: 2024/09/26 10:55:14 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is alphanumerical.
 *
 * @param c The char to check, as an integer.
 * @return 1 if the character is alphanumerical, 0 if not.
 */
int	ft_isalnum(int c)
{
	if (
		(c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')
	)
		return (1);
	return (0);
}
