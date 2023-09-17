/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 08:30:54 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/17 23:30:33 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*La idea es parecida a ft_list_foreach, de nuevo nos pasan una función como
argumento a ft_list_remove_if, en este caso sabemos que esa función nos 
devuelve un int 0 o 1 (true/false) y que tiene que recibir dos valores int
como sus propios argumentos ->  int cmp(int a, int b)
El int b de la función cmp lo recibimos en la nuestra como data_ref, y el 
int a con el que lo compara será el elmento data de cada nodo de la lista*/

/*IMPORTANTE -> Esta función trabaja con doble puntero a lista, por lo que hay
que tener clara la sintaxis, yo me lio bastate... 
Como norma que muy general: los '*' en los prototipos de las funciones son 
para indicarnos que se trata de una variable de tipo puntero, pero para usar 
la variable puntero como tal dentro de la función lo "restamos", por lo que 
si tenemos '**' al usarlo dentro de la función pondremos un solo '*', y si 
solo tenía uno en el prototipo, usaremos la variable sin el '*'
Es importante tenerlo en cuenta porque si usamos un asterisco de más, imitando
la declaración del prototipo, a lo que accedemos es al contenido de la dirección
a la que apunta, y no al puntero o dirección en si*/

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*aux;

	if (!begin_list || !(*begin_list))
		return ;
	aux = *begin_list;
	if (cmp(aux->data, data_ref) == 0)
	{
		*begin_list = aux->next;
		free(aux);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	aux = *begin_list;
	ft_list_remove_if(&aux->next, data_ref, cmp);
}

/* Vamos a trabajar con recursividad, creamos un puntero a lista auxiliar que va
a guardar una "copia" de la posición actual en la lista antes pasarle la función
cmp, si esta devuelve 0 significa que los valores comparados coinciden, hay que
eliminar ese nodo de la lista porque está duplicado
En ese caso avanzamos el puntero de la lista original al siguiente de la aux,
borramos el nodo aux y llamamos de nuevo a la función (recursiva)
Cuando no se cumpla cmp == 0, hacemos lo mismo pero sin liberar aux, es decir,
volvemos apuntar aux a la posición donde está begin_list y llamamos a nuestra 
función de nuevo
Al principio de la función siempre comprobamos si hemos llegado al final de lista
comprobando begin_list y (*begin_list) -doble puntero-, esta es nuestra condición
para "romper" la recursividad y que termine de ejecutarse la función y todas las
ejecuciones pendientes
*/

/*IMPORTANTE -> cuando se cumple cmp == 0 llamamos recursivamente a remove_if
enviando como parámetro la lista "original" (begin_list), pero si no se cumple 
le enviamos un puntero al siguiente nodo de la lista auxiliar(&aux-next)*/

/*
#include <stdio.h>
#include <string.h>

void	print_list(t_list **begin_list)
{
	t_list *cur = *begin_list;
	while (cur != 0)
	{
		printf("%s\n", cur->data);
		cur = cur->next;
	}
}

int		main(void)
{
	char straa[] = "String aa";
	t_list *aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = straa;

	char strbb[] = "String bb";
	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strbb;

	char strcc[] = "String cc";
	t_list *cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strcc;

	char strdd[] = "String dd";
	t_list *dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strdd;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	t_list **begin_list = &aa;

	print_list(begin_list);
	printf("----------\n");
	ft_list_remove_if(begin_list, straa, strcmp);
	print_list(begin_list);
}
*/