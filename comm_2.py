#Programa para leer el readout del pueto serial de arduino
#Modificado por Leonardo Loaiza
import serial
#serialport = serial.Serial("/dev/ttyUSB0",baudrate=9600, timeout=300)
serialport = serial.Serial("/dev/ttyUSB0",baudrate=9600, timeout=10)
textfile = open("delay_7s.dat","w")
cincoMinutosHora=6
#horas=12
horas=1
#range se refiere a la cantidad de datos que se quieren imprimir
#for i in range(0,(2*horas*cincoMinutosHora)):
for i in range(0,4):
    arduinodata=serialport.readline().decode("ascii")
    print(arduinodata)
    textfile.write(arduinodata)
textfile.close()
