#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main(int argc, char **argv)
{
    char laberinto[10][10];
    string currChar;
    ifstream labArch;
    int x = 0, y = 0;   

    cout<<argv[1]<<endl;

    labArch.open(argv[1]);
    while(!labArch.eof())
    {   
        getline(labArch, currChar, '\n');

        if(!labArch.eof())
        {
            for(int i = 0; i < currChar.length(); i += 2)
            {
                laberinto[y][x] = currChar[i];
                x++;
            }
        }
        

        x = 0;
        y++;
    }
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout<<laberinto[i][j];
        }
        cout<<endl;
    }

    return 0;

}