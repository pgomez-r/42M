/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explicacion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:06:38 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/03/22 10:57:31 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void fila(int columnas, char *caracteres)
{
    int contador;
    contador = 0;

    while (contador < columnas)
    {
        if (contador == 0)
        {
            ft_putchar(*(caracteres));
        }
        else if (contador == columnas - 1)
        {
            ft_putchar(*(caracteres + 2));
        }
        else
        {
            ft_putchar(*(caracteres + 1));
        }
        contador++;
    }

    ft_putchar('\n');
}

void caja(int columnas, int filas, char *caracteres)
{
    int contador;
    contador = 0;

    while (contador < filas)
    {
        if (contador == 0)
        {
            fila(columnas, caracteres);
        }
        else if (contador == filas - 1)
        {
            fila(columnas, caracteres + 6);
        }
        else
        {
            fila(columnas, caracteres + 3);
        }
        contador++;
    }
}

void rush(int x, int y)
{
    caja(x, y, "o^o+^#V W");
}

int main()
{
    rush(5, 4);
    return (0);
}
