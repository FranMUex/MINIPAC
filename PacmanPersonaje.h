/*
 * PacmanPersonaje.h
 *
 *  Created on: 19 feb. 2024
 *      Author: alumno
 */

#ifndef PACMANPERSONAJE_H_
#define PACMANPERSONAJE_H_
#include<cmath>

class PacmanPersonaje {
private:
	int y;
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

	double getValor(int salidaX, int salidaY, int fantX, int fantY);

	 ~PacmanPersonaje();
};

#endif /* PACMANPERSONAJE_H_ */
