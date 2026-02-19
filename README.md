# Sistema de Citas de Veterinaria

## Descripción

Este proyecto es un sistema de gestión de citas para una veterinaria desarrollado en C++. El sistema permite administrar veterinarios, paquetes y gestionar citas médicas.

**Curso:** Programación I 
**Ciclo:** 2023

## Características

El sistema incluye las siguientes funcionalidades:

### Mantenimiento de Veterinarios
- Agregar veterinario
- Buscar veterinario
- Modificar veterinario
- Eliminar veterinario
- Listar veterinarios

### Mantenimiento de Paquetes
- Agregar paquete
- Buscar paquete
- Modificar paquete
- Eliminar paquete
- Listar paquetes


## Estructura del Proyecto

```
Proyecto #2/
├── Principal.cpp      # Archivo principal con menú del sistema
├── Veterinario.h      # Clase para gestión de veterinarios
├── Cita.h             # Clase para gestión de citas
├── Paquetes.h         # Clase para gestión de paquetes
└── Utilitarios.h      # Clase con funciones auxiliares para interfaz
```

## Archivos de Datos

El sistema utiliza archivos binarios para almacenar la información:
- `Veterinario.dat` - Almacena los registros de veterinarios
- `Paquetes.dat` - Almacena los registros de paquetes
- `Cita.dat` - Almacena los registros de citas

## Requisitos

- Compilador de C++ (g++, MinGW, Visual Studio, etc.)
- Sistema operativo Windows

## Compilación

Para compilar el proyecto, utiliza tu compilador de C++ preferido:

```bash
g++ Principal.cpp -
```

O en Windows con Visual Studio:
```bash
cl Principal.cpp
```

## Uso

1. Compila el proyecto
2. Ejecuta el archivo ejecutable generado
3. Navega por el menú principal para acceder a las diferentes funcionalidades

## Notas

- Este proyecto fue desarrollado como parte del curso de Programación I, Ciclo 2023
- El sistema utiliza archivos binarios para el almacenamiento de datos
- La interfaz está diseñada para ejecutarse en consola de Windows


