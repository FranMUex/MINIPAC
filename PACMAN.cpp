//============================================================================
// Name        : PACMAN.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
using namespace std;

#include "PacmanPersonaje.h"
#include "Fantasma.h"

using namespace std;


void mostrarLab(char lab[][10]);

int main() {
	char laberinto[10][10];
	string currChar;
	ifstream fEnt;
	ofstream fSal;
	int numChar = 200;
	PacmanPersonaje *pacman;
	Fantasma *fantasma;
	int salidaX;
	int salidaY;

	fEnt.open("MINIPAC1.txt");
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
			case 'C':
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

	mostrarLab(laberinto);
	for(int i=0;i<28;i++){
	  //fantasma->mover(laberinto);
		pacman->EscaladaSimple(laberinto, salidaX, salidaY, fantasma->getX(), fantasma->getY());
	}
	return 0;
}
void mostrarLab(char lab[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << lab[i][j];
		}
		cout << endl;
	}
}