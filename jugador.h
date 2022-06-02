extern int DIM;
extern char barcos[4][13];
extern int casillas[4];

void posicionarBarco();

char **inicializarTablero(){
	char **tablero;
	tablero = (char **)malloc(DIM*sizeof(char *));
	for(int i=0;i<DIM;i++){
		tablero[i] = (char *)malloc(DIM*sizeof(char));
	}
	for(int i=0;i<DIM;i++){
		for(int j=0;j<DIM;j++){
			tablero[i][j] = '-';
		}
	}
	return tablero;
}

void colocarBarcosJugador(char **tabJugador){
	char posicion[3], barco = 0;
	do{
		system("cls");
		printf("********TABLERO  ACTUAL********\n");
		printf("   A  B  C  D  E  F  G  H  I  J\n");
		for (int i=0;i<DIM;i++){
			printf(" %d ",i);
			for (int j=0;j<DIM;j++){
				printf("%c  ", tabJugador[i][j]);
			}
			printf("\n\n");
		}
		printf("\nPOR FAVOR ELIGA LA POSICION DEL BARCO: %s (%d casillas)\n", barcos[barco], casillas[barco]);
		scanf("%s",&posicion);
		if(validarPosicion(posicion, barco, tabJugador)){
			posicionarBarco(posicion, barco, tabJugador);
			barco ++;
		}else{
			printf("\nELIGA OTRA POSICION PARA EL BARCO\n");
			printf("Presione enter para volver a intentar...");
			wait();
		}
	}while(barco < 4);
	system("cls");
	printf("********TABLERO  ACTUAL********\n");
	printf("   A  B  C  D  E  F  G  H  I  J\n");
	for (int i=0;i<DIM;i++){
		printf(" %d ",i);
		for (int j=0;j<DIM;j++){
			printf("%c  ", tabJugador[i][j]);
		}
		printf("\n\n");
	}
	printf("\nTODOS LOS BARCOS POSICIONADOS\n");
	printf("Presione enter para continuar...");
	wait();
	system("cls");
}

int validarPosicion(char *pos, int barco, char **jugador){
	int indiceI = pos[1] - 48, indiceJ = pos[0] - 65;
	if(pos[2] == 'V'){ //Se mueve el indice I para colocar en vertical
		if((indiceI + casillas[barco] - 1) < 10){//Comprueba que no se rebase el limite del tablero
			for(int i=indiceI;i<casillas[barco]+indiceI;i++){//Loop para comprobar si las casillas estan vacias
				if(jugador[i][indiceJ] != '-'){
					return 0;
				}
			}
		}else{
			return 0;
		}
	}else{//Se mueve el indice J para colocar en horizontal
		if((indiceJ + casillas[barco] - 1) < 10){//Comprueba que no se rebase el limite del tablero
			for(int j=indiceJ;j<casillas[barco]+indiceJ;j++){//Loop para comprobar si las casillas estan vacias
				if(jugador[indiceI][j] != '-'){
					return 0;
				}
			}
		}else{
			return 0;
		}
	}
	return 1;
}

void posicionarBarco(char *pos, int barco, char **jugador){
	int indiceI = pos[1] - 48, indiceJ = pos[0] - 65;
	if(pos[2] == 'V'){//Se mueve el indice I para colocar en vertical
		for(int i=indiceI;i<casillas[barco]+indiceI;i++){
			jugador[i][indiceJ] = '1';
		}
	}else{//Se mueve el indice J para colocar en horizontal
		for(int j=indiceJ;j<casillas[barco]+indiceJ;j++){
			jugador[indiceI][j] = '1';
		}
	}
}
