/*
 * Fantasma.h
 *
 *  Created on: 19 feb. 2024
 *      Author: alumno
 */

#ifndef FANTASMA_H_
#define FANTASMA_H_
#include<cmath>
#include <iostream>
#include <string>
using namespace std;

class Fantasma {
private:
	int y;//fila
	int x;//col
	int numMov;

public:
	Fantasma();
	Fantasma(int x, int y);
	Fantasma(int x, int y,int mov);

	float getDistancia(int destinoX, int destinoY);
	int getMov();
	void setMov(int mov);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y) ;
	void mover(char lab[10][10]);
	//void moverr(char lab[10][10],Fantasma f);
	void desplazarse(int mov);
	//bool getPared();
    ~Fantasma();
};

#endif /* FANTASMA_H_ */
