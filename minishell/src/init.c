/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:32:32 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/01/14 18:17:48 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Archivo para funciones que inicien nuestras structs, si nos pasamos de
funcionemos podemos ir sacando a archivos utils.c las auxiliares (como
ft_split_env por ejemplo)*/

#include "../inc/minishell.h"

/*Función para guardar el input que está en formato str después de readline en 
el formato de doble matrix y array de estructuras que queremos para usarlo
En el mismo bucle podemos ir llamando a la función lexer cuando la tengamos*/
void	ft_fill_input(t_input *in, char *st)
{
	int	i;

	in->sp_input = ft_split(st, ' ');
	in->n_elements = (int)ft_strdlen(in->sp_input);
	in->elements = malloc(sizeof(t_element) * in->n_elements);
	i = -1;
	while (in->sp_input[++i] != NULL)
	{
		in->elements[i].data = ft_strdup(in->sp_input[i]);
		in->elements[i].type = '0';
	}
	ft_totalfree(in->sp_input);
	in->sp_input = NULL;
}

/*A esta función le entra una variable de entorno completa en una str
Lo que hace es dividirla y guardar por un lado el nombre de la variable (antes
de '=') y por otro el contenido o ruta (después de '='), ambos se quedan
guardados por separado en la struct que tenemos para cada variable de entorno*/
void	ft_split_env(t_data *d, char *var, size_t x)
{
	int	i;
	int	j;

	i = 0;
	while (var[i] != '=' && var[i] != '\0')
		i++;
	d->env_arr[x].title = malloc(sizeof(char) * i + 1);
	i = 0;
	while (var[i] != '=' && var[i] != '\0')
	{
		d->env_arr[x].title[i] = var[i];
		i++;
	}
	d->env_arr[x].title[i] = '\0';
	i++;
	j = i;
	while (var[i] != '\0')
		i++;
	d->env_arr[x].line = malloc(sizeof(char) * ((i - j) + 1));
	i = j - 1;
	j = -1;
	while (var[++i] != '\0')
		d->env_arr[x].line[++j] = var[i];
	d->env_arr[x].line[j] = '\0';
}

/**
 * TODO: fix '=' cuando no hay o hay varios! (Gracias Rosana =D)
 */

/*De momento solo copia las variables de entorno, más adelante podemos inciar
aquí también variables que vayamos añadiendo a la struct general*/
void	ft_init(t_data *d, char **env)
{
	size_t	i;

	d->rl_input = NULL;
	d->env_dup = env;
	d->env_arr = malloc(sizeof(t_env) * ft_strdlen(d->env_dup));
	i = 0;
	while (i < ft_strdlen(d->env_dup))
	{
		d->env_arr[i].full = ft_strdup(d->env_dup[i]);
		ft_split_env(d, env[i], i);
		i++;
	}
}

/*ft_init_pipes no se usa en el proceso del primer init que llamamos
en el main, pero la dejo por aquí porque es función de inicialización*/
void	ft_init_pipes(t_input *in)
{
	int	i;

	in->pipes = malloc(sizeof(*in->pipes) * (in->cmd_n - 1));
	if (!in->pipes)
	{
		ft_printf_error("cascaribash: malloc error\n");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < in->cmd_n - 1)
	{
		if (pipe(in->pipes[i]) == -1)
		{
			ft_printf_error("cascaribash: pipe error\n");
			exit(EXIT_FAILURE);
		}
	}
}
