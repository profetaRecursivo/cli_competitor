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

Esta herramienta genera números compuestos dentro de un rango dado.

**Uso:**
```bash
gencomp 10 50   # Muestra los números compuestos entre 10 y 50
```

