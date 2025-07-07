/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:46:36 by haile         #+#    #+#                 */
/*   Updated: 2024/11/06 13:21:14 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	finish;
	char	*sub;

	if (!s)
		return (0);
	finish = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	else
		finish = s_len - start;
	if (finish > len)
		finish = len;
	sub = (char *)malloc(sizeof(char) * (finish + 1));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, finish + 1);
	return (sub);
}
