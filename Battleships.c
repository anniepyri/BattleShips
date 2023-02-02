#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void caption(void);
void welcome(char *str);

int main(void){
	
	srand(time(NULL));

	int howManyShips, zugy, zugx, zugPCy, zugPCx, gameboardSize;
	int gameboardPlayer[20][20] = {{ 0 }};
	int gameboardComputer[20][20] = {{ 0 }};
	char name[21];

	printf("Wie gross soll dein Spielfeld sein?[3-20] ");
	fflush(stdin);
	scanf("%d", &gameboardSize);
/*Festlegung der Spielfeldgröße, durch Eingabe des Spielers*/

welcome(name);
caption();
/*Ausführen der Funktionen welcome und caption*/

	printf("\n");
	printf("Mit wievielen Schiffen willst du spielen? ");
	scanf("%d", &howManyShips);
/*Festlegung der Anzahl der Schiffe*/

	int a=1;
	while(a<howManyShips+1){
	
		printf("Wo willst du dein %d. Schiff platzieren? [Spalte][1-%d] ", a, gameboardSize);
		scanf("%d", &zugy);
	
		printf("Wo willst du dein %d. Schiff platzieren? [Reihe][1-%d] ", a, gameboardSize);
		scanf("%d", &zugx);
		printf("\n");
	
		gameboardPlayer[zugx-1][zugy-1]=1;
		a++;
	}
/*Platzierung der Schiffe des Spielers mit Zählvariable und While Schleife*/

	int b=1;
	while(b<howManyShips+1){
	
		TRYAGAIN:
		zugPCy = (int) (gameboardSize*rand()/(RAND_MAX+1.0));
		zugPCx = (int) (gameboardSize*rand()/(RAND_MAX+1.0));
	/*Kontrollausgabe; printf("zugPCy: %d, zugPCx: %d", zugPCy, zugPCx);*/
	
		if (gameboardComputer[zugPCx][zugPCy]==1){
			goto TRYAGAIN;
		}
	
		gameboardComputer[zugPCx][zugPCy]=1;
		b++;
	}
/*Platzierung der Schiffe des Computers mit Zählvariable, While Schleife, random Int und einem GOTO Befehl, um eine Doppelbelegung zu vermeiden*/


	int i, j, h;
	for(h=1; h<gameboardSize+1; h++){
			if (h>1){
				printf(" %d", h);
			}
			else{
				printf("   %d", h);
			}
		}
	printf("\n");
/*zeichnen der Spielfeldbeschriftung in X-Richtung*/
			
	for(i=0; i<gameboardSize; i++) {
	
		printf(" %d ", i+1);
/*zeichnen der Spielfeldbeschriftung in Y-Richtung*/
	
		for(j=0; j<gameboardSize; j++) {
		
			printf("%d ", gameboardPlayer[i][j]);
		}
		printf("\n");
	}
	printf("\n");
/*zeichnen des Spielfelds*/
	
/* Kontrollausgabe Spielfeld Computer, deaktiviert
int d, e, k;
for(k=1; k<gameboardSize+1; k++){
		if (k>1){
			printf(" %d", k);
		}
		else{
			printf("   %d", k);
		}
	}
		printf("\n");	
for(d=0; d<gameboardSize; d++) {
	printf(" %d ", d+1);
	for(e=0; e<gameboardSize; e++) {
		printf("%d ", gameboardComputer[d][e]);
	}
	printf("\n");
}*/

	int v,w,n,m;
	int shipsAlivePC=0;
	int shipsAlivePlayer=0;
	
	for (v=0;v<gameboardSize+1;v++){
		for (w=0;w<gameboardSize+1;w++){
			if(gameboardComputer[v][w]==1){
				shipsAlivePC++;
			}
		}
	}

	for (n=0;n<gameboardSize+1;n++){
		for (m=0;m<gameboardSize+1;m++){
			if(gameboardPlayer[n][m]==1){
				shipsAlivePlayer++;
			}
		}
	}
/*zählen der aktiven Schiffe auf beiden Spielbrettern, für Computer und für Spieler*/

	int attackX, attackY, attackPCX, attackPCY;
		while (shipsAlivePlayer>0 && shipsAlivePC>0){
/*Beginn While Schleife für Spielverlauf/ Angriffe*/
	
			printf("Wo willst du angreifen? [Spalte] ");
			scanf("%d", &attackY);
	
			printf("Wo willst du angreifen? [Reihe] ");
			scanf("%d", &attackX);
			printf("\n");
/*Abfragen der Koordinaten für Angriff auf Computer*/	
	
			attackPCX= (int) (gameboardSize*rand()/(RAND_MAX+1.0));
			attackPCY= (int) (gameboardSize*rand()/(RAND_MAX+1.0));
			/*Kontrollausgabe, deaktiviert: printf("attack Y: %d, X: %d",attackPCY,attackPCX );*/
/*random int für Koordinaten für Angriff auf Spieler*/	
	
			if(gameboardComputer[attackX-1][attackY-1]==1){
		
				if(gameboardPlayer[attackX-1][attackY-1]==1){
			
					gameboardPlayer[attackX-1][attackY-1]=2;
					printf("Treffer\n");
				}
		
			gameboardPlayer[attackX-1][attackY-1]=3;
			gameboardComputer[attackX-1][attackY-1]=2;
			printf("Treffer\n");
			}
/*Ausführen des Angriffs auf Computer, mit entsprechender Bedingungsprüfung und evtl Spielfeldbeschriftungsänderung und Ausgabe*/	

			if(gameboardPlayer[attackPCX][attackPCY]==1){
		
				gameboardPlayer[attackPCX][attackPCY]=4;
		
				printf("TrefferPC\n");
			}
/*Ausführen des Angriffs auf Spieler, mit entsprechender Bedingungsprüfung und evtl Spielfeldbeschriftungsänderung und Ausgabe*/	

			int v,w,n,m;
			int shipsAlivePC=0;
			int shipsAlivePlayer=0;

			for (v=0;v<gameboardSize+1;v++){
				for (w=0;w<gameboardSize+1;w++){
					if(gameboardComputer[v][w]==1){
					shipsAlivePC++;
					}
				}
			}

			for (n=0;n<gameboardSize+1;n++){
				for (m=0;m<gameboardSize+1;m++){
					if(gameboardPlayer[n][m]==1){
						shipsAlivePlayer++;
					}
				}
			}
/*zählen der aktiven Schiffe auf beiden Spielbrettern, für Computer und für Spieler nach jedem Angriff*/

			int q, o, l;
			for(l=1; l<gameboardSize+1; l++){
		
				if (l>1){
					printf(" %d", l);
				}
				else{
					printf("   %d", l);
				}
			}
			printf("\n");
		
			for(q=0; q<gameboardSize; q++) {
		
				printf(" %d ", q+1);
		
			for(o=0; o<gameboardSize; o++) {
		
				printf("%d ", gameboardPlayer[q][o]);
			}
			printf("\n");
			}
/*Darstellung des Spielfeldes des Spielers nach Angriff*/
	
			printf("aktive Schiffe PC: %d \naktive Schiffe %s: %d \n\n", shipsAlivePC, name, shipsAlivePlayer);
/*Ausgabe des aktuellen Spielstands*/		
	
			if(shipsAlivePlayer==0){
				printf("du hast verloren :(\n\n drueck eine Taste zum beenden");
				getch();
				exit(0);
			}

			if (shipsAlivePC==0){
				printf("du hast gewonnen :)\n\n drueck eine Taste zum beenden");
				getch();
				exit(0);
			}
/*Ausgabe, wenn der Spieler gewonnen oder verloren hat und beenden des Programms nach Eingabe von etwas*/
		}
		
		getch();
		return 0;
}

void caption(void){
	
	printf ("Legende:\n 1=Schiff; 2=Treffer,aber eigenes Schiff auf gleichem Feld; 3=Treffer; 4=getroffen\n");
/*Legende*/
}

void welcome(char *str){
	
	printf ("Willkommen bei BattleShips!\n\nBitte gib deinen Namen ein:[max 20 Zeichen] ");
	fflush(stdin);
	scanf("%s", str);
	printf("Hallo %s!\n\n",str);
/*Eingabe und Ausgabe des Spielernamens*/
}





