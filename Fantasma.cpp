/*
 * Fantasma.cpp
 *
 *  Created on: 19 feb. 2024
 *      Author: alumno
 */

#include "Fantasma.h"

Fantasma::Fantasma(int x, int y)
{
    this->x = x;
    this->y = y;
}

float Fantasma::getDistancia(int destinoX, int destinoY)
{
    int catetoX = destinoX - x;
    int catetoY = destinoY - y;

    return sqrt(catetoX^2 + catetoY^2);
}

int Fantasma::getX() {
	return x;
}

void Fantasma::setX(int x) {
	this->x = x;
}

int Fantasma::getY() {
	return y;
}

void Fantasma::setY(int y) {
	this->y = y;
}

Fantasma::~Fantasma() {
	// TODO Auto-generated destructor stub
}

