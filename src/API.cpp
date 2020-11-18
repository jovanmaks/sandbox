#include <iostream>
#include "Grid.h"

int main()
{

/* DEKLARACIJA */

grid::Buffer B;
Atributes atr;



/* VERTEXI XY*/

int countVertex = atr.countCoordinates;
int countIndeks = atr.countIndeks;


float* Niz = new float[countVertex];
B.VertexBuffer_XY(Niz);

/* VERTEXI XY + RGBA*/


/* INDEKSI */

std::vector <unsigned int> indeksi;
B.IndexBuffer(indeksi);

unsigned int* indeksiNiz = new unsigned int [countIndeks];
indeksiNiz = &indeksi[0];//Index buffer mora biti array pa ovdje vektor pretvaras u array



/* ISPIS */

std::cout<<"Verteksi:"<<std::endl;
for(int i=0; i<countVertex; i++)
    std::cout<< Niz[i] << "  ";

    std::cout<<std::endl;


std::cout<<"Indeksi:"<<std::endl;
for(int i=0; i<countIndeks; i++)
    std::cout<< indeksiNiz[i] << "  ";

    std::cout<<std::endl;
 

return 0;
}