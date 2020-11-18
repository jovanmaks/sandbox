#include <iostream>
#include "Grid.h"

int main()
{

grid::Buffer B;
Atributes atr;

int count = atr.countCoordinates;




/*  */

float* Niz;
Niz  = new float[count];

B.VertexBuffer_XY(Niz);

std::cout<<count<<std::endl;

std::cout<<"pozicije:"<<std::endl;
for(int i=0; i<count; i++)
    std::cout<< Niz[i] << "  ";

    std::cout<<std::endl;
/*  */




/* VERTEKSI */
/* 
    unsigned int BrojVertexa;
    BrojVertexa = atr.vertexCount;

    float* verteksi;
    verteksi = new  float [BrojVertexa];

    Grid.GridVertex(verteksi);

    std::cout<<"verteksi Triangles:"<<std::endl;
    //ispis na ekran
    for(int i=0; i< BrojVertexa; i++)
    {
    std::cout<< verteksi[i] << "  ";
    }
    std::cout<< " " <<std::endl;
 */




/* INDEKSI TRIANGLES*/
/* 
    std::cout<<"indeksi Triangles:"<<std::endl;

     std::vector <unsigned int> indeksiTriangles;//Declarises vektor za unos koordinata  

     Grid.GridIndexTriangles(indeksiTriangles);

     unsigned int* indeksiNizTriangles;
     indeksiNizTriangles = new unsigned int [BrojIndeksTriangles]; //Deklarises niz u koji ces smjestiti koordinate
     indeksiNizTriangles = &indeksiTriangles[0];//Index buffer mora biti array pa ovdje vektor pretvaras u array

    //ispis na ekran
    for(int i=0; i<BrojIndeksTriangles; i++)
    {
    std::cout<< indeksiNizTriangles[i] << "  ";
    }

    std::cout<< " " <<std::endl; */




/* INDEKSI QUADS*/
/* 
    std::cout<<"indeksi Quads:"<<std::endl;

     std::vector <unsigned int> indeksi;//Declarises vektor za unos koordinata  

     Grid.GridIndexQuads(indeksi);

     unsigned int* indeksiNiz;
     indeksiNiz = new unsigned int [BrojIndeksa]; //Deklarises niz u koji ces smjestiti koordinate
     indeksiNiz = &indeksi[0];//Index buffer mora biti array pa ovdje vektor pretvaras u array

    //ispis na ekran
    for(int i=0; i<BrojIndeksa; i++)
    {
    std::cout<< indeksiNiz[i] << "  ";
    }
    std::cout<< " " <<std::endl;
 */

return 0;
}