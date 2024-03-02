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

void PacmanPersonaje::EscaladaSimple2(char lab[10][10], int salidaX, int salidaY, int fantX, int fantY) { //comprobar que no nos come el fantasma
	float m=getValor(salidaX, salidaY, fantX, fantY);
	int filaActual=y;
	int columnaActual=x;
	int nuevaFila;
	int nuevaColumna;
	int numMov =1;
	bool fin=false;
	while(getValor(salidaX, salidaY, fantX, fantY)>m||numMov<5||!fin ){
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
			if(getValor(salidaX, salidaY, fantX, fantY)<m){
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
void PacmanPersonaje::EscaladaSimple(char lab[10][10], int salidaX, int salidaY, int fantX, int fantY) { //comprobar que no nos come el fantasma
	double m=getValor(salidaX, salidaY, fantX, fantY);
	cout<<m<<endl;
	PacmanPersonaje* aux = new PacmanPersonaje(getX(),getY());
	int mov =1;
	aux->mover(mov);
	bool pared = aux->getPared(aux->getX(),aux->getY(),lab);
	while((aux->getValor(salidaX, salidaY, fantX, fantY)>m)||mov<5){ //valor
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

void PacmanPersonaje::EscaladaMaxPendiente(char lab[10][10], int salidaX, int salidaY, int fantX, int fantY)
{
	double hPr = getValor(salidaX, salidaY, fantX, fantY), hPrAux;

	bool pared;

	int movMejor;

	Fantasma *auxFant = new Fantasma(fantX, fantY);
	auxFant->mover(lab);

	for(int i = 1; i <= 4; i++)
	{	
		PacmanPersonaje *auxPac = new PacmanPersonaje(getX(), getY());

		switch(i)
		{
			case 1:
				pared = getPared(getX() - 1, getY(), lab);
				break;
			case 2:
				pared = getPared(getX() + 1, getY(), lab);
				break;
			case 3:
				pared = getPared(getX(), getY() + 1, lab);
				break;
			case 4:
				pared = getPared(getX(), getY() - 1, lab);
				break;
		}

		if(!pared){
			auxPac->mover(i);

			hPrAux = auxPac->getValor(salidaX, salidaY, auxFant->getX(), auxFant->getY());

			if(hPr < hPrAux)
			{
				movMejor = i;
				hPr = hPrAux;
			}
		}
		delete auxPac;
	}

	delete auxFant;

	mover(movMejor);
}

double PacmanPersonaje::getValor(int salidaX, int salidaY, int fantX, int fantY) {
	double 
	distSalida = getDistancia(salidaX, salidaY),
	distFantasma = getDistancia(fantX, fantY);

	return (100 - distSalida) * (distFantasma / 12.727);
}

bool PacmanPersonaje:: getPared(int x,int y,char lab[10][10]){
	return lab[x][y] == 'M';
}

PacmanPersonaje::~PacmanPersonaje() {
	// TODO Auto-generated destructor stub
}

