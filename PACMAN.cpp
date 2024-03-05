//============================================================================
// Name        : PACMAN.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include "PacmanPersonaje.h"
#include "Fantasma.h"

using namespace std;

void mostrarLab(char lab[10][10]);

int main() {
	char laberinto[10][10];
	ifstream fEnt;
	int numChar = 200;
	PacmanPersonaje *pacman;
	Fantasma *fantasma;
	int salidaX;
	int salidaY;

	fEnt.open("MINIPAC2.txt");
	if (fEnt.fail()) {
		cerr << "ERROR" << endl;
	}

	char caracter;
	int fila = 0;
	int columna = 0;
	while (numChar >= 0) {
		fEnt >> caracter;
		numChar--;
		if (caracter != ',' && caracter != '\n') {

			switch(caracter)
			{
			case 'P':
				pacman = new PacmanPersonaje(columna, fila); //fila y columna pueden estar al reves
				break;

			case 'F':
				fantasma = new Fantasma(columna, fila,1);
				break;

			case 'S':
				salidaX = columna;
				salidaY = fila;
				break;

			}
			laberinto[fila][columna] = caracter;
			columna++;
		}
		if (columna == 10) {
			fila++;
			columna = 0;
		}
	}
	fEnt.close();

	bool fin = false;
	mostrarLab(laberinto);

	while(!fin)
	{
	  	fantasma->mover(laberinto);
		
		if(!pacman->EscaladaSimpleAlternativo(laberinto, salidaX, salidaY, *fantasma) || 
		pacman->getX() == fantasma->getX() && pacman->getY() == fantasma->getY())
		{
			cout<<"Derrota"<<endl;
			fin = true;
		}
		else if(pacman->getX() == salidaX && pacman->getY() == salidaY)
		{
			cout<<"Victoria"<<endl;
			fin = true;
		}
	}

	delete pacman; delete fantasma;
	
	return 0;
}


void mostrarLab(char lab[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << lab[i][j] << " ";
		}
		cout << endl;
	}
}