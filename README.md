# Trabajo Práctico 4 - IdS

-----

# Tabla de contenidos

- [Trabajo Práctico 4 - IdS](#trabajo-práctico-4---ids)
- [Tabla de contenidos](#tabla-de-contenidos)
- [Descripción](#descripción)
- [Como usar](#como-usar)
- [Configuración inicial (LINUX)](#configuración-inicial-linux)
- [Uso](#uso)
  - [Compilación](#compilación)
  - [Documentación](#documentación)
- [License](#license)
- [Autor](#autor)

# Descripción

Solución al trabajo práctico de la materia Ingeniería de Software (IdS) de la Carrera de Especialización en Sistemas Embebidos (CESE) de la Facultad de Ingeniería de la Universidad de Buenos Aires (FIUBA).

# Como usar

Este repositorio utiliza pre-commit para validaciones automáticas de formato y estilo. Debe tener instaladas las siguientes herramientas antes de trabajar con este repositorio:

1. [pre-commit](https://pre-commit.com/#install)
2. [cppcheck](https://cppcheck.sourceforge.io/)
3. [clang-format](https://clang.llvm.org/docs/ClangFormat.html)
4. [doxygen](https://www.doxygen.nl/)

# Configuración inicial (LINUX)

Para configurar el entorno de desarrollo en Linux, sigue los siguientes pasos:

1. **Instalar las herramientas requeridas**

- Clona el repositorio:

```bash
git clone https://github.com/ivanpodo/ids-tp4-22co.git
cd ids-tp4-22co
```

- Instala `pre-commit`

```bash
sudo apt install pre-commit
```

- Instala `cppcheck`

```bash
sudo apt install cppcheck
```

- Instala `clang-format`

```bash
sudo apt install clang-format
```

- Instala `doxygen`

```bash
sudo apt install doxygen
```

2. **Configurar pre-commit**

- Ejecuta el siguiente comando para instalar los hooks de pre-commit:

```bash
pre-commit install
```

- Ahora, cada vez que hagas `git commit`, se ejecutarán automáticamente las verificaciones de estilo y formato.

3. **Ejecutar validaciones manualmente**

- Para ejecutar las validaciones manualmente, puedes usar:

```bash
pre-commit run --all-files
```

# Uso

## Compilación

Para compilar el proyecto, simplemente ejecute el siguiente comando

```bash
make all
```

## Documentación

La documentación del proyecto se puede generar usando Doxygen con el siguiente comando

```bash
make doc
```

Los archivos generados se guardarán en la carpeta `docs/doxy`.

# License

Este repositorio utiliza licencia [MIT](https://spdx.org/licenses/MIT.html).

# Autor

- Ing. Iván Podoroska - [GitHub](https://github.com/ivanpodo) - [Mail](mailto:ivanpodoroska@gmail.com)
