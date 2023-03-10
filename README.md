# Proyecto de video juego Laboratorio I 


- Alumna: Afonso de Souza Noelia
- Laboratorio de Computación I
- Universidad Tecnológica Nacional FRGP



----------------
## Introducción
----------------

Este proyecto consiste en "El Gran Cerdo": un juego de dados para dos jugadores, el cual tiene como objetivo sumar la mayor cantidad de puntos de victoria en un total de 5 rondas. La suma del puntaje depende de diferentes situaciones que se pueden dar en el juego. 
El menú contiene los siguientes items: "Jugar",  "Instrucciones", "Estadisticas", y "Participantes":

![Menu 1](https://user-images.githubusercontent.com/122423086/211717638-fa2b56f2-e1f1-4aa0-81e7-76042ab31ec2.jpg)


-------------
## Instrucciones del juego
------------
Este item contiene notas sobre cómo jugar y cómo sumar puntos:

![4-instrucciones 2](https://user-images.githubusercontent.com/122423086/211718039-4bd8b551-8865-40b2-b3c3-dfde59f7871f.jpg)


---------------
## Demostración del proyecto paso a paso
----------------

Para comenzar el juego se debe seleccionar la opción N°1 desde el menú "Jugar". Luego, el sistema pide los nombres de ambos jugadores, y se lanzan los dados para determinar cuál de los dos jugadores empieza:

![A jugar b](https://user-images.githubusercontent.com/122423086/211718204-65be46c1-d7e8-41c8-a5ce-b1015d0e2348.jpg)


El juego está compuesto por cinco rondas por jugador y en cada ronda el jugador dispone de ilimitados lanzamientos, hasta que salga un "AS", situación en la que se cede el turno al otro jugador.
En cada lanzamiento el jugador tira los dados y se analizan los valores de las caras. El puntaje y la situación de ambos jugadores se puede visualizar en la cabecera del juego (cantidad de trufas acumuladas, numero de ronda, cantidad de lanzamientos, etc):

![A jugar 2](https://user-images.githubusercontent.com/122423086/211718491-cc44fc81-90cd-4677-9247-340b992eb3e9.jpg)


Cuando finalizan las rondas, se determina el puntaje final (PDV = puntos de victoria) a partir de los siguientes hitos en el juego:

![A jugar 3](https://user-images.githubusercontent.com/122423086/211718498-74ca5acd-4686-4c92-8eee-f7a7d1eba299.jpg)

Para el desarrollo del mismo se utilizó C++.
