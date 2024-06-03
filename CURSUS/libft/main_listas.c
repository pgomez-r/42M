/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_listas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:10:47 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/23 13:19:09 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Vamos a hacer aquí un main y funciones para probar a toquetear las struct y 
listas a ver si me entra en la cabeza, cabessa*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h> 
// #include <unistd.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

/*Estamos declarando y definidiendo una variable tipo estructura y le damos 
el nombre de s_list, t_list == nodo, es el tipo de archivo de nodos de lista
Añadimos dentro de la misma un puntero a tipo void, void como "comodin", ya que 
content es lo que vamos a usar para añadir valor a cada nodo, y queremos que 
pueda ser de cualquier tipo de datos (char, int, long...)
Creamos otro puntero a tipo struct s_list (el tipo de dato que hemos definido
nosotros mismos ante, que hace referencia a nuestros nodos), con el nombre 
next, lo usaremos para enlazar nodos unos con otros, el primer content/nodo 
apuntará a next, y next a NULL para indicar que es el último nodo de la lista, 
así comienza digamos de cero, pero siguiento esa estructura siempre estarán todos
los nodos enlazados unos a otros por next, y el último a NULL, mientras mantenga
esta esctructa de referencia/punteros entre los nodos siempre podremos
localizar y modificar el orden de cada nodo por medio de refencia de punteros
Cerramos la declaración/definición de la struct list con } t_list; así tenemos 
nuestro tipo de variable nodo (no me explico/entiendo ni yo muy bien todavía)*/

// void	ft_printlst(t_list *head)
// {
// 	t_list	*temp;

// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		printf("%d\n", temp->content);
// 		temp = temp->next;
// 	}
// }
// /*Función para imprimir en pantalla la lista en orden, solo para comprobar
// con el main si estamos modificando como queremos la lista*/

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }
// /*Función para añadir nodos, "explicada en su .c"*/

// t_list	*ft_lstaddfront(t_list **head, t_list *toadd)
// {
// 	toadd->next = head;
// 	*head = toadd;
// 	return (toadd);
// }
// /*Función para añadir nodo a la head de lista*/

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*tmp;

// 	tmp = ft_lstnew(42);
// 	/*head = temp*/
// 	ft_lstaddfront(&head, tmp);
// 	tmp = ft_lstnew(2022);
// 	/*tmp->next = head*/
// 	ft_lstaddfront(&head, tmp);
// 	head = tmp;
// 	/*este mismo proceso se podría hacer con:
// 	for (int i=0; i<20; i++) {ft_strlnew(i) tmp->next = head head = temp}
// 	así añadiriamos 20 veces siempre al inicio de lista número de 0 a 20*/
// 	ft_printlst(head);
// 	return (0);
// }
/*solo con la función lstnew no puedo ir añadiendo nodos consecutivos, si 
quiero añadir más de uno y que no se sobreescriba hay que declarar dos punteros
a t_list y cada vez que llamo a la función con un valor nuevo, voy moviendo
el anterior a next antes de asignar el valor nuevo
tmp->next ("esto significa el puntero next de tmp, cada nodo tiene un puntero
next, un enlace digamos, al establecer que ese puntero es igual a head, estamos
moviendo el contenido que estaba donde vamos a colocar algo ahora, a la posicion
siguiente, lo hacemos, dejamos el hueco y entonces head = tmp")*/