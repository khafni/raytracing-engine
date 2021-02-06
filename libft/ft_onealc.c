/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onealc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 02:29:40 by khafni            #+#    #+#             */
/*   Updated: 2019/10/30 02:31:13 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_onealc(void)
{
	char *str;

	str = (char *)malloc(1);
	if (str == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}
