# Este es el script que usamos para mostrar en pantalla los datos del sistema que nos exige el
# subject del proyecto. Para obtener cada dato, crearemos una variable que contendrá el comando o
# comandos que nos devuelvan el dato que queremos mostrar. Luego, usando el comando wall, editamos 
# la forma en la que se mostrará cada dato en pantalla, ya que wall es un comando que muestra un
# mensaje en pantalla de consola y admite tanto texto entre comillas, como el valor de una variable.
# Podemos usar encabezados comentados para cada variable o grupo de variables, para que quede más
# claro para el usuario.

# para declarar variables en bash, establecemos el nombre de la variable (no necesita tipo, solo nombre)
# y le asignamos el valor que queremos que tenga, en nuestro caso el valor de un comando que debe ejecutar,
# la sintaxis sería "nombre_variable=$(comando)".

#!/bin/bash

# ARCH
arch=$(uname -a)

# uname muestra la información del sistema, -a (--all) muestra todo lo que se puede mostrar de la arquitectura

# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)

# grep busca una cadena de texto en el archivo /proc/cpuinfo, donde se encuentra información del procesador,
# y wc -l cuenta las líneas que coinciden con la cadena de texto que le pasamos a grep, esto lo hacemos porque
# si solo hay un procesador el archivo marcará 0, pero si hay más de uno mostrará toda la información de cada
# uno por separado, por lo que lo más sencillo es contar las líneas en las que aparezca "physical id".

# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# mismo proceso que antes, buscamos en el mismo archivo, con el comando grep, pero en este caso la cadena "processor"
# y luego contamos el número de líneas que coinciden con esa cadena.

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# El comando free muestra la información de la memoria RAM del sistema, --mega muestra la información en megabytes, y
# luego, con el comando awk "filtramos" la información obtenida por free, así conseguimos que cada una de las variables del
# grupo RAM muestren solo la información que queremos, por ejemplo para ram_use le pedimos que si la primera palabra de la 
# file es "Mem:", nos muestre la tercera palabra de esa fila, que este caso sabemos que será la memoria usada. En el caso
# del porcentaje, hacemos que awk filtre la información y luego muestre el resultado de la operación que le pasamos.

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')

# df == disk filesystem, muestra información completa de los discos del sistema, -m muestra la información en megabytes, luego usamos
# grep para buscar línas que contengan "/dev/" y que no contengan "/boot" (grep -v), ya que el boot es un disco que no nos interesa
# después volvemos a filtrar y mostrar la información de la manera deseada con el comando awk. 
# TOTAL: sumamos todos los valores de la colúmna 2, como tenemos que mostrar este valor en Gb, pero el resultado de df -m es en Mb, 
# hacemos que awk divida el resultado de la suma entre 1024 y que imprima solo 1 decimal (".1f")
# USE: sumamos todos los valores de la columna 3, que es la que nos interesa, y mostramos el resultado.
# PERCENT: sumamos todos los valores de la columna 3 y de la columna 2, y luego hacemos que awk muestre el resultado de dividir ambos
# totales multiplicado por 100

# CPU LOAD
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)

# vmstat muestra información del sistema, añadimos 1 2 para que muestre la información de un intervalo de 1 a 2 segundos
# tail -1 muestra la última línea del archivo, y awk muestra la columna 15, que es la que nos interesa, que es uso de CPU
# con el primer comando tenemos cpul (uso de cpu), ahora para obtner cpu_op (el porcentaje de uso de cpu libre), restamos 
# 100 - cpul, para imprimir el resultado con solo 1 decimal (cpu_fin), usamos printf "%.1f" y le pasamos la variable cpu_op		

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# who muestra información de los usuarios conectados, -b muestra la información del último inicio de sesión, y luego con awk
# filtramos la información para que de esa información solo muestre la fecha y la hora del último inicio de sesión (columnas 3 y 4)

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# lsblk muestra información de los discos del sistema, y con grep buscamos si hay algún disco que tenga "lvm" en su nombre
# luego hacemos un if, si el resultado de la búsqueda es mayor que 0, es decir, si hay algún disco con "lvm" en su nombre,
# mostramos "yes", si no, mostramos "no"

# TCP CONNEXIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

# ss muestra información de las conexiones establecidas, -ta muestra solo conexiones TCP, y luego con grep buscamos las líneas
# que contengan ESTAB (establecidas), y con wc -l contamos el número de líneas que coinciden con la búsqueda, para que el valor
# final de la variable tcpc sea el número de conexiones TCP establecidas

# USER LOG
ulog=$(users | wc -w)

# users muestra los usuarios conectados, y con wc -w contamos el número de palabras obtenidas, lo que nos dará el número de usuarios

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# hostname -I muestra la IP del host, ip link muestra información de las interfaces de red, y con grep buscamos las líneas que
# contengan "link/ether", y con awk mostramos la segunda columna de cada fila que coincida con la búsqueda, que será la dirección MAC

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

# journalctl recopila y administra registros del sistema, -_COMM=sudo filtra los registros de este comando y muestra solo los de sudo, 
# luego con grep buscamos las líneas que contengan COMMAND (ya que solo queremos los comandos sudo, de otra manera también tendría en
# cuenta inicios de sesión, por ejemplo), y con wc -l contamos el número de líneas que coinciden con la búsqueda para sacar el número

wall "	Architecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	CPU load: $cpu_fin%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"

# Como habíamos dicho antes, el comando wall mostrará en la pantalla del terminal de todos los
# usuarios un mensaje que le pasamos como parámetro. Realmente monitoring ejecuta wall, y este va
# llamando a cada variable, que a su vez ejecuta los comandos que hemos establecido para esta.
# Le damos la estructura que queramos, todo entre comillas, debe ser parecida al subject pero no
# idéntica, mientras incluya toda la información que nos piden.