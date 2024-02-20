#include<iostream>
#include<string>
#include<math.h>

#ifndef PACMAN
#define PACMAN

class Pacman
{
    private:
        int x;
        int y;

    public:

        Pacman(int x, int y);
        float getDistancia(int salidaX, int salidaY);

};

#endif