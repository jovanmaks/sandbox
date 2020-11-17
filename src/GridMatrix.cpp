#include "GridMatrix.h"

GridMatrix::GridMatrix(/* args */)
{
}

GridMatrix::~GridMatrix()
{
}


unsigned int GridMatrix::GridValueMx(int* array, unsigned int width, unsigned int height)
{

  for(int i=0; i<height;i++)
  {
    for(int j=0; j<width; j++ )
    {
      array[i + j*height]=GridValue;
    }
  }

return 0;
}

/*
If someone is reading this code let the god help him to understand this piece of crap.
 This is for the number of vertecies. It has +1 number of vertecies in the loop then the number of cells
 */
unsigned int GridMatrix::GridVertexMx ( float* array )
{
  for(int i=0; i< GridVertexHeight; i++)
  {
    for(int j=0; j< GridVertexWidth * 2; j++ )// *2 becouse X and Y component
    {
       if( (i*GridVertexWidth * 2 + j) % 2 == 0 ) //testiras da li je prvi ili drugi clan u nizu
       array[i * GridVertexWidth * 2 + j] =  j/2;
        
       else       
       array[i * GridVertexWidth * 2 + j] =  i ;

    }
  }

return 0;


} 

//=============== OVO KAD SE SMILUJES DA ISPISES KAO ARRAY A NE DA SALJES KAO VEKTOR NA TEST PA DA GA PRETVARAS U ARRAY ========================
unsigned int GridMatrix::GridIndexQuads ( std::vector<unsigned int>& indices)
{
    // indices.reserve(2*(width-1) * (height-1));


    for(int i = 0; i<height; i++)
    {
        for(int j = 0; j<width; j++)
        {

        int  xPos = j + i*(width+1);


        indices.push_back(xPos);
        indices.push_back(xPos+1);
        indices.push_back(xPos+width +2);
        indices.push_back(xPos+width + 1);        
        }
    }
    
  // std::copy(indices.begin(), indices.end(), std::ostream_iterator<float>(std::cout, " ")); 

return 0;

}


unsigned int GridMatrix::GridIndexTriangles( std::vector<unsigned int>& indices)
{
  
    // indices.reserve(2*(width-1) * (height-1));

   for(int i = 0; i<height; i++)
    {
        for(int j = 0; j<width; j++)
        {

        int  xPos = j + i*(width+1);


        indices.push_back(xPos);
        indices.push_back(xPos+1);
        indices.push_back(xPos+width +1);


        indices.push_back(xPos+1);
        indices.push_back(xPos + width+2);        
        indices.push_back(xPos + width+1);        

        }
    }
    



}