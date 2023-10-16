/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:35:30 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/10/15 21:02:03 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Prueba de las funciones ft_time con ejemplos sencillos de uso para ver si se
produce un desfase de tiempo*/
#include "incl/philo.h"

int	main(void)
{
	time_t	start_time;
	time_t	time_action;
	time_t	time_limit;
	time_t	time_stamp;
	int		i;

	i = -1;
	time_action = 200;
	time_limit = 520;
	start_time = ft_get_time();
	printf("Start_time: %ld\n", start_time);
	while (++i < 5)
	{
		ft_usleep(time_action);
		time_stamp = ft_get_time() - start_time;
		printf("[%ld]--philo[1]--ha terminado una acción\n", time_stamp);
	}
}
