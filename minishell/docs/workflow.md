
# Estructuración de trabajo minishell

## Parser / Analizador

Es la parte del programa encargada de **leer, comprender y traducir un comando** a un formato con el que el intérprete pueda trabajar y de **verificar la validez** de la entrada respecto a un conjunto de **reglas** y generar un error si el comando no es válido. Esta compuesto por los siguientes pasos:

### **Lexer - Análisis léxico**

El lexer identifica el token o elemento en la string de entrada*(input).
**Covenciones léxicas de shell**
Los tokens o elementos se clasificarán por su contexo inmediato de acuerdo con las siguientes reglas aplicadas en orden:
1. Si el token es un operador, resultará el id del token para el operador.
2. Si la string consta de dígitos y el carácter delimitador es '<' o '>', se devolverá el id de token **IO_NUMBER**
3. De lo contrario, se obtiene el id de token **TOKEN**
Una mayor distinción en **TOKEN** depende del contexto. Puede ser que **TOKEN** sea **NAME**, **WORD** o una de las palabras reservadas a continuación.
**Reglas gramaticales de Sell**
1. [Nombre del comando]
Cuando el token es exactamente una palabra reservada, el id del token será esa palabra reservada, en caso contrario el id será **WORD**.
*Los carácteres **"** se retienen en el token, las cadenas entre comillas no se pueden reconocer como palabras reservadas.*
2. [Redirección <, <<, >>, > hacia el nombre del archivo]
La redirección abre y cierra archivos para bash o para cualquier comando.
[fd] < word -> redirección de entrada, abre el archivo resultante de word en el fd designado-> Salida estandar [0].
[fd] > word -> redirección de salida, abre el archivo word y almacena la salida. **REVISAR BIEN ESTA DEFINICIÖN**
[fd] >> word -> Hace que el archivo que resulte de la expansión de word se cree y se abra para su salida en el fd designado. Si el archivo no existe se creará (O_APPEND).
[fd] << word -> Permite la redirección de líneas posteriores leidas por shell a la entrada de un comando (*"in-file"*). 
El documento se tratará como una sola palabra que comienza despues del salto de línea y continúa hasta que haya una línea que contenga el delimitador y un salto de linea sin carácters en blanco por medio.
