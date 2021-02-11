/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:36:05 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 11:53:01 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_sxb	sxb_create(void)
{
	t_sxb sxb;

	sxb = malloc(sizeof(struct s_syntax));
	sxb->r = 0;
	sxb->a = 0;
	sxb->error_message = NULL;
	sxb->is_error = 0;
	sxb->cameras_number = 0;
	sxb->does_ambient_exist = 0;
	return (sxb);
}

void	sxb_destroy(t_sxb sxb)
{
	file_destroy(sxb->f);
	free(sxb->error_message);
	close(sxb->fd);
	free(sxb);
}

void	sxb_set_error(t_sxb sxb, char *error_message)
{
	if (sxb->is_error == 0)
	{
		sxb->is_error = 1;
		sxb->error_message = ft_strdup(error_message);
	}
}
