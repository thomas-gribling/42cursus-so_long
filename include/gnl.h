/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:59:36 by tgriblin          #+#    #+#             */
/*   Updated: 2023/12/21 09:55:04 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# define BUFFER_SIZE 1000

char	*get_next_line(int fd);
void	*free_null(void *ptr1, void *ptr2);
char	*ft_strchr(const char *s, int c);

#endif