#include<iostream>
#include<fstream>
#include "pacman.h"
#include "fantasma.h"

using namespace std;

void mostrarLab(char lab[][10]);

int main(int argc, char **argv)
{
    char laberinto[10][10];

    string currChar;
    ifstream labArch("MINIPAC1.txt");

    int x = 0, y = 0,
    salidaX, salidaY;

    Pacman *pacman;
    Fantasma *fantasma;
    
    while(!labArch.eof())
    {   
        getline(labArch, currChar, '\n');

        if(!labArch.eof())
        {
            for(int i = 0; i < currChar.length(); i += 2)
            {
                switch(currChar[i])
                {
                    case 'C':
                        pacman = new Pacman(x, y);
                        break;
                    
                    case 'F':
                        fantasma = new Fantasma(x, y);
                        break;

                    case 'S':
                        salidaX = x;
                        salidaY = y;
                        break;

                }
                laberinto[y][x] = currChar[i];
                x++;
            }
        }
        
        x = 0;
        y++;
    }

    labArch.close();

    mostrarLab(laberinto);    

    return 0;

}


void mostrarLab(char lab[][10])
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout<<lab[i][j];
        }
        cout<<endl;
    }
}