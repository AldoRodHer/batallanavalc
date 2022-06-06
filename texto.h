void wait(){
	getchar();
	getchar();
}

void mostrarPresentacion(){
	printf("\n\n");
	printf("oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
	printf("ooo       oooooooo   oooooo          oooooo   ooooooo  oooooooooo  ooooooooooooo   ooooooo\n");
	printf("ooo  oooo  oooooo     ooooooooo  ooooooooo    ooooooo  oooooooooo  oooooooooooo     oooooo\n");
	printf("ooo  oooo  oooooo  o  ooooooooo  oooooooo   o  oooooo  oooooooooo  oooooooooooo  o  oooooo\n");
	printf("ooo       oooooo  ooo  oooooooo  oooooooo  ooo  ooooo  oooooooooo  ooooooooooo  ooo  ooooo\n");
	printf("ooo  oooo   ooo  ooooo  ooooooo  ooooooo  ooooo ooooo  oooooooooo  oooooooooo  ooooo  oooo\n");
	printf("ooo  oooo   ooo         ooooooo  oooooo          oooo  oooooooooo  oooooooooo         oooo\n");
	printf("ooo        ooo  ooooooo  oooooo  oooooo  ooooooo  ooo        oooo        ooo  ooooooo  ooo\n");
	printf("oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
	printf("oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
	printf("ooooooooooooo   oooooo  oooooooo ooooo  oooooooo  ooooo   ooooooo  ooooooooooooooooooooooo\n");
	printf("ooooooooooooo    ooooo  ooooooo   ooooo  oooooo  ooooo     oooooo  ooooooooooooooooooooooo\n");
	printf("ooooooooooooo  o  oooo  oooooo  o  ooooo  ooooo  ooooo  o   ooooo  ooooooooooooooooooooooo\n");
	printf("ooooooooooooo  oo  ooo  ooooo  ooo  oooo   ooo  ooooo  ooo  ooooo  ooooooooooooooooooooooo\n");
	printf("ooooooooooooo  ooo  oo  oooo  ooooo ooooo   o  ooooo  ooooo  oooo  ooooooooooooooooooooooo\n");
	printf("ooooooooooooo  oooo  o  ooo          ooooo  o  ooooo          ooo  ooooooooooooooooooooooo\n");
	printf("ooooooooooooo  ooooo    oo   ooooooo  ooooo   ooooo  ooooooo  ooo         oooooooooooooooo\n");
	printf("oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n");
	printf("\n\n");
	printf("Presione enter para continuar...\n");
	getchar();
	system("cls");
}

int mostrarMenu(){
	int op = 0;
	printf("SELECCIONE UNA OPCION DEL MENU: \n");
	printf("1. COMENZAR JUEGO\n");
	printf("2. INSTRUCCIONES DEL JUEGO\n");
	printf("3. SALIR\n");
	printf("INGRESE SU OPCION: ");
	scanf("%d",&op);
	printf("\n");
	return op;
}

void mostrarInstrucciones(){
	system("cls");
	printf("---------- INSTRUCCIONES DE BATALLA NAVAL 2.0 ----------\n");
	printf("1. PARA EMPEZAR A JUGAR DEBE SELECCIONAR LA OPCION 1 EN EL MENU\n");
	printf("2. DEBE COLOCAR SUS BARCOS DE LA SIGUIENTE MANERA:\n");
	printf("\tINTRODUCIR LETRA DE LA COLUMNA SEGUIDO DEL NUMERO DE FILA Y POSTERIORMENTE\n");
	printf("\tLA LETRA QUE INDICA SI ES HORIZONTAL O VERTICAL (H o V), EJEMPLO: C5H\n");
	printf("\tNOTA: EN EL CASO DE LOS VERTICALES EL BARCO SE POSICIONARA HACIA ABAJO DE LA POSICION ELEGIDA\n");
	printf("\tY EN EL CASO DE LOS HORIZONTALES EL BARCO SE POSICIONARA A LA DERECHA DE LA POSICION ELEGIDA\n");
	printf("\tDEBE TENER EN CUENTA QUE LOS BARCOS SE COLOCAN EN EL SIGUIENTE ORDEN:\n");
	printf("\t\t1. LANCHA (2 CASILLAS)\n");
	printf("\t\t2. ACORAZADO (3 CASILLAS)\n");
	printf("\t\t3. SUBMARINO (4 CASILLAS)\n");
	printf("\t\t4. PORTAAVIONES (5 CASILLAS)\n");
	printf("Presione enter para regresar al menu...\n");
	wait();
	system("cls");
}