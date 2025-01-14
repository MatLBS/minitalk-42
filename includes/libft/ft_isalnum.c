/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:04:23 by matle-br          #+#    #+#             */
/*   Updated: 2024/06/27 16:01:13 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isalnum(int c)
{
	if (((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
		&& ((c < '0' || c > '9' )))
		return (0);
	return (1);
}
