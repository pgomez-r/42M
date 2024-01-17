# PARSER
Es el encargado de tomar los tokens producidos por el lexer y construir una representación estructurada de los comandos que el usuario quiere ejecutar (**AST**-> Árbol de Síntaxis Abstracta -> *Es una representación jerárquica de la estructura de un programa o entrada. Cada nodo el AST representa un comando o una operación(redirección o pipe) y los hijos de cada nodo representan los args de ese comando u operación.*) 
Así podria funcionar (segun mi amigo el copiloto):
1. El parser recibe la lista de tokens del lexer.
2. Comienza a construir el AST. Cada comando es un nodo en el árbol, y los operadores de redirección y pipe determinan las relaciones entre los nodos.
3. Para cada token en la lista el parser crea un decide que hacer basandse en el tipo de token:
	* Si el token es un nombre de comando el parser crea un nuevo nodo en el AST para ese comando.
	* Si el token es una redirección o pipe, el parser crea una relación entre el comando actual y el siguiente comando en el AST.
	* Si el token es un arg de un comando (como *file.txt* en *ls file.txt*), el parser añade ese argumento al nodo del comando correspondiente en el AST.
4. Una vez que el parser ha procesado todos los tokens, devuelve el AST.
