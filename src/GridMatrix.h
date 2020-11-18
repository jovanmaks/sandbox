
#ifndef __GRIDMATRIX_H__
#define __GRIDMATRIX_H__

// #include <iostream>
#include <vector>


// #include <algorithm> // for copy
// #include <iterator> // for ostream_iterator


#include "Atributes.h"

//======================================================================
/*

VRIJEDNOSTI OVIH MATRICA IDE NA 0 JER SU ONE OSNOVNE I NA NJIH SE DODAJU OSTALE.

TO CE BITI PAPIR I NA NJIH DODAJES OSTALE

*/
//======================================================================

class GridMatrix : public Atributes
{
private:

public:
    GridMatrix(/* args */);
    ~GridMatrix();

   unsigned int GridValueMx( int* array,unsigned int width,unsigned int height );/* prebaceno */
   unsigned int GridVertexMx ( float* array );/* prebaceno */
   
   unsigned int GridVertex ( float* array );/* prebaceno */
   

   unsigned int GridIndexQuads ( std::vector<unsigned int>& indices);
   unsigned int GridIndexTriangles(std::vector<unsigned int>& indices);
};

#endif
