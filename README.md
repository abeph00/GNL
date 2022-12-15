# getnextline
Get next line es un proyecto de 42.

En este proyecto desarrollaremos una funcion que permita leer una linea, que terminara en un salto de linea, de un file descriptor sin saber su 
tamaño. Cuando llames de nuevo a la funcion en el mismo archivo esta cogerá la siguiente linea.
Cuando la funcion retorne -1 habrá ocurrido un error, si devuelve 0 el archivo habrá terminado y si es 1 habrá leido una linea.
Comprenderemos atraves de este proyecto como los archivos son abiertos, leidos y cerrados en OS. 
