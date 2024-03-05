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

bool PacmanPersonaje::EscaladaSimpleAlternativo(char lab[10][10], int salidaX, int salidaY, Fantasma fantasma)
{
	double hPr = getValor(salidaX, salidaY, fantasma.getX(), fantasma.getY(), lab), hPrAct;
	srand(time(NULL));

	bool mejor = false, 
		 pared = false;

	int mov;

	fantasma.mover(lab);
	for(int i = 0; i < 200 && !mejor; i++)
	{
		PacmanPersonaje *auxPac = new PacmanPersonaje(getX(), getY());
		mov = 1+ rand() %4;
		switch(mov)
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
		if(!pared)
		{
			auxPac->mover(mov);
			hPrAct = auxPac->getValor(salidaX, salidaY, fantasma.getX(), fantasma.getY(), lab);

			if(hPrAct < hPr)
			{
				mover(mov);
				mejor = true;
			}
		}
		delete auxPac;
	}

	return mejor;
}

bool PacmanPersonaje::EscaladaSimple(char lab[10][10], int salidaX, int salidaY, Fantasma fantasma) { //comprobar que no nos come el fantasma
	double m=getValor(salidaX, salidaY, fantasma.getX(), fantasma.getY(), lab);
	cout<<m<<endl;
	PacmanPersonaje* aux = new PacmanPersonaje(getX(),getY());
	int mov =1;
	bool pared = aux->getPared(aux->getX(),aux->getY(),lab), fin = true;
	fantasma.mover(lab);


	if(aux->getValor(salidaX, salidaY, fantasma.getX(), fantasma.getY(), lab)>m){
		do
		{
			aux->mover(mov);
			cout<<"Movimiento: "<<mov<<" | "<<aux->getValor(salidaX, salidaY, fantasma.getX(), fantasma.getY(), lab)<<endl;
			mov ++;
			pared= aux->getPared(aux->getX(),aux->getY(),lab);
			aux->setX(getX());
			aux->setY(getY());
			if (pared==true){
				mov++;
			}
		}
		while((aux->getValor(salidaX, salidaY, fantasma.getX(), fantasma.getY(), lab)>m) && 
			mov<5 && m > 0);
		if(mov>4 || m == 0){
			cout<<"No se ha encontrado solucion"<<endl;
			fin = false;
		}
		else{
			mover(mov);
		}
	}
	else
	{
		cout<<"No se ha encontrado solucion"<<endl;
		fin = false;
	}

	cout<<"Movimiento"<<endl;
	cout<<"mov:"<<mov<<"  Fila:"<<y<<"  Col:"<<x<<endl;
	return fin;
}

bool PacmanPersonaje::EscaladaMaxPendiente(char lab[10][10], int salidaX, int salidaY, Fantasma fantasma)
{
	double hPr = getValor(salidaX, salidaY, fantasma.getX(), fantasma.getY(), lab), hPrAux = 0;

	bool pared, mejor = false;

	int movMejor = 0;

	fantasma.mover(lab);

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

			hPrAux = auxPac->getValor(salidaX, salidaY, fantasma.getX(), fantasma.getY(), lab);

			if(hPrAux < hPr && hPrAux != 0)
			{
				movMejor = i;
				mejor = true;
				hPr = hPrAux;
			}
		}
		delete auxPac;
	}

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

	//return (distFantasma*100*0.1/(pow(distSalida*100, 2)/*+numMuros*100*0.1*/));
	return distSalida*2 * distFantasma*0.2;
}

bool PacmanPersonaje:: getPared(int x,int y,char lab[10][10])
{
	return lab[y][x] == 'M';
}

PacmanPersonaje::~PacmanPersonaje() {
	// TODO Auto-generated destructor stub
}