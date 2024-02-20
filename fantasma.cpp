#include "fantasma.h"

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