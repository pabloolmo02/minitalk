/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:56:50 by aporras-          #+#    #+#             */
/*   Updated: 2025/04/15 22:11:12 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bitargument	g_bitargument;

void	handle_signal(int bit)
{
	if (bit == SIGUSR1)
		g_bitargument.c = (g_bitargument.c << 1) | 1;
	else if (bit == SIGUSR2)
		g_bitargument.c = (g_bitargument.c << 1) | 0;
	g_bitargument.recive++;
	if (g_bitargument.recive == 8)
	{
		if (g_bitargument.c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", g_bitargument.c);
		g_bitargument.c = 0;
		g_bitargument.recive = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %i\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		;
	return (0);
}