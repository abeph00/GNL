<img src="https://raw.githubusercontent.com/JaeSeoKim/badge42/main/public/badge42_logo.svg" width ="10%"/>
<h1 align="center">
	Get next line
</h1>

<p align="center">
	<b><i>Development repo for 42 projects</i></b><br>

---

## 🗣️EN QUE CONSISTE

> _ El objetivo es crear una función que lea una linea hasta \n o EOF. Leerá  linea a linea hasta el final, con repetidas llamadas a la función get next line. Devolvera la linea que se acaba de leer(carácter n incluido). Si no hay nada mas que leer o si ocurre un error deberá devolver NULL. Deberá comportarse adecuadamente leyendo tanto de un archivo como de stdin.

## 📝QUE DEBERIAS SABER

> _Buffer: El buffer es un espacio temporal de memoria física el cual se usa para almacenar Ia información mientras se envía a otro lado. Su principal utilidad es transmitir información en sistemas en los cuales la velocidad a la que se obtiene o se manda la información es diferente a la velocidad a la que se procesa. A diferencia de la memoria cache almacena la información sin mantenerla mas que el tiempo que tarda en mandarse.

> _File descriptor: Un descriptor de archivo es un pequeño numero entero no negativo que ayuda a identificar un archivo dentro de un proceso(un programa funcionando en ese momento) mientras se utilizan recursos de entrenad/salida. Stdin: entrada estándar 0. Stdout: salida estándar 1, error stander 2.

> _VARIABLES ESTATICAS : No pueden ser accedidas desde otro fichero. Mantiene su valor a lo largo de toda la ejecución del programa independientemente del ámbito en el que están definidas. Si esta declarada fuera de las funciones. Sera accesible únicamente por el código que le siga en el mismo fichero. Si esta declarada dentro de una función, solo sera accesible desde esa función y mantendrá su valor entre ejecuciones de la función.

## 📈QUE VA A HACER CADA UNA DE LAS FUNCIONES

> _FT_READ
Será la función con la que leeremos el archivo de un descriptor de archivo en un bucle hasta detectar un \n o EOF. En bucle se repetirá hasta que la función read retorne 0 lo que significara que hemos llegado al final del archivo. Si retornara -1 habría ocurrido un error, por lo que liberaríamos toda la memoria alocada y terminaria devolviendo NULL. 

> _FT_LINE
Copiaremos la linea leída en un string, y alocaremos la memoria necesaria para ese string que es el que vamos devolver incluido el \n. Ademas gestionaremos que devuelva null si hay algún error o si hemos llegado al final del archivo.

> _FT_NEXTSTR
Primero avanzaremos str hasta el final  para que se sitúe en el siguiente string que vamos a copiar. Alocaremos memoria para guardar el siguiente string que debe leer el archivo. Crearemos otro string para guardas la siguiente linea. Liberaremos la memoria de str cuando hayamos terminado y gestionaremos también si no hay nada mas que leer o hay algún error que retorne NULL.

> _FT_STRCHR
Con esta función controlaremos que read funcione hasta que encuentre un salto de linea. Este sera el contenido del bff que luego pasar a ser nuestra str. IMPORTANTE: Aparecera en el bucle del while para que independientemente de cual sea tu BUFFER_SIZE, tu string sea hasta que encuentre un salto de linea.

> _FT_STRJOIN
Aqui haremos del buffer a la estatica. Guardaremos los caracteres leidos en una variable estatica.

## EL PROGRAMA
"get_next_line" es una función en el lenguaje C que se utiliza para leer una línea completa desde un archivo. La función utiliza un buffer de tamaño fijo para leer una cantidad de caracteres del archivo y luego procesa el contenido del buffer para buscar el final de línea ('\n').

La función recibe como argumento el descriptor de archivo (fd) correspondiente al archivo que se quiere leer. En la primera llamada a la función, se inicializa una variable estática llamada "str" con un valor nulo. En las siguientes llamadas a la función, esta variable "str" mantiene el contenido del archivo que aún no ha sido procesado.

La función "ft_read" se encarga de leer una cantidad de caracteres del archivo y almacenarlos en un buffer. Si el buffer se llena antes de encontrar un final de línea, la función continúa leyendo desde donde quedó la última lectura. La función devuelve un puntero a una cadena de caracteres que contiene el contenido del archivo leído hasta el final de línea o hasta el final del archivo.

La función "ft_line" recibe una cadena de caracteres y devuelve una nueva cadena que contiene todos los caracteres desde el inicio de la cadena original hasta el primer carácter '\n' encontrado. La función "ft_nextstr" recibe una cadena de caracteres y devuelve una nueva cadena que contiene todos los caracteres después del primer carácter '\n' encontrado en la cadena original.

En la función "get_next_line", se llama a "ft_read" para obtener una cadena de caracteres que contenga una línea completa desde el archivo. Luego, se llama a "ft_line" para obtener una nueva cadena que contenga la línea completa. La variable estática "str" se actualiza para que contenga el resto del archivo que aún no ha sido procesado.

La función devuelve un puntero a la nueva cadena que contiene la línea completa. Si la función llega al final del archivo, devuelve un valor nulo. En cada llamada sucesiva a la función, se procesa el contenido restante del archivo almacenado en la variable "str" hasta encontrar una nueva línea completa.
