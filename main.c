#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "texto.h"
#include "utils.h"

int DIM = 10;
char barcos[4][13] = {
	{"LANCHA\0\0\0\0\0\0\0"},
	{"ACORAZADO\0\0\0\0"},
	{"SUBMARINO\0\0\0\0"},
	{"PORTAAVIONES\0"}
};
int casillas[4] = {2,3,4,5};

void main(){
	//MENU:
	//OPCION 1: COMENZAR EL JUEGO
	//- COLOCAR LOS BARCOS DEL JUGADOR
	//- COLOCAR LOS BARCOS DE LA MAQUINA
	//- EMPIEZA EL JUEGO, EL PRIMER TURNO LE PERTENECE AL JUGADOR, LUEGO LA MAQUINA Y SUCESIVAMENTE HASTA QUE UNO GANE EL PARTIDO
	//OPCION 2: INSTRUCCIONES
	//OPCION 3: SALIR
  srand(time(NULL));
	system("cls");
	int opcion = 0, turno = 1, ganador = 0;
	mostrarPresentacion();
	while(opcion != 3){
		opcion = mostrarMenu();
		switch(opcion){
			case 1:
				char **tabJugador, **tabMaquina, **tabAtaqueJ;
				tabJugador = inicializarTablero();
				tabMaquina = inicializarTablero();
        tabAtaqueJ = inicializarTablero();
				colocarBarcos(tabJugador, 1);
        colocarBarcos(tabMaquina, 0);
        do{
          if(turno){
            system("cls");
            printf("*****TABLERO DE TUS BARCOS*****\t\t******TU TABLERO DE ATAQUE*****\n");
            imprimirTableros(tabJugador, tabAtaqueJ);
            turno = 0;
          }else{
            turno = 1;
          }
        }while(ganador != 0);//TODO: Cambiar por == cuando se termine de hacer el debug
				break;
			case 2:
				mostrarInstrucciones();
				break;
			default:
				break;
		}
	}
}