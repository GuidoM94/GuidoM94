/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:20:31 by gmeoli            #+#    #+#             */
/*   Updated: 2022/02/14 20:14:40 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(char *file);
char	*get_line(int fd, char *save);
void	*ft_calloc(size_t count, size_t size);
int		ft_strchr(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_save(char *save, char *file);

#endif
