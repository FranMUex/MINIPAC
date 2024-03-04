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

double PacmanPersonaje::getDistancia(int destinoX, int destinoY)
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

bool PacmanPersonaje::EscaladaSimple(char lab[10][10], int salidaX, int salidaY, int fantX, int fantY) { //comprobar que no nos come el fantasma
	double m=getValor(salidaX, salidaY, fantX, fantY, lab);
	cout<<m<<endl;
	PacmanPersonaje* aux = new PacmanPersonaje(getX(),getY());
	int mov =1;
	bool pared = aux->getPared(aux->getX(),aux->getY(),lab), fin = true;
	Fantasma *fantAux = new Fantasma(fantX, fantY);
	fantAux->mover(lab);


	if(aux->getValor(salidaX, salidaY, fantAux->getX(), fantAux->getY(), lab)>m){
	do
	{
		aux->mover(mov);
		cout<<"Movimiento: "<<mov<<" | "<<aux->getValor(salidaX, salidaY, fantX, fantY, lab)<<endl;
		mov ++;
		pared= aux->getPared(aux->getX(),aux->getY(),lab);
		aux->setX(getX());
		aux->setY(getY());
		if (pared==true){
			mov++;
		}
	}
	while((aux->getValor(salidaX, salidaY, fantAux->getX(), fantAux->getY(), lab)>m) && 
		mov<5 && m > 0);
	if(mov>4 || m == 0){
		cout<<"No se ha encontrado solucion"<<endl;
		fin = false;
	}
	else{
		mover(mov);
	}
	else
	{
		cout<<"No se ha encontrado solucion"<<endl;
		fin = false;
	}
	}

	delete fantAux;
	cout<<"Movimiento"<<endl;
	cout<<"mov:"<<mov<<"  Fila:"<<y<<"  Col:"<<x<<endl;
	return fin;
}

bool PacmanPersonaje::EscaladaMaxPendiente(char lab[10][10], int salidaX, int salidaY, int fantX, int fantY)
{
	double hPr = getValor(salidaX, salidaY, fantX, fantY, lab), hPrAux = 0;

	bool pared, mejor = false;

	int movMejor = 0;

	Fantasma *auxFant = new Fantasma(fantX, fantY);
	auxFant->mover(lab);

	for(int i = 1; i < 5; i++)
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

			hPrAux = auxPac->getValor(salidaX, salidaY, auxFant->getX(), auxFant->getY(), lab);

			if(hPrAux > hPr && hPrAux != 0)
			{
				movMejor = i;
				mejor = true;
				hPr = hPrAux;
			}
		}
		delete auxPac;
	}

	delete auxFant;

	mover(movMejor);

	return mejor;
}

double PacmanPersonaje::getValor(int salidaX, int salidaY, int fantX, int fantY, char lab[10][10]) {
	double 
	distSalida = getDistancia(salidaX, salidaY),
	distFantasma = getDistancia(fantX, fantY);

	short numMuros = 0;

	/*for(int i = getY() - 1; i < getY() + 1; i++)
	{
		for(int j = getX() - 1; j < getX() + 1; j++)
		{
			if(getPared(j, i, lab))
			{
				numMuros++;
			}
		}
	}*/

	return (distFantasma*100*0.1/(distSalida*100*2/*+numMuros*100*0.1*/));
}

bool PacmanPersonaje:: getPared(int x,int y,char lab[10][10])
{
	return lab[y][x] == 'M';
}

PacmanPersonaje::~PacmanPersonaje() {
	// TODO Auto-generated destructor stub
}