# Diseño y Programación Seguras - Ejercicios de C - pbarrn00

_Prácticas de la asignatura **Diseño y programación seguras** del máster universitario de investigación en Ciberseguridad de la Universidad de León_

## Dinámica de la prácticas 🚀

Las prácticas realizadas durante la asignatura de diseño y programación seguras se basan es estudiar y analizar las diferentes reglas y recomendaciones propuestas por el CMU CERT para la programación segura en C. Para ello, se han realizado ejercicios de programación en C que se encuentran en los directiros lab de este repositorio. Estos ejercicios se han realizado en el entorno de desarrollo de Visual Studio Code, por lo que se recomienda su uso para la ejecución de los mismos.

### Pre-requisitos 📋

_Librerías necesarias para la compilación y ejecución de los ejercicios_

```
gcc (Raspbian 8.3.0-6+rpi1) 8.3.0
rats (RATS version 2.4.1)
perf (perf version 4.19.75-v7+)
gdb (GNU gdb (Raspbian 8.2.1-2+b3) 8.2.1)
cppchecker (Cppcheck 1.86)
splint (Splint 3.1.2)
valgrind (valgrind-3.15.0)
vera++ (Vera++ 1.3.0)
```

## Archivos 📦

```
.
├── 📂 CMU-INT Reminder                     # Ejercicios de programación segura en C Reglas INT del CMU CERT
│   └── 📄 CMU-INT-Example.c
├── 📂 lab1-strings-pbarrn00                # Ejercicios de programación segura en C Reglas STR del CMU CERT
│   ├── 📄 ejemplo1.c
│   ├── 📄 ejemplo2.c
│   ├── 📄 Makefile
│   └── 📄 README.md
├── 📂 lab2-unit-tests-pbarrn00             # Ejercicios de programación segura con test unitarios
│   ├── 📄 CMakeLists.txt
│   ├── 📄 exampleFunction.cpp
│   ├── 📄 Makefile
│   ├── 📄 README.md
│   ├── 📄 runTests
│   └── 📄 tests.cpp
├── 📂 lab3-variable-init-pbarrn00          # Ejercicios de programación segura Reglas de inicio de variables CMU CERT
│   ├── 📂 DLCblock-Recommendations
│   │   ├── 📄 example1.c
│   │   ├── 📄 example2.c
│   │   ├── 📄 fib.c
│   │   ├── 📂 img
│   │   │   ├── 📸 perftopdisassembly.png
│   │   │   ├── 📸 perftopfibodisassembly.png
│   │   │   ├── 📸 perftopfibo.png
│   │   │   └── 📸 perftop.png
│   │   ├── 📄 Makefile
│   │   └── 📄 README.md
│   └── 📂 DLCblock-Rules
│       ├── 📄 example1.cpp
│       ├── 📄 example2.cpp
│       ├── 📄 example3_broken.cpp
│       ├── 📄 example3.cpp
│       ├── 📄 main.cpp
│       ├── 📄 Makefile
│       └── 📄 README.md
├── 📂 lab4-concurrency-pbarrn00            # Ejercicios de programación segura Reglas de concurrencia CMU CERT
│   ├── 📄 example1.c
│   ├── 📄 example1.o
│   ├── 📄 example2.c
│   └── 📄 example2.o
├── 📂 lab5-heap-overflow-pbarrn00              # Práctica de desborde de heap en C
│   ├── 📄 address.txt
│   ├── 📄 DPS_PracticaSimpleOverflow.pdf
│   ├── 📄 h1
│   ├── 📄 h2
│   ├── 📄 h3
│   ├── 📄 h4
│   ├── 📄 heap0
│   ├── 📄 heap0.c
│   ├── 📂 img
│   │   ├── 📸 compile.png
│   │   ├── 📸 crash.png
│   │   ├── 📸 disass_nowinner.png
│   │   ├── 📸 disass_winner.png
│   │   ├── 📸 h1.png
│   │   ├── 📸 h2.png
│   │   ├── 📸 h3.png
│   │   ├── 📸 h4.png
│   │   ├── 📸 heap_observe.png
│   │   ├── 📸 inject.png
│   │   ├── 📸 rip.png
│   │   ├── 📸 string_mem.png
│   │   └── 📸 target_rip.png
│   └── README.md
├── 📂 lab6-stack-overflow-pbarrn00             # Práctica de desborde de pila en C
│   └── 📄 buffero.c
└── 📄 README.md
```
## Indicaciones para la ejecución de las prácticas 📖

#### Comprensión de las reglas CMU CERT 📱
La mayoría de las practicas se basan en la comprensión de las reglas CMU CERT, por lo que se recomienda la lectura de las mismas para una mejor comprensión de los ejercicios realizados. Las reglas se encuentran en el siguiente enlace: [CMU CERT C Coding Standard](https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard)

#### Ejecución de los ejercicios 📱
Para la ejecución de los ejercicios se recomienda el uso del entorno de desarrollo **Visual Studio Code**, ya que se ha utilizado para la realización de las prácticas. Para la compilación de los ejercicios se ha utilizado el compilador **gcc**, por lo que se recomienda su uso para la compilación de los mismos. Para la ejecución de los ejercicios se ha utilizado el depurador **gdb**, por lo que se recomienda su uso para la depuración de los mismos.

#### Guía de la práctica de heap overflow 📱
Para la práctica de heap overflow se ha seguido una guía simple del proceso de explotación de un buffer overflow, la cual se encuentra en el siguiente enlace: [DPS Practica Simple Overflow](https://samsclass.info/127/proj/p7-heap0.htm)

## Construido con 🛠️

* [RPi 4 Model B](https://www.amazon.es/NinkBox-Actualizada-Alimentación-Interruptor-Ventilador/dp/B07ZV9C6QF) - Raspberry Pi 4 Model B 4GB RAM
* [Docker](https://docs.docker.com/engine/release-notes/) - Docker version 20.10.21
* [Raspbian](https://releases.ubuntu.com/22.04/) - Raspbian GNU/Linux 10 (buster)


## Autores ✒️


* **Pablo Javier Barrio Navarro** - *Realización de la Práctica SNORT* - [Pablo Javier Barrio Navarro](https://github.com/pbarrn00) 
* **Francisco Javier Rodríguez Lera** - *Propuesta de las Prácticas* - [Francisco Javier Rogríguez Lera](https://github.com/fjrodl)

## _My Social Media_ 🔗

* [Youtube](https://www.youtube.com/channel/UC5waeaJaVlue9qGkHp4557Q)  📢
* [Github](https://github.com/pbarrn00) 😺
* [LinkedIn](https://github.com/pbarrn00) ☑️
* [Twitter](https://twitter.com/pablosky157) 🐦
* [Onkisko Web](https://onkisko.es/) 📰



---
⌨️ con ❤️ por [NoobInTheNet](https://github.com/pbarrn00) 😊