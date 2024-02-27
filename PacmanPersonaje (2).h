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
using namespace std;

class PacmanPersonaje {
private:
	int y; //fila
	int x;
public:
	PacmanPersonaje();
	PacmanPersonaje (int x, int y);

	float getDistancia(int destinoX, int destinoY);

	void mover(int m);
	void distancia();

	int getX();
	void setX(int x);
	int getY();
	void setY(int y) ;
	void EscaladaSimple(char lab[10][10]);
	void EscaladaSimple2(char lab[10][10]);
	void EscaladaMaxPendiente();
	bool getPared(int x,int y,char lab[10][10]);
	float getValor(int x,int y);

	 ~PacmanPersonaje();
};

#endif /* PACMANPERSONAJE_H_ */
