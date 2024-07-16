/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:00:45 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/11 17:22:07 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	stock_char(char c)
{
	char			*tmp;
	static char		*message = NULL;
	static size_t	total_len;

	tmp = ft_calloc(total_len + 2, sizeof(char));
	if (!tmp)
		return ;
	if (message)
	{
		ft_memcpy(tmp, message, total_len);
		free(message);
	}
	message = tmp;
	message[total_len] = c;
	total_len++;
	message[total_len] = '\0';
	if (c == '\0')
	{
		ft_printf("%s", message);
		free(message);
		message = NULL;
		total_len = 0;
	}
}

void	bin_to_ascii(int signal, char *c)
{
	if (signal == SIGUSR2)
		*c = (*c << 1) | 1;
	else
		*c <<= 1;
}

void	handler_server(int signal, siginfo_t *info, void *context)
{
	static int		i;
	static char		c;
	int				client_pid;

	(void)context;
	client_pid = info->si_pid;
	bin_to_ascii(signal, &c);
	i++;
	if (i == 8)
	{
		i = 0;
		if (!c)
		{
			stock_char(c);
			kill(client_pid, SIGUSR2);
			return ;
		}
		stock_char(c);
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("The process ID is %s%d%s\n", ROUGE, pid, RESET);
	action.sa_sigaction = handler_server;
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
