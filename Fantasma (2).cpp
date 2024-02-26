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
Fantasma::Fantasma(int x, int y,int mov)
{
    this->x = x;
    this->y = y;
    this->numMov = mov;
}

float Fantasma::getDistancia(int destinoX, int destinoY)
{
    int catetoX = destinoX - x;
    int catetoY = destinoY - y;

    return sqrt((catetoX^2) + (catetoY^2));
}
/*void Fantasma::mover(char lab[10][10]) {

	Fantasma * aux;
	aux = new Fantasma(this->x, this->y,0);
	moverr(lab,aux);
	this = aux;
}

void Fantasma::moverr(char lab[10][10],Fantasma f){
	    f.desplazarse(f.getMov());
		if(lab[f->getX()][f->getY()]=="M"){
			f.setMov(f.getMov()+1);
			if(f.getMov() > 4){
				f.setMov(1);
			}
			moverr(lab,f);
		}
		else{
			this->desplazarse(mov);
		}
}*/

void Fantasma::mover(char lab[10][10]) {

    int filaActual = getY();
    int columnaActual = getX();
    int nuevaFila ;
    int nuevaColumna;
    bool mover=false;
   // cout<<"Inicio"<<endl;
   // cout<<"mov:"<<numMov<<"  Fila:"<<y<<"  Col:"<<x<<endl;

    while (mover==false) {

    	if(numMov==1){ //der
    		 nuevaFila = filaActual;
    		 nuevaColumna =columnaActual+1;
    	}
    	if(numMov==2){ //abajo
    		nuevaColumna = columnaActual;
    		nuevaFila =filaActual+1;
    	}
    	if(numMov==3){ //izq
    		nuevaFila = filaActual;
    		nuevaColumna =columnaActual-1;
    	}
    	if(numMov==4){ //arriba
    		nuevaColumna = columnaActual;
    		 nuevaFila =filaActual+1;
    	}
        if(lab[nuevaFila][nuevaColumna] == 'M'||lab[nuevaFila][nuevaColumna] == 'S'){
        	numMov=numMov+1;
        	if(numMov > 4){
        		numMov=1;
        	}
        }
        else{
        	mover=true;
        	setX(nuevaColumna);
        	setY(nuevaFila);
        }
    }
    cout<<"Movimiento"<<endl;
    cout<<"mov:"<<numMov<<"  Fila:"<<y<<"  Col:"<<x<<endl;
}

void Fantasma::desplazarse(int mov) {
	switch(mov) {
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
				break;
		}
}

int Fantasma::getMov() {
	return numMov;
}

void Fantasma::setMov(int mov) {
	this->numMov = mov;
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

