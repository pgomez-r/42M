/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell_commented.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:54:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/03/22 10:37:40 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> //man strcmp
#include <unistd.h> 
#include <sys/wait.h> //man waitpid

/*Función para imprimir errores, write con fd2 (stderr)
Siempre devuelve 1 porque la llamamos cuando detectamos un error, va en cadena:
ej. ft_cd si hay error hace return(ft_error), termina devolviendo 1, que se
iguala en main a stat, que es la variable devuelve siempre el programa*/
int	ft_err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

/**
 * @brief ft_cd recibe los argumentos a partir de "cd", si no hay exactamente
 * 	2 argumentos (contando con "cd"), return + error
 * Se ejecuta chdir, si falla return + error / resto de casos return (0)
 * @param av argumentos (matriz de cadenas - char **), como antes hemos
 * 	movido el puntero, la función recibe la matriz desde el punto donde
 * 	este se quedó apuntando, en este caso "cd" + todo lo que le sigue
 * @param i contador de argumentos, lo hemos aumentado antes de enviarlo a la
 * función, desde el puntero en "cd" hasta "|", ";" o NULL; lo usamos para 
 * 	comprobar si el numero de argumentos es correcto antes de ejecutar
 */
int	ft_cd(char **av, int i)
{
	if (i != 2)
		return (ft_err("error: cd: bad arguments\n"));
	else if (chdir(av[1]) == -1) //solo se ejecuta si sabemos que hay 2 argumentos, el [0] es "cd", asi que chdir al [1]
		return (ft_err("error: cd: cannot change directory to "), ft_err(av[1]), ft_err("\n"));
	return (0);
}

/**
 * @brief ft_exe va a intentar ejecutar el comando;
 * 1) comprueba si hay pipe después del comando
 * 2) hace fork (indiferentemente de si hay pipe o no, siempre!)
 * 3) en el caso de haber pipe; 
 * 	father (pid > 0) intercambia STDIN con fd READ de pipe 
 * 	(dup2(fd[0], 0)) y cierra los dos fd del pipe (+error_protect)
 * 	child (pid == 0) intercambia STDOUT con fd READ de pipe 
 * 	(dup2(fd[0], 0)) y cierra los dos fd del pipe (+error_protect)
 * 4) el hijo siempre iguala av[i] a NULL, para "cortar" la matriz
 * 	de argumentos cuando el bloque de comando termina
 * 5) el hijo ejecuta con execve, justo una linea debajo hacemos return
 * 	con error de ejecución (porque execve si ejecuta correctamente hace
 * 	exit, por lo tanto solo se va a llegar a la siguiente linea si falla)
 * 6) el padre espera, con waitpid(pid, &stat, 0) y termina haciendo return
 * 	del exit stat del hijo (WEXITSTATUS)
 * @param av puntero a matriz de cadenas, llega a la función apuntando a la
 * 	cadena (argumento) que "toca" 
 * @param env variable de entorno, se va pasando desde el main
 * @param i contador de argumentos, se ha aumentado antes de pasarlo a la 
 * 	función, llega hasta "|", ";" o NULL, por lo que marca el final del bloque
 * 	de comando ("echo hola que dice ;[i] ls -la...")
 */
int	ft_exe(char **av, char **env, int i)
{
	int	fd[2];	//para hacer pipe si es necesario
	int	stat;	//codigo de salida
	int	is_pipe;//flag de pipe SI/NO
	int	pid;	//para igualar a fork y separar codigo father/child

	is_pipe = 0;
	if (av[i] && !strcmp(av[i], "|")) //si hay pipe, flag en 1 (proteger primero que av[i] exista!)
		is_pipe = 1;
	if (is_pipe && pipe(fd) == -1) //si hay pipe, inicializamos nuestro pipe + protección
		return (ft_err("error: fatal\n"));
	pid = fork(); //hacemos fork + protección
	if (pid < 0)
		return (ft_err("error: fatal\n"));
	else if (pid == 0) //CHILD
	{
		av[i] = NULL; //i marca el final de bloque de comando, como puede haber otro comando después, lo dejamos a NULL para "cortar"
		if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 //si hay pipe, intercambio de fds + protección
				|| close(fd[1]) == -1))								//el hijo intercambia la escritura - fd[1] y STDOUT(1)
			return (ft_err("error: fatal\n"));
		execve(*av, av, env);
		return (ft_err("error: cannot execute "), ft_err(*av), ft_err("\n"));
	}
	//FATHER - de aqui al final solo ejecuta el padre, no hace falta else if(pid > 0)...
	waitpid(pid, &stat, 0);
	if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 //si hay pipe, intercambio de fds + protección
			|| close(fd[1]) == -1))							//el padre intercambia la lectura - fd[0] y STDIN(0)
		return (ft_err("error: fatal\n"));
	return (WEXITSTATUS(stat));
}

/**
 * 0) ejecutamos solo si hay más de un argumento
 * 1) bucle exterior -> comprueba que haya un argumento después del actual, en ese
 * 	caso aumenta ++i, le suma al puntero de la matriz de argumentos el valor de i
 * 	para que empecemos a trabajar siempre desde el incio del comando actual
 * 	(la primera cadena/argumento de todos los que haya) y reinicia i a 0 para volver
 * 	a usar la variable como contador de elementos dentro de el bloque comando
 * 2) bluce interior -> primero cuenta los elementos del comando aumentando i, hasta
 * 	encontrar "|", ";" o fin de matriz; cuando termina compreba si la cadena a la
 * 	que apunta actualmente *av (que lo hemos dejado antes donde sabemos que está 
 * 	el primer argumento o cadena del comando) es "cd" para llamar a su función, en
 * 	cualquier otro caso, llama a ft_exe
 * 3) al salir del bucle interior, seguimos en el exterior, i se había quedado antes
 * 	en el "|", ";" o NULL, comprobamos entonces de nuevo si existe av[i] y av[++i],
 * 	si i había llegado a fin de matriz no se cumple y salimos, si estaba en | o ;,
 * 	volvemos a entar y a repetir el proceso anterior
 * @def	i = contador de arguementos para delimitar bloques de comandos  
 * @def	stat = codigo de salida, lo igualamos a ft_cd o ft_exe y es el return value
 * @details	LOS MENSAJES DE ERROR VIENEN EXPLICITADOS POR EL SUBJECT, NO CAMBIAR!
 */
int	main(int ac, char **av, char **env)
{
	int	i;
	int	stat;

	i = 0;
	stat = 0;
	if (ac > 1)
	{
		while (av[i] && av[++i])
		{
			av += i; //movemos el puntero de la matriz de cadenas a la posición que nos interesa, en el primer caso saltamos "./microshell"
			i = 0; //reiniciamos i para reciclarla, a partir de aqui contea solo los elementos o cadenas del bloque comando en el que estamos
			while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";")) //hasta pipe, coma o fin de matriz, aumenta i para saber cuantos elementos (cadenas) tiene el comando
				i++;
			//aquí ya sabemos cuandos elementos hay, ahora analizamos la primera cadena del bloque actual, usando el puntero *av (le habiamos sumado +=i para situarlo en el primer elemento)
			if (!strcmp(*av, "cd"))
				stat = ft_cd(av, i);
			else if (i) //en lugar de solo "else" para proteger el caso en que i quede en cero
				stat = ft_exe(av, env, i);
		}
	}
	return (stat);
}
