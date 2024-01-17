/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tools_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:59:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/01/14 18:17:53 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*Llamar a la función cuando haga falta dividir y añadir elementos, con un if 
o funcion check antes en cada ft_token, si solo hay que catalogar el elemento
lo hacemos fuera, si hay que separar sus partes se hace aquí y se cataloga la
que estamos buscando, el resto queda indefinida = '0'*/
/**
 * TODO: ft_free_arr justo antes de free(in->elements) da doble free -> FIX!
 */
t_element	*ft_arr_update(t_input *in, int i, char c)
{
	char		**new_text;
	t_element	*new_arr;
	int			new_size;
	int			size;

	size = in->n_elements;
	new_text = ft_element_split(in->elements[i].data, c);
	new_size = in->n_elements + (int)ft_strdlen(new_text) - 1;
	new_arr = malloc(sizeof(t_element) * new_size);
	in->n_elements = new_size;
	ft_fill_arr(in, new_arr, i, new_text);
	ft_tag_type(new_arr, i, (int)ft_strdlen(new_text), c);
	ft_totalfree(new_text);
	ft_free_arr(in, size);
	free(in->elements);
	return (new_arr);
}

/*Una especie de split pero que también incluye el char que le pasamos
para separar en una cadena propia -> "ls|la" == "ls", "|"", "la"*/
char	**ft_element_split(char *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = malloc(sizeof(char *) * (ft_count_elements(str, c) + 1));
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (i > j)
			tab[k++] = ft_savewords(str + j, i - j);
		if (str[i] == c)
		{
			tab[k++] = ft_write_token(c);
			i++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

/*Esta función rellena el array nuevo de elementos, usamos un contador para
movernos en el array nuevo, otro para movernos en el antiguo y otro solo
para recorrer la tabla de cadenas a copiar cuando encontremos el punto 
donde insertar los elementos nuevos
Mientras no estemos en el punto a insertar (target) copiamos en el nuevo
los datos y tipo del elemento correspondiente del array original; cuando
lleguemos al target, copiamos al campo data de los nuevo elementos cada
str de tab y asignamos los type a 0*/
void	ft_fill_arr(t_input *in, t_element *new_arr, int tar, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < in->n_elements)
	{
		if (i == tar)
		{
			k++;
			j = -1;
			while (tab[++j] != NULL)
			{
				new_arr[i].data = ft_strdup(tab[j]);
				new_arr[i++].type = '0';
			}
		}
		else
		{
			new_arr[i].data = ft_strdup(in->elements[k].data);
			new_arr[i++].type = in->elements[k++].type;
		}
	}
}

/*Misma idea que arr_update pero orientada a las redirecciones "dobles",
para separar >> o << en un elemento independiente y catalogarlo (o solo lo
último, si ya se encuentra como elemento independiente) - Puede servir como
base para otra función si hace falta contemplar || como operador lógico*/
/**
 * TODO: ft_free_arr justo antes de free(in->elements) da doble free -> FIX!
 */
t_element	*ft_db_redirs(t_input *in, int i, char c)
{
	char		**new_text;
	t_element	*new_arr;
	int			new_size;
	int			size;

	size = in->n_elements;
	new_text = ft_dbredir_split(in->elements[i].data, c);
	new_size = in->n_elements + (int)ft_strdlen(new_text) - 1;
	new_arr = malloc(sizeof(t_element) * new_size);
	in->n_elements = new_size;
	ft_fill_arr(in, new_arr, i, new_text);
	ft_tag_redtype(new_arr, i, (int)ft_strdlen(new_text), c);
	ft_totalfree(new_text);
	ft_free_arr(in, size);
	free(in->elements);
	return (new_arr);
}

/*Otro split, misma idea que el element_split que además de separar
guarda el char separador en su propia cadena, pero aquí siendo dos char
para << o >> - De nuevo, puede servir para || y && si lo necesitamos*/
char	**ft_dbredir_split(char *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = malloc(sizeof(char *) * ft_count_elements(str, c));
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (i > j)
			tab[k++] = ft_savewords(str + j, i - j);
		if (str[i] == c)
		{
			tab[k++] = ft_save_dbred(c);
			i += 2;
		}
	}
	tab[k] = NULL;
	return (tab);
}
