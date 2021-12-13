# Factorización Prima de un Número (Serial)

## Autor
Estudiante: Luis Fernando Gomez Sanchez.

Correo: luis.gomez20@ucr.ac.cr.

Carnet: C03309.

## Problema a resolver

<p style='text-align: justify'>
El programa recibe de la entrada estándar un conjunto de números enteros que almacenará en memoria para luego calcular su factorización prima. Si la entrada recibe un número negativo, imprime 'invalid number' en la salida estándar; si la entrada recibe un 1 o un 0, imprime 'NA' en la salida estándar; si la entrada recibe un numero entero cualquiera, la salida estandar muestra su factorización prima; si la entrada estándar recibe cualquier otro conjunto de caracteres, la salida imprime un aviso de error. Además, el programa se detiene sin calcular la factorización prima únicamente si no logra almacenar de manera exitosa en memoria el número ingresado, indicando un error de memoria. El método de entrada debe ser de la siguiente forma:
</p>

```bash
1
7
25
87
378
1400
-40
```

<p style='text-align: justify'>
Una vez el usuario digita los números a los que desea calcular su factorización prima, procede a realizar la factorización de cada uno de los números ingresados, almacenando en memoria los números primos que corresponden a dicho número.
</p>

<p style='text-align: justify'>
Finalmente, el programada imprime en la salida estándar una lista con los números ingresados y su respectiva factorización prima de la siguiente forma:
</p>

```bash
1: NA
7: 7
25: 5^2
87: 3 29
378: 2 3^3 7
1400: 2^3 5^2 7
-40: invalid number
```

## Diseño

El diseño del programa se puede visualizar [aquí](design/README.md).

## Documentación

<p style='text-align: justify'>
La documentación del programa esta disponible gracias a la herramienta Doxygen. Para generarla, ingrese el siguiente comando en la línea de comandos:
</p>

```bash
make doc
```

<p style='text-align: justify'>
Una vez se corre el comando, se generará la documentación en el directorio /doc/ del directorio raíz del programa.
</p>

## Manual de Uso

### Compilación sin parámetros

<p style='text-align: justify'>
Para compilar el programa sin especificaciones, utilice el siguiente comando en la línea de comandos:
</p>

```bash
make
```

### Compilación con Casos de Prueba
<p style='text-align: justify'>
Para compilar el programa con los casos de prueba, ingrese el siguiente comando en la línea de comandos:
</p>

```makefile
make test
```
<p style='text-align: justify'>
<b>NOTA:</b> Para utilizar estos casos de prueba, de tener instalado el paquete icdiff para verificar los archivos. 
</p>

### Sanitizers

<p style='text-align: justify'>
Para compilar el programa con los sanitizers, ingrese uno de los siguientes comandos según el sanitizers que requiera en la línea de comandos:
</p>

#### Adress Sanitizer (Asan)
```bash
make asan
```
#### Memory Sanitizer (Msan)
```bash
make msan
```
#### UndefinedBehavior Sanitizer (UBSan)
```bash
make ubsan
```

### Valgrind

<p style='text-align: justify'>
Para compilar el programa con alguna herramienta de Valgrind, ingrese uno de los siguientes comandos según la herramienta que requiera en la línea de comandos:
</p>

#### Helgrind
```bash
make helgrind
```
#### Memcheck
```bash
make memcheck
```

### Compilar con varias herramientas a la vez

<p style='text-align: justify'>
Si desea compilar el programa con las herramientas Cpplint, Memcheck y Helgrind, además de generar la documentación del programa utilice el siguiente comando en la consola:
</p>

```bash
make all
```

### Reiniciar compilaciones

<p style='text-align: justify'>
Si desea utilizar otra herramientas para el compilado o desea compilar nuevamente el programa, utilice el siguiente comando antes de volver a compilar:
</p>

```bash
make clean
```

### Revisar formato del código

<p style='text-align: justify'>
Si desea revisar el formato del código fuente con Cpplint, ingrese el siguiente comando en consola:
</p>

```bash
make lint
```

### Correr el programa

<p style='text-align: justify'>
Para correr el programa una vez compilado el código fuente, utilice el siguiente comando:
</p>

```bash
./build/primefact_serial.o
```

## Créditos
- <p style='text-align: justify'>Diseño y desarrollo por Luis Fernando Gómez Sánchez; Correo: luis.gomez20@ucr.ac.cr. Año 2021.</p>
- <p style='text-align: justify'>El módulo de factorización está inspirado en el realizado por John Ortiz Ordoñez, disponible en este <a href="https://github.com/Fhernd/JavaScriptEjercicios/blob/master/Parte001/ex787-factores-primos-unicos-numero-funcion.js">enlace</a>.</p>
