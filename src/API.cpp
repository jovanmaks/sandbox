#include <iostream>
#include "Grid.h"

int main()
{

/* DEKLARACIJA */

grid::BufferData BD;
grid::Buffer     B;
Atributes        atr;

int countVertex = atr.countCoordinates;
int countIndeks = atr.countIndeks;

int countBoja = atr.countAll;


/* VERTEXI XY*/


float* Niz = new float[countVertex];
B.VertexBuffer_XY(Niz);

/* VERTEXI XY + RGBA*/

float* NizSve = new float[countBoja];
B.VertexBuffer_XY_RGBA(NizSve);



/* INDEKSI */
std::vector <unsigned int> indeksi;
B.IndexBuffer(indeksi);

unsigned int* indeksiNiz = new unsigned int [countIndeks];
indeksiNiz = &indeksi[0];//Index buffer mora biti array pa ovdje vektor pretvaras u array

/* R G B */
float* Boja = new float [countVertex/2];
BD.ColorRGB ( Boja );


/* ALFA */
float* Alfa = new float [countVertex/2];
BD.ColorAlpha( Alfa );


/* ISPIS */

std::cout<<"Verteksi:"<<std::endl;
for(int i=0; i<countVertex; i++)
    std::cout<< Niz[i] << "  ";

    std::cout<<std::endl;


std::cout<<"Indeksi:"<<std::endl;
for(int i=0; i<countIndeks; i++)
    std::cout<< indeksiNiz[i] << "  ";

    std::cout<<std::endl;
 

std::cout<<"R G B:"<<std::endl;
for(int i=0; i<countVertex/2; i++)
    std::cout<< Boja[i] << "  ";

    std::cout<<std::endl;


std::cout<<"Alfa:"<<std::endl;
for(int i=0; i<countVertex/2; i++)
    std::cout<< Alfa[i] << "  ";

    std::cout<<std::endl;



std::cout<<"Spojeno:"<<std::endl;
for(int i=0; i<countBoja; i++)
    std::cout<< NizSve[i] << "  ";

    std::cout<<std::endl;




return 0;
}