//Cronometro test
/*
+Autor: Lautaro Linquiman
+Fecha y Hora: 28/02/2015
+Licencia: GPL 3
*/
#include <stdio.h> // printf, scanf
#include <stdlib.h> // system
#include <time.h> // time

// Importando funcion sleep y definiendo comando de limpieza de consola
#ifdef _WIN32
#include <Windows.h>
#define clearCommand    "cls"
#else
#include <unistd.h>
#define clearCommand    "clear"
#endif

int main(){
    int segundos = 0, sec = 0, min = 0, hor = 0;
    clock_t tiempoDeInicio, tiempoAcual;    
    tiempoDeInicio = time(NULL); // Obtiene el tiempo a la hora de iniciar el cronometro - Variable de referencia
    while(1){
        /* Se inicia el cronometro */
        tiempoAcual = time(NULL); // Obtiene el tiempo para ser comparado con la variable de refencia
        segundos = (tiempoAcual-tiempoDeInicio); // Se obtiene la cantidad de segundos

        if(segundos < 60){ //Comprueba que la cantidad de segundos sea menor a 60 segundos
            sec = segundos;
        }else if(segundos >= 60){ //Si los segundos son mayores a 60 se obtene la cantidad de minutos y la cantidad de segundos
            min = segundos/60; //Cantidad de minutos
            sec = segundos%60; //Cantidad de segundos
        }

        if(min >= 60){ // SI la cantidad de minutos es mayos o igual a 60 se obtiene la cantidad de horas
            hor = min/60;//Cantidad de horas
            min = min%60;//Cantidad de minutos
        }
    
        system(clearCommand); // Limpiamos nuestra ventana
        printf("Cronometro %02d:%02d:%02d\n", hor, min, sec);
        sleep(1); //Genera una demora en la ejecucion de 1 segundo para evitar una sobre carga
    }
    return 0;
}
