import speech_recognition as sr

import serial, time
#from time import sleep

def reconocer_voz_y_guardar():
    # Crear un objeto de reconocimiento de voz
    r = sr.Recognizer()

    # Configurar el micrófono
    with sr.Microphone() as source:
        print("Hable para comenzar a reconocer la voz...")
        audio = r.listen(source)
        print("Escuchado, ahora reconociendo...")

    try:
        # Reconocer la voz usando el reconocedor de voz de Google
        texto_reconocido = r.recognize_google(audio, language="es-ES")
        reconocer(texto_reconocido)
        print("Texto reconocido: " + texto_reconocido)
        
        

        # Guardar la transcripción en un archivo de texto
        with open("transcripcion.txt", "a") as archivo:
            archivo.write(texto_reconocido + "\n")
        print("Transcripción guardada en 'transcripcion.txt'")

    except sr.UnknownValueError:
        print("No se pudo entender lo que dijiste")
    except sr.RequestError as e:
        print("Error al conectarse al servicio de reconocimiento de voz: {0}".format(e))
        
        return texto_reconocido
        
def reconocer(texto):
    num=""
    if texto == "avanza":
        num="1"
        arduino.write(num.encode())
        #
        datos_recibidos = arduino.readline().decode()
        print("Datos recibidos:", datos_recibidos)
        #
        return escribir(num)
    elif texto == "detente":
        num="2"
        arduino.write(num.encode())
        return escribir(num)
    elif texto == "atras":
        num="3"
        arduino.write(num.encode())
        return escribir(num)
    elif texto == "derecha":
        num="4"
        arduino.write(num.encode())
        return escribir(num)
    elif texto == "izquierda":
        num="5"
        arduino.write(num.encode())
        return escribir(num)
    else:
        return print("Error Catastrofico")
    
    
    
        
#Funcion que escribe la salida de la funcion reconocer al archivo txt
def escribir(entrada):
    with open("transcripcion.txt", "a") as archivo:
            archivo.write(entrada + "\n")
    print("Transcripción guardada en 'transcripcion.txt'")
    
#Funcion que envia el dato al serial por bluetooth

        
        

if __name__ == "__main__":
    try:
        arduino = serial.Serial("COM5",9600)
        print("Conectado")
        while True:
            reconocer_voz_y_guardar()

    except TimeoutError:
        print("error")
    finally:
        print("done")