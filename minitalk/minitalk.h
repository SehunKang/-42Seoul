/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:28:48 by sehkang           #+#    #+#             */
/*   Updated: 2021/07/19 13:42:37 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_conf
{
	unsigned int	str_len;
	unsigned int	bits;
	char			str[1024];
	int				connected;
}					t_conf;

#endif
