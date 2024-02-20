/*
 * Fantasma.h
 *
 *  Created on: 19 feb. 2024
 *      Author: alumno
 */

#ifndef FANTASMA_H_
#define FANTASMA_H_
#include<cmath>

class Fantasma {
private:
	int y;
	int x;
public:
	Fantasma();
	Fantasma(int x, int y);

	float getDistancia(int destinoX, int destinoY);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y) ;
	void mover();
    ~Fantasma();
};

#endif /* FANTASMA_H_ */
