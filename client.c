/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:48:55 by aporras-          #+#    #+#             */
/*   Updated: 2025/04/15 22:09:15 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
int	ft_atoi(const char *str)
{
	long int	i;
	long int	sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

void	send_signal(int pid, unsigned char *mesage, size_t len)
{
	int	i;
	int	bit;

	i = 0;
	while (len > 0)
	{
		bit = 0;
		while (bit < 8)
		{
			if ((mesage[i] >> (7 - bit) & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(42);
		}
		i++;
		len--;
	}
}

int	main(int argc, char **argv)
{
	int				pid;
	unsigned char	*mesage;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		mesage = (unsigned char *)argv[2];
		send_signal(pid, mesage, (ft_strlen((const char *)mesage) + 1));
	}
	else
		ft_printf("Sintax: %s [PID_servidor] [Mensage]", argv[0]);
}