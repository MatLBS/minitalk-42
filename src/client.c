/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:50:36 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/12 11:23:26 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_sig;

void	handle_client(int signal, siginfo_t *info, void *context)
{
	static int	i;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
	{
		g_sig = 1;
		i++;
	}
	else
	{
		ft_printf("Nombre de bits reçus : %d\n", i - 7);
		exit(0);
	}
}

void	send_sig(pid_t	pid_server, char c)
{
	int	shift;
	int	compteur;

	shift = 7;
	while (shift >= 0)
	{
		compteur = 0;
		if ((c >> shift) & 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		while (g_sig == 0)
		{
			if (compteur == 200)
			{
				ft_printf("%s\n", "Le serveur ne répond pas");
				exit(1);
			}
			usleep(100);
			compteur++;
		}
		g_sig = 0;
		shift--;
	}
}

int	main(int ac, char **av)
{
	pid_t				pid_server;
	struct sigaction	action;
	int					i;

	if (ac != 3)
		return (ft_printf("Usage : ./client \"PID\" \"String\"\n"), 0);
	pid_server = ft_atoi(av[1]);
	if (pid_server <= 0)
		return (0);
	action.sa_sigaction = handle_client;
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	i = 0;
	while (av[2][i])
	{
		send_sig(pid_server, av[2][i]);
		i++;
	}
	send_sig(pid_server, '\0');
	return (0);
}
