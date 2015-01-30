/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 15:58:53 by jspezia           #+#    #+#             */
/*   Updated: 2014/03/13 14:02:45 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	error_msg(char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
}

void	error_msg_exit(char *message)
{
	error_msg(message);
	_exit(-1);
}
