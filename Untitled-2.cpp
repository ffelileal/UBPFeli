#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    ofstream fichero ("prubeba.txt");
    fichero << "Hola Mundo" << endl;
    fichero << "Una linea";
    fichero << "Otra linea" << endl;
    fichero.close();

    return 0;
}

