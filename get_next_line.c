/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megul <megul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:58:30 by megul             #+#    #+#             */
/*   Updated: 2025/01/07 15:01:40 by megul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


void print_with_escape_chars(const char* str) {
	while (*str) {
		if (*str == '\n') {
			printf("\\n");  // \n karakteri görüldüğünde \n yazdır
		} else if (*str == '\t') {
			printf("\\t");  // \t karakteri görüldüğünde \t yazdır
		} else if (*str == '\\') {
			printf("\\\\");  // \\ karakteri görüldüğünde \\ yazdır
		} else {
			putchar(*str);  // Diğer karakterleri olduğu gibi yazdır
		}
		str++;
	}
}
//strdup
//strchr
//strjoin(collector  collector_buffer)
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_l;
	size_t	s2_l;

	if (!s1 || !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	result = (void *)malloc(s1_l + s2_l + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, s1_l + 1);
	ft_strlcpy(result + s1_l, s2, s2_l + 1);
	return (result);
}
//char *	trim_tochr(str, char);
//char *	trim_upchr(str, char);
//
char	*get_the_line(int fd, char *collector)
{
	char	*collector_buffer;
	int		read_test;
	
	collector_buffer = (char *)malloc(BUFFER_SIZE);
	while (!strchr(collector_buffer, 10) && collector_buffer)
	{
		printf("%i\n", !strchr(collector_buffer, 10) && collector_buffer);
		read_test = read(fd, collector_buffer, BUFFER_SIZE);
		printf("read()\t"); print_with_escape_chars(collector_buffer);printf("\t");print_with_escape_chars(collector);printf("\n");//sınama
	           //--read error handling--
		collector = ft_strjoin(collector, collector_buffer);
		printf("join\t"); print_with_escape_chars(collector_buffer);printf("\t");print_with_escape_chars(collector);printf("\n\n");//sınama
	}
	return (collector );
}
char	*get_next_line(int fd)
{
	static char	*collector;
	char		*the_line;
	
	collector = (char *)malloc(1);
	collector = get_the_line(fd, collector);
	//the_line = trim_tochr(strdup(collector), '\n');
	//collector = trim_upchr(collector, '\n');
	return (the_line);
}

int	main()
{
	int fd = open("test1", O_RDONLY);
	
	print_with_escape_chars(get_next_line(fd));printf("\n");
	print_with_escape_chars(get_next_line(fd));printf("\n");
	
	close(fd);
	return (0);
}
/*


fd: mehmet sağlim hikmet

i:1 mehm
i:2 mehm-et s 



*/