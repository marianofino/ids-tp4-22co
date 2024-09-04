# Trabajo Práctico Número 4

## Herramientas usadas en el repositorio

Este repositorio utiliza las siguientes herramientas:
1. [make](https://www.gnu.org/software/make) para gestionar la compilación de código fuente. 
1. [pre-commit](https://pre-commit.com) para validaciones generales de formato del repositorio
1. [doxygen](https://www.doxygen.nl/manual/index.html) para documentar el codigo

**Tabla de contenido**

- [Como usar este repositorio](#Uso-del-repositorio)
- [Licencia](#Licencia)

## Uso del repositorio

Después de clonar el repositorio debe ejecutar el siguiente comando:

```
pre-commit install
```

Para generar la documentación del proyecto se utiliza el siguiente comando:

```
make doc
```

Para compilar el proyecto se utiliza el siguiente comando:

```
make all
```

Para eliminar los archivos producto de la compilación

```
make clean
```

## Licencia

This template is distributed under the terms of the [MIT](https://spdx.org/licenses/MIT.html) license.
