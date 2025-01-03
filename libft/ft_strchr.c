/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:05:13 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:40:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 	Locates the FIRST occurrence of c (as a char)
///			in the string pointed to by s.
///			The terminating null character is considered to be part of the str
///			therefore if c is `\0', the functions locate the terminating `\0'
/// @param s	string to be searched.
/// @param c	character to search for.
/// @return		pointer to the located character, NULL if non found
char	*ft_strchr(const char *s, int_fast32_t c)
{
	int_fast32_t	i;

	i = -1;
	c = (char)c;
	while (s[++i] != '\0')
		if (s[i] == c)
			return ((char *)&s[i]);
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
