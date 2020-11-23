#include <iostream>
#include "Grid.h"

int main()
{

/* DEKLARACIJA */

grid::BufferData BD2;
grid::Buffer     B2;
Atributes        atr2;

int countVertexXY = atr2.countCoordinatesXY;
int countVertexXYZ = atr2.countCoordinatesXYZ;


int countIndeks = atr2.countIndeks;



int countRGB_XY = atr2.countAllXY;
int countRGB_XYZ = atr2.countAllXYZ;



/* VERTEXI XY*/


float* NizXY = new float[countVertexXY];
B2.VertexBuffer_XY(NizXY);

/* VERTEXI XYZ*/

float* NizXYZ = new float[countVertexXYZ];
B2.VertexBuffer_XYZ(NizXYZ);



/* VERTEXI XY + RGBA*/

float* NizXY_RGB = new float[countRGB_XY];
B2.VertexBuffer_XY_RGBA(NizXY_RGB);

/* VERTEXI XYZ + RGBA*/

float* NizXYZ_RGB = new float[countRGB_XYZ];
B2.VertexBuffer_XYZ_RGBA(NizXYZ_RGB);



// /* INDEKSI */
std::vector <unsigned int> indeksi;
B2.IndexBuffer(indeksi);

unsigned int* indeksiNiz = new unsigned int [countIndeks];
indeksiNiz = &indeksi[0];//Index buffer mora biti array pa ovdje vektor pretvaras u array

// /* R G B */
// float* Boja = new float [countVertex/2];
// BD.ColorRGB ( Boja );


// /* ALFA */
// float* Alfa = new float [countVertex/2];
// BD.ColorAlpha( Alfa );




/* ISPIS */

std::cout<<"XY Bufer:"<<std::endl;
for(int i=0; i<countVertexXY; i++)
    std::cout<< NizXY[i] << "  ";

    std::cout<<std::endl;

std::cout<<"XYZ Bufer:"<<std::endl;
for(int i=0; i<countVertexXYZ; i++)
    std::cout<< NizXYZ[i] << "  ";

    std::cout<<std::endl;


std::cout<<"XY_RGBA Bufer:"<<std::endl;
for(int i=0; i<countRGB_XY; i++)
    std::cout<< NizXY_RGB[i] << "  ";

    std::cout<<std::endl;


std::cout<<"XYZ_RGBA Bufer:"<<std::endl;
for(int i=0; i<countRGB_XYZ; i++)
    std::cout<< NizXYZ_RGB[i] << "  ";

    std::cout<<std::endl;


    std::cout<<std::endl;
 std::cout<<"Indeksi:"<<std::endl;
for(int i=0; i<countIndeks; i++)
    std::cout<< indeksiNiz[i] << "  ";

    std::cout<<std::endl;
/* 
 

std::cout<<"R G B:"<<std::endl;
for(int i=0; i<countVertex/2; i++)
    std::cout<< Boja[i] << "  ";

    std::cout<<std::endl;


std::cout<<"Alfa:"<<std::endl;
for(int i=0; i<countVertex/2; i++)
    std::cout<< Alfa[i] << "  ";

    std::cout<<std::endl;



 */

return 0;
}