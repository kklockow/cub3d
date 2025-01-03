/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:59:58 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:45:15 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Converts an alphabetic character from lower to capital case
/// @param c Character to convert
/// @return Converted character if successful
///			Unconverted character if char is not alphabetical
int_fast32_t	ft_toupper(int_fast32_t c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
