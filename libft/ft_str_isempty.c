/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isempty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:55:54 by bstrong           #+#    #+#             */
/*   Updated: 2022/03/25 20:16:25 by bstrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isempty(char *str)
{
	while(str)
	{
		if (ft_isprint(*str) || *str == ' ')
			return (0);
		++str;
	}
	return (1);
}
