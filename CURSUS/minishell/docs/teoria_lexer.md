# LEXER
Toma la entrada del usuario y la divide en **tokens**(*unidades básicas de significado en un comando*)
Ejemplo de funcionammiento:
1. Recibe la entrada como una string.
2. Recorre la cadena.
3. Cuando el lexer encuentra un espacio lo interpreta com el final de un token y lo almacena en una matriz de tokens(**split**).
4. Si encuentra un caracter especial (**; , |, &, etc.**) lo trata como un token por separado.
5. Devuelve la lista de tokens como una matriz.

También debería de manejar específicas de shell como la expansión de carácteres (reemplazar **$VAR** por el valor de la variable **VAR**),
el manejo de comillas (pueden cambiar como manejar los tokens)
En términos generales podrían manejarse de la siguiente manera:

**comillas->** Tanto simples **'** como dobles **"** se utilizan en los shell para **agrupar palabras en un solo token** incluso si contienen espacios. Además las comillas dobles permiten la expansión de variables mientras que las simples no.

**Expansión de variables->** Cuando el lexer encuentra un **$** seguido del nombre de una variable(**$PATH**) implica buscar el valor de la variable en el entorno y reemplazar el valor de la variable con su valor.
#### Redirecciones
Son operadores que cambian como se maneja la entrada y salida de comandos. Se tratan como tokens separados y pueden manejarse de la siguiente manera:
1. **Redirecciones de salida->** (**>** y **>>**) Redirigen la salida de un comando a un archivo. El token que sigue a este operador se considera el nombre del archivo al que se redirige la salida.

* **(>)** -> Si el archivo existe sobreescribirá el contenido del archivo.

* **(>>)** -> Si el archivo existe agrega la salida al final del archivo **O_APPEND**.

2. **Redirecciones de entrada->** (**<** y **<<**) Redirige la entrada de un comando desde un archivo.
* **(<)** -> Redirige la entrada de un comande desde un archivo. *Ej, sort < archivo.txt* tomará la entrada para *sort* desde *archivo.txt*.
* **(<<)** -> Tambien conocido como *here document* redirige la entrada desde el contenido de un documento que se proporciona directamente en la linea de comandos usando un delimitador final. Ej:
```bash
 cat << EOF 
 Hola, mundo!
 EOF
```
*cat* tomará la entrada desde el texto proporcionado entre *<< EOF* y *EOF*.