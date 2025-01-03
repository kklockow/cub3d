/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:03:28 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:45:01 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Converts an alphabetic character from capital to lower case
/// @param c Character to convert
/// @return Converted character if successful
///			unconverted character if char is not alphabetical
int_fast32_t	ft_tolower(int_fast32_t c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
