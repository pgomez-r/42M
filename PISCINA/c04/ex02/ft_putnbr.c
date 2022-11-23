/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:19:31 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/23 15:33:16 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_putnbr recibe un entero y lo representa en pantalla, es decir, lo imprime
en chars se basa en el uso de recursividad, se llama así misma y, cada vez que
lo hace, envia el número dividido entre 10 (lo "descompone") y luego ,cuando 
termina de llamarse así misma, comienza a imprimir todos los restos (%10) de 
las divisiones, lo que será igual a cada último dígito del número entero 
(ej. 14%10 = 4)*/

#include <unistd.h>

void	ft_putchar(char nb)
{
	write(1, &nb, 1);
}

/*comprobamos si el número que entra es el mínimo int, si es así, imprimimos a 
caraperro, así nos ahorramos posibles conflictos
si es negativo, lo primero que imprimimos es el signo -, luego pasamos el número
a positivo para poder operar con el
mientras el módulo 10 de n no sea 0 (es decir, n >= 10), comenzamos la recursi-
-vidad, llamamos a putnbr con n/10
cuando nb sea menor que 10 (por lo que el dígito a imprimr es solo uno) solo se
cumple el ultimo if, que simplemente imprime ese digito en char con +'0'*/

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb / 10 != 0 && nb != -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	if (nb <= 9 && nb >= 0)
	{
		ft_putchar(nb + '0');
	}
}

/*cómo funciona la recursividad para imprimir el número final en orden: 
mientras n>10 la función vuelve a iniciarse con el entero con un dígito menos,
cuando solo queda un dígito, imprime ese y comienza a "terminar" todas las 
putnbr anteriores que no habían llegado a recorrerse enteras, ya que volvían a
llamar a putnbr, cada una de estas está usando el resto de la divisón (ese 
último dígito que le estamos quitando cada vez al entero), pero comienza a 
hacerlo desde la "ejecución" anterior de putnbr, de esa manera, siempre imprimime
el primer dígito que "quitamos" (el último en el número, la unidad) se imprime
el último, como debe quedar*/

// int	main()
// {
// 	ft_putnbr(152);
// }