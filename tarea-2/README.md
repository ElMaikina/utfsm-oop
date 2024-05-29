# Diseño y Programación Orientada a Objetos

## Grupo 18

- Miguel Soto Delgado, Rol 201973623-K
- Sebastián Moya, Rol 202330520-7
- Maximiliano Muñoz Hinojosa, Rol 202104526-0
- Joaquín Jara Hananías, Rol 202221028-1

## Requisitos

Tener la última versión de _Java_, _Javac_ y _Make_ instalados en su equipo. Software usado y sus versiónes correspondientes a continuación.

## Ejecución

Se asume que se tiene la ultima version de _JavaFX_ (22.0.1) instalados en _C:_ de Windows. Luego, para compilar el programa:

```
make

```
Alternativamente, para correrlo en sistemas UNIX (Linux y Mac) correr el siguiente comando:

```
sudo chmod +x compilar_y_correr.sh
./compilar_y_correr.sh

```
_*Importante*: La tarea fue probada en MacOS y Arch Linux, de ser que no funcione en otro sistema operativo basado en UNIX, cambiar la direccion de la libreria acorde a su distribucion correspondiente._

## Diagramas

El codigo incluye una diagramacion de las clases generada por StarUML, esta muestra las clases, asociaciones, jerarquia y estrcutura general del programa. A grandes rasgos se uso el modelo de tipo _"Model-View-Controller"_ en donde _App_ es nuestra Interfaz y _Controller_ es nuestro Controlador. 

La Interfaz sirve como nuestra interaccion directa con el jugador, manejando los elementos de la vista, cargando el escenario y gestionando el ciclo del juego. 

Por otra parte el Controlador gestiona toda la logica del juego, mostrando el cambio de las estadisticas al pasar el tiempo, controlando la cantidad de items que se poseen en el inventario y modificando la salud / estado de la mascota en tiempo real.
