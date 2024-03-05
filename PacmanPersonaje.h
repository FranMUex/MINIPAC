/*
 * PacmanPersonaje.h
 *
 *  Created on: 19 feb. 2024
 *      Author: alumno
 */

#ifndef PACMANPERSONAJE_H_
#define PACMANPERSONAJE_H_
#include<cmath>
#include <iostream>
#include <string>
#include <time.h>
#include "Fantasma.h"
using namespace std;

class PacmanPersonaje {
private:
	int y; //fila
	int x;
public:
	PacmanPersonaje();
	PacmanPersonaje (int x, int y);

	double getDistancia(int destinoX, int destinoY);

	void mover(int m);
	void distancia();

	int getX();
	void setX(int x);
	int getY();
	void setY(int y) ;
	bool EscaladaSimple(char lab[10][10], int salidaX, int salidaY, Fantasma fantasma);
	bool EscaladaSimpleAlternativo(char lab[10][10], int salidaX, int salidaY, Fantasma fantasma);
	bool EscaladaMaxPendiente(char lab[10][10], int salidaX, int salidaY, Fantasma fantasma);
	bool getPared(int x,int y,char lab[10][10]);

	double getValor(int salidaX, int salidaY, int fantX, int fantY, char lab[10][10]);

	 ~PacmanPersonaje();
};

#endif /* PACMANPERSONAJE_H_ */
