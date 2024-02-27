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

    return sqrt(pow(catetoX,2) + pow(catetoY,2));
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

void PacmanPersonaje::EscaladaSimple2(char lab[10][10]) { //comprobar que no nos come el fantasma
	float m=getValor(getX(),getY());
	int filaActual=y;
	int columnaActual=x;
	int nuevaFila;
	int nuevaColumna;
	int numMov =1;
	bool fin=false;
	while(getValor(columnaActual,filaActual)>m||numMov<5||!fin ){
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
		if(lab[nuevaFila][nuevaColumna] != 'M'&& lab[nuevaFila][nuevaColumna] != 'F'){
			if(getValor(columnaActual,filaActual)<m){
				setX(columnaActual);
				setY(filaActual);
				fin=true;
			}
		}
		if(fin==false){
			numMov=numMov+1;
		}
	}

	if(numMov>4){
		cout<<"No se ha encontrado solucion"<<endl;
	}
	cout<<"Movimiento"<<endl;
	cout<<"mov:"<<numMov<<"  Fila:"<<y<<"  Col:"<<x<<endl;
}
void PacmanPersonaje::EscaladaSimple(char lab[10][10]) { //comprobar que no nos come el fantasma
	float m=getValor(x,y);
	PacmanPersonaje* aux = new PacmanPersonaje(getX(),getY());
	int mov =1;
	aux->mover(mov);
	bool pared = aux->getPared(aux->getX(),aux->getY(),lab);
	while((aux->getValor(aux->getX(),aux->getY())>m)||mov<5){ //valor
		mov ++;
		pared= aux->getPared(aux->getX(),aux->getY(),lab);
		aux->setX(getX());
		aux->setY(getY());
		if (pared==true){
			mov++;
		}
		aux->mover(mov);
	}
	if(mov>4){
		cout<<"No se ha encontrado solucion"<<endl;
	}
	else{
		mover(mov);
	}
	cout<<"Movimiento"<<endl;
	cout<<"mov:"<<mov<<"  Fila:"<<y<<"  Col:"<<x<<endl;
}

float PacmanPersonaje::getValor(int x,int y) {
	return 1.01;
}

bool PacmanPersonaje:: getPared(int x,int y,char lab[10][10]){
	bool pared=false;
	if(lab[x][y] =='M'){
		pared=true;
	}
	return pared;
}

PacmanPersonaje::~PacmanPersonaje() {
	// TODO Auto-generated destructor stub
}

