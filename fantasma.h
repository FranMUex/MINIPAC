#include<iostream>
#include<string>
#include<math.h>

#ifndef FANTASMA
#define FANTASMA

class Fantasma
{
    private:
        int x;
        int y;

    public:

        Fantasma(int x, int y);
        float getDistancia(int salidaX, int salidaY);

};

#endif