# CLI Competitor

Este repositorio contiene una colección de herramientas de línea de comandos útiles para la programación competitiva.

## Instalación

Para instalar las herramientas, sigue estos pasos:

```bash
# Clonar el repositorio
git clone https://github.com/tuusuario/cli_competitor.git
cd cli_competitor

# Dar permisos de ejecución al instalador
chmod +x install.sh

# Ejecutar el instalador
./install.sh
```

## Uso

Después de la instalación, las herramientas estarán disponibles en la carpeta `binarios` y tambien en `/bin/`. Aquí se explica cómo utilizarlas:

### 1. `primes`

Este programa permite obtener números primos en un rango determinado.

**Uso:**
```bash
primes 10 50   # Muestra los primos entre 10 y 50
primes -i 5 10  # Muestra los primos en las posiciones 5 a 10 en la lista de primos
```

### 2. `fact`

Este programa permite factorizar números.

**Uso:**
```bash
fact 100        # Factoriza 100
fact -e 100     # Muestra la factorización extendida (ejemplo: 8 = 2, 2, 2 en vez de 2^3)
fact -a 10 15 20  # Factoriza un array de números
```

### 3. `gencomp`

Esta herramienta genera una carpeta con archivos .cpp numerados desde la a hasta la z (o la cantidad que prefieras) con opcion a pasarle la ruta de un snippet y copie su contenido a cada archivo, ideal para contests de codeforces
**Uso:**
```bash
gencomp -n 10 "Codeforces Round 9999" #crea la carpeta ~/competencias/Codeforces_Round_9999 y en su interior 10 archivos con extension .cpp, a.cpp, b.cpp, ...
```

