# Trabajo Práctico 4

Repositorio correspondiente al Trabajo Práctico 4 de Ingeniería de Software de la CESE, FIUBA.

## Autor

### -Marco Rolón Radcenco

## Pasos previos

Este repositorio utiliza [pre-commit](https://pre-commit.com) para validaciones automáticas de formato y estilo. Asegúrese de tener instaladas las siguientes herramientas antes de trabajar con este repositorio:

1. pre-commit (<https://pre-commit.com/#install>)
2. cpp-check (<https://cppcheck.sourceforge.io>)

## Configuración Inicial

Después de clonar el repositorio, ejecute el siguiente comando para configurar los hooks de pre-commit:

```
pre-commit install
```

## Compilación del Proyecto

Para compilar el proyecto, simplemente ejecute el siguiente comando:

```
make all
```

Este comando generará el ejecutable principal en el directorio build.

## Generación de Documentación

La documentación del proyecto se puede generar usando Doxygen con el siguiente comando:

```
make doc
```

La documentación generada estará disponible en el directorio build.

## Limpieza del Proyecto

Para limpiar los archivos generados durante la compilación y la documentación, ejecute:

```
make clean
```

## Licencia

Distribuido bajo los términos de la licencia [MIT](https://spdx.org/licenses/MIT.html).
