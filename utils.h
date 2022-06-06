extern int DIM;
extern char barcos[4][13];
extern int casillas[4];

void posicionarBarco();
void imprimirTablero();
void imprimirTableros();

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

void colocarBarcos(char **tablero, int jugador){
	char posicion[3], barco = 0;
	do{
    if(jugador){
      system("cls");
      printf("********TABLERO  ACTUAL********\n");
      printf("   A  B  C  D  E  F  G  H  I  J\n");
      for (int i=0;i<DIM;i++){
        printf(" %d ",i);
        for (int j=0;j<DIM;j++){
          printf("%c  ", tablero[i][j]);
        }
        printf("\n\n");
      }
      printf("\nPOR FAVOR ELIGA LA POSICION DEL BARCO: %s (%d casillas)\n", barcos[barco], casillas[barco]);
      scanf("%s",&posicion);
    }else{
      if(rand() % 2){
        posicion[2] = 'V';
        posicion[0] = rand() % 10;
        posicion[1] = rand() % (10 - casillas[barco] + 1);
      }else{
        posicion[2] = 'H';
        posicion[1] = rand() % 10;
        posicion[0] = rand() % (10 - casillas[barco] + 1);
      }
    }
    if(validarPosicion(posicion, barco, tablero, jugador)){
      posicionarBarco(posicion, barco, tablero, jugador);
      barco ++;
    }else{
      if(jugador){
        printf("\nELIGA OTRA POSICION PARA EL BARCO\n");
        printf("Presione enter para volver a intentar...");
        wait();
      }
    }
	}while(barco < 4);
  if(jugador){
  	system("cls");
  	printf("********TABLERO  ACTUAL********\n");
  	imprimirTablero(tablero);
  	printf("\nTODOS LOS BARCOS POSICIONADOS\n");
  	printf("Presione enter para continuar...");
  	wait();
  	system("cls");
  }else{
    system("cls");
    printf("********TABLERO  ACTUAL********\n");
    imprimirTablero(tablero);
    printf("\nTODOS LOS BARCOS DE LA MAQUINA POSICIONADOS\n");
    printf("Presione enter para continuar...");
    getchar();
    system("cls");
  }
}

int validarPosicion(char *pos, int barco, char **tablero, int jugador){
	int indiceI, indiceJ;
  if(jugador){
    indiceI = pos[1] - 48;
    indiceJ = pos[0] - 65;
  }else{
    indiceI = pos[1];
    indiceJ = pos[0];
  }
	if(pos[2] == 'V'){ //Se mueve el indice I para colocar en vertical
		if((indiceI + casillas[barco] - 1) < 10){//Comprueba que no se rebase el limite del tablero
			for(int i=indiceI;i<casillas[barco]+indiceI;i++){//Loop para comprobar si las casillas estan vacias
				if(tablero[i][indiceJ] != '-'){
					return 0;
				}
			}
		}else{
			return 0;
		}
	}else{//Se mueve el indice J para colocar en horizontal
		if((indiceJ + casillas[barco] - 1) < 10){//Comprueba que no se rebase el limite del tablero
			for(int j=indiceJ;j<casillas[barco]+indiceJ;j++){//Loop para comprobar si las casillas estan vacias
				if(tablero[indiceI][j] != '-'){
					return 0;
				}
			}
		}else{
			return 0;
		}
	}
	return 1;
}

void posicionarBarco(char *pos, int barco, char **tablero, int jugador){
	int indiceI, indiceJ;
  if(jugador){
    indiceI = pos[1] - 48;
    indiceJ = pos[0] - 65;
  }else{
    indiceI = pos[1];
    indiceJ = pos[0];
  }
	if(pos[2] == 'V'){//Se mueve el indice I para colocar en vertical
		for(int i=indiceI;i<casillas[barco]+indiceI;i++){
			tablero[i][indiceJ] = '1';
		}
	}else{//Se mueve el indice J para colocar en horizontal
		for(int j=indiceJ;j<casillas[barco]+indiceJ;j++){
			tablero[indiceI][j] = '1';
		}
	}
}

void imprimirTablero(char **tablero){
  printf("   A  B  C  D  E  F  G  H  I  J\n");
  for (int i=0;i<DIM;i++){
    printf(" %d ",i);
    for (int j=0;j<DIM;j++){
      printf("%c  ", tablero[i][j]);
    }
    printf("\n\n");
  }
}

void imprimirTableros(char **tablero1, char **tablero2){
  printf("   A  B  C  D  E  F  G  H  I  J\t\t   A  B  C  D  E  F  G  H  I  J\n");
  for (int i=0;i<DIM;i++){
    printf(" %d ",i);
    for (int j=0;j<DIM;j++){
      printf("%c  ", tablero1[i][j]);
    }
    printf("\t %d ",i);
    for (int j=0;j<DIM;j++){
      printf("%c  ", tablero2[i][j]);
    }
    printf("\n\n");
  }
}

int *ataqueJugador(char *ataque, char **tableroAtaque, char **tableroMaquina, int restantes){
  int indiceI = ataque[1] - 48, indiceJ = ataque[0] - 65, *resultado;
  resultado = (int *)malloc(2*sizeof(int *));
  resultado[0] = 1;
  resultado[1] = restantes;
  if(tableroAtaque[indiceI][indiceJ] != '-'){
    return resultado;
  }else if(tableroMaquina[indiceI][indiceJ] == '1'){
    tableroAtaque[indiceI][indiceJ] = '*';
    resultado[1] --;
  }else{
    tableroAtaque[indiceI][indiceJ] = ' ';
  }
  resultado[0] = 0;
  return resultado;
}