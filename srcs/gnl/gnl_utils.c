/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:44:01 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/21 09:54:59 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/gnl.h"
#include "../../include/so_long.h"

void	*free_null(void *ptr1, void *ptr2)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*str;

	i = 0;
	str = (char *)s;
	ch = (char)c;
	while (str[i] != ch && str[i])
		i++;
	if (str[i] == '\0' && ch != '\0')
		return (NULL);
	return (str + i);
}
