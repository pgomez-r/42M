# Minishell

## En este proyecto vamos a programar una pequeña shell

### Nuestro shell debe:
- [ ] Mostrar ``una entrada`` mientras espera un comando nuevo.
- [ ] Tener un ``historial`` funcional.
- [ ] Buscar y ejecutar el ejecutable correcto. (basado en la variable PATH o mediante del uso de rutas relativas o absolutas).
- [ ] No usar mas de una variable global.
- [ ] No interpretar comillas sin cerrar o carácteres especiales no especificados en el enunciado como ``\``o ``;``.
- [ ] Gestionar que la ``'`` evite que el shell interprete los metacaracteres en la secuencia entrecomillada.
- [ ] Gestionar que la ``"``evite que el shell interprete los metacaracteres en la secuencia entrecomillada exceptuando ``$``.
- [ ] Implementar ``redirecciones:``
	- [ ] ``<`` debe redirigir input.
	- [ ] ``>`` debe redirigir output.
	- [ ] ``<<`` debe recibir un delimitador, despues lee del input de la fuente actual hasta que una línea que contenga solo el delimitador aparezca. Sin embargo, no necesita actualizar el historial.
	- [ ] ``>>``debe redirigir al output en modo append.
- [ ] Implementar ``|`` el output de cada comando en la pipeline se conecta a través de un pipe al input del siguiente comando.
- [ ] Gestionar las variables de entorno (``$``seguidos de caracteres) que deberán expandirse a sus valores.
- [ ] Gestionar ``$?``, que deberá expandirse al estado de salida del comando mas reciente ejexutado en la pipeline.
- [ ] Gestionar ``ctrl-C ctrl-D ctrl-\``, deberá comportarse como en bash.
- [ ] Cuando sea interactivo:
	- [ ] ``ctrl-C`` imprime una nueba entrada en una línea nueva.
	- [ ] ``ctrl-D`` termina el shell.
	- [ ] ``ctrdl-\`` no hace nada.
- [ ] Debe implementar los ``builts-ins:``
	- [ ] ``echo`` con la opción ``-n``.
	- [ ] ``cd`` solo con una ruta relativa o absoluta.
	- [ ] ``pwd`` sin opciones.
	- [ ] ``export`` sin opciones.
	- [ ] ``unset`` sin opciones.
	- [ ] ``env`` sin opciones o args.
	- [ ] ``exit`` sin opciones.

* La función readline puede producir algunos leaks.

## Bonus

- [ ] ``&& y ||`` con parentesis para prioridades.
- [ ] Los wildcards ``*`` deben funcionar para el directorio actual.

# Cazi nah abeh!!!