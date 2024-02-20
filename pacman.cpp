#include "pacman.h"

Pacman::Pacman(int x, int y)
{
    this->x = x;
    this->y = y;
}

float Pacman::getDistancia(int destinoX, int destinoY)
{
    int catetoX = destinoX - x;
    int catetoY = destinoY - y;

    return sqrt(catetoX^2 + catetoY^2);
}