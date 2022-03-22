/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeoli <gmeoli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:55:14 by mpatrini          #+#    #+#             */
/*   Updated: 2022/03/22 14:37:30 by gmeoli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *c);
char	*ft_strdup(char *s1);
char	*ft_ret_line(char *line);
char	*ft_modify_line(char *line);

#endif
