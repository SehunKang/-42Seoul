/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:42:11 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/27 11:46:57 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ret_ptr;
	
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret_ptr = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(ret_ptr, s1, ft_strlen(s1));
	ft_memcpy(ret_ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ret_ptr[len] = '\0';
	return (ret_ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1);
	if (!(ptr = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(ptr, s1, len);
	ptr[len] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *tmp_dst;
	unsigned char *tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (0 < n--)
		*tmp_dst++ = *tmp_src++;
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret_ptr;
	size_t	ptr_len;

	ptr_len = (len <= ft_strlen(s) - start) ? len : (ft_strlen(s) - start);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (!(ret_ptr = (char *)malloc((ptr_len + 1) * sizeof(char))))
		return (NULL);
	ret_ptr = (char *)ft_memcpy(ret_ptr, s + start, ptr_len);
	ret_ptr[ptr_len] = '\0';
	return (ret_ptr);
}
