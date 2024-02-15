#include<iostream>
#include<fstream>

using namespace std;

void mostrarLab(char lab[][10]);

int main(int argc, char **argv)
{
    char laberinto[10][10];
    string currChar;
    ifstream labArch(argv[1]);
    int x = 0, y = 0;   

    cout<<argv[1]<<endl;

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