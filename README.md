# Estacion_Metereologica

**Estación meteorológica con Arduino** que mide temperatura, humedad, presión atmosférica e intensidad de luz, muestra los valores en una pantalla LCD y los envía por el puerto serial a la computadora, donde un script de Python los guarda en un archivo.

## Objetivo

Registrar variables ambientales de forma automática y periódica para analizarlas después.

## Lenguaje y tecnologías

- **Arduino (C/C++)** para la placa.
- **Python 3** con `pyserial` para guardar los datos en la computadora.
- **C++** para el ejemplo de escritura de archivos.

### Componentes

| Componente | Mide | Conexión |
|---|---|---|
| DHT22 (AM2302) | Temperatura y humedad | Pin digital 2 |
| BMP085 / BMP180 | Presión atmosférica | I2C |
| Fotorresistencia | Intensidad de luz | Pin analógico A0 |
| LCD 16×2 con módulo I2C | Pantalla | I2C (dirección `0x27`) |

## Archivos

| Archivo | Descripción |
|---|---|
| `temp_humedad.ino` | Programa del Arduino. Cada 7,5 segundos lee los sensores, los muestra en el LCD y los envía por serial. |
| `comm_2.py` | Lee el puerto serial y guarda las líneas en `delay_7s.dat`. |
| `ejemplo_escritura.cpp` | Ejemplo de cómo escribir datos en un archivo (simulación de un péndulo simple). |
| `printMatrix.cpp` | Copia del programa del repositorio [imprimir-matriz](https://github.com/loaizaleo/imprimir-matriz). |

## Uso

### 1. Cargar el programa al Arduino

En el IDE de Arduino, instale estas librerías (*Herramientas → Administrar bibliotecas*):

- *DHT sensor library* (Adafruit)
- *Adafruit Unified Sensor*
- *Adafruit BMP085 Unified*
- *LiquidCrystal I2C*

Luego abra `temp_humedad.ino` y súbalo a la placa.

### 2. Guardar los datos en la computadora

```bash
pip install pyserial
python comm_2.py
```

El archivo `delay_7s.dat` queda con columnas separadas por tabulación:

```
contador    temperatura(°C)    humedad(%)    presión(hPa)    luz(0-1023)
```

### Ejemplo del péndulo (opcional)

```bash
g++ ejemplo_escritura.cpp -o pendulo
./pendulo   # genera pendulo_mejor.dat
```

## Notas

- `comm_2.py` usa el puerto `/dev/ttyUSB0` (Linux). En Windows cámbielo por el que corresponda, por ejemplo `COM3`.
- Como está, `comm_2.py` solo guarda **4 lecturas**. Para registrar más tiempo, cambie `range(0,4)` (la línea comentada calcula las lecturas según las horas deseadas).
- La temperatura se corrige restando 1 °C (`delta = 1.0`) para calibrar el sensor.
- El intervalo entre lecturas se ajusta con la variable `minutos` del `.ino` (0,125 min = 7,5 s).
