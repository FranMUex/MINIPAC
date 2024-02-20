/*
 * PacmanPersonaje.cpp
 *
 *  Created on: 19 feb. 2024
 *      Author: alumno
 */

#include "PacmanPersonaje.h"

PacmanPersonaje::PacmanPersonaje() {
	// TODO Auto-generated constructor stub

}
PacmanPersonaje::PacmanPersonaje(int x, int y)
{
    this->x = x;
    this->y = y;
}

float PacmanPersonaje::getDistancia(int destinoX, int destinoY)
{
    int catetoX = destinoX - x;
    int catetoY = destinoY - y;

    return sqrt(catetoX^2 + catetoY^2);
}
int PacmanPersonaje::getX() {
	return x;
}

void PacmanPersonaje::setX(int x) {
	this->x = x;
}

int PacmanPersonaje::getY() {
	return y;
}

void PacmanPersonaje::setY(int y) {
	this->y = y;
}

void PacmanPersonaje::mover(int m) {
	switch(m) {
		case 1:
			setX(getX()-1);
		    break;
		case 2:
			setX(getX()+1);
			break;
		case 3:
			setY(getY()+1);
			break;
		case 4:
			setY(getY()-1);
			break;
		default:
			// Manejar cualquier otro caso si es necesario
			break;
	}
}

void PacmanPersonaje::distancia() {
}

PacmanPersonaje::~PacmanPersonaje() {
	// TODO Auto-generated destructor stub
}

