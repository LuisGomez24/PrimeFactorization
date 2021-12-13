# Factorización Prima de un Número (Pthreads)

## Autor
Luis Fernando Gómez Sánchez.

luisfergs24@gmail.com

## Ambientes y Herramientas Utilizados

<ul>
  <li>Sistema Operativo: Linux (Debian)</li>
  <li>Lenguaje: C</li>
  <li>Control de concurrencia: Pthreads</li>
</ul>

## Problema a Resolver

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
abcd
```

<p style='text-align: justify'>
Una vez el usuario digita los números a los que desea calcular su factorización prima, procede a realizar la factorización de cada uno de los números ingresados, almacenando en memoria los números primos que corresponden a dicho número.

Finalmente, el programa imprime en la salida estándar una lista con los números ingresados y su respectiva factorización prima de la siguiente forma:
</p>

```bash
1: NA
7: 7
25: 5^2
87: 3 29
378: 2 3^3 7
1400: 2^3 5^2 7
-40: invalid number
invalid number
```

<p style='text-align: justify'>
La solución planteada resuelve el problema utilizando la cantidad de núcleos con las que cuente la máquina o con una cantidad específica que el usuario ingrese como parámetro al correr el programa. Estos hilos dividirán sus tareas a la hora de imprimir y de calcular los factores primos de cada número ingresado.
</p>

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

### Compilación sin Parámetros

<p style='text-align: justify'>
Para compilar el programa sin especificar la cantidad de hilos y crear únicamente tantos hilos como núcleos posea la máquina, utilice el siguiente comando en la línea de comandos:
</p>

```bash
make
```

### Compilación con Casos de Prueba
<p style='text-align: justify'>
Para compilar el programa con los casos de prueba, ingrese el siguiente comando en la línea de comandos:
</p>

```makefile
make test [CANTIDAD_DE_HILOS]
```

<p style='text-align: justify'>
<b>NOTA:</b> 

La cantidad de hilos que se desea ingresar se escribe como dato numérico entero positivo en la posición de <em>[CANTIDAD_DE_HILOS]</em>. Si se omite, se crearan tantos hilos como núcleos tenga la máquina.

Para utilizar estos casos de prueba, de tener instalado el paquete icdiff para verificar los archivos. 
</p>

### Sanitizers

<p style='text-align: justify'>
Para compilar el programa con los sanitizers, ingrese uno de los siguientes comandos según el sanitizers que requiera en la línea de comandos:
</p>

<p style='text-align: justify'>
<b>NOTA:</b> La cantidad de hilos que se desea ingresar se escribe como dato numérico entero positivo en la posición de <em>[CANTIDAD_DE_HILOS]</em>. Si se omite, se crearan tantos hilos como núcleos tenga la máquina.
</p>

#### Adress Sanitizer (Asan)
```bash
make asan [CANTIDAD_DE_HILOS]
```
#### Memory Sanitizer (Msan)
```bash
make msan [CANTIDAD_DE_HILOS]
```
#### UndefinedBehavior Sanitizer (UBSan)
```bash
make ubsan [CANTIDAD_DE_HILOS]
```

### Valgrind

<p style='text-align: justify'>
Para compilar el programa con alguna herramienta de Valgrind, ingrese uno de los siguientes comandos según la herramienta que requiera en la línea de comandos:
</p>

#### Helgrind
```bash
make helgrind [CANTIDAD_DE_HILOS]
```
#### Memcheck
```bash
make memcheck [CANTIDAD_DE_HILOS]
```

<p style='text-align: justify'>
<b>NOTA:</b> La cantidad de hilos que se desea ingresar se escribe como dato numérico entero positivo en la posición de <em>[CANTIDAD_DE_HILOS]</em>. Si se omite, se crearan tantos hilos como núcleos tenga la máquina.
</p>

### Compilar con Varias Herramientas

<p style='text-align: justify'>
Si desea compilar el programa con las herramientas Cpplint, Memcheck y Helgrind, además de generar la documentación del programa utilice el siguiente comando en la consola:
</p>

<p style='text-align: justify'>
<b>NOTA:</b> La cantidad de hilos que se desea ingresar se escribe como dato numérico entero positivo en la posición de <em>[CANTIDAD_DE_HILOS]</em>. Si se omite, se crearan tantos hilos como núcleos tenga la máquina.
</p>

```bash
make all [CANTIDAD_DE_HILOS]
```

### Reiniciar Compilaciones

<p style='text-align: justify'>
Si desea utilizar otra herramientas para el compilado o desea compilar nuevamente el programa, utilice el siguiente comando antes de volver a compilar:
</p>

```bash
make clean
```

### Revisar Formato del Código

<p style='text-align: justify'>
Si desea revisar el formato del código fuente con Cpplint, ingrese el siguiente comando en consola:
</p>

```bash
make lint
```

### Correr el Programa

<p style='text-align: justify'>
Para correr el programa una vez compilado el código fuente, utilice el siguiente comando:
</p>

```bash
./bin/primefact_pthreads [CANTIDAD_DE_HILOS]
```

<p style='text-align: justify'>
<b>NOTA:</b> La cantidad de hilos que se desea ingresar se escribe como dato numérico entero positivo en la posición de <em>[CANTIDAD_DE_HILOS]</em>. Si se omite, se crearan tantos hilos como núcleos tenga la máquina.
</p>

## Créditos

<ul style='text-align: justify'>
<li>Diseño y desarrollo por Luis Fernando Gómez Sánchez; Correo: luisfergs24@gmail.com. Año 2021.</li>
<li>El módulo de factorización está inspirado en el realizado por John Ortiz Ordoñez, disponible en este <a href="https://github.com/Fhernd/JavaScriptEjercicios/blob/master/Parte001/ex787-factores-primos-unicos-numero-funcion.js">enlace</a>.</li>
</ul>
