#include "Grid.h"
#include "Atributes.h"

namespace grid
{
        BufferData::BufferData()
        {            
        }

        BufferData::~BufferData()
        {            
        }



        float BufferData::Value ( float* values )
        {

            for(int i=0; i<colums;i++)
            {
                for(int j=0; j<rows; j++ )
                {
                values[i + j*colums]= GridValue ;
                }
            }
            return 0;
        }  

        /* X position */
        float BufferData::XPositionCoordinates ( float* Xpositions )
        {

            for(int i=0; i<heightVertex; i++)
            {
                for(int j=0; j<widthVertex; j++)
                {
                    Xpositions[ i*widthVertex + j ] = j ;
                }
            }

            return 0;
        }



        /* Y position */
        float BufferData::YPositionCoordinates ( float* Ypositions )
        {

            for(int i=0; i<heightVertex; i++)
            {
                for(int j=0; j<widthVertex; j++)
                {
                    Ypositions[ i*widthVertex + j ] = i ;
                }
            }

            return 0;            
        }


        /* Z position */
        float BufferData::ZPositionCoordinates ( float* Zpositions )
        {

            for(int i=0; i<heightVertex; i++)
            {
                for(int j=0; j<widthVertex; j++)
                {
                    Zpositions[ i*widthVertex + j ] = 0;
                }
            }

            return 0;            
        }


        /* Texture coordinates */
        float BufferData::TextureCoordinates ( float* array )
        {
                /* ovo ostaje da se uradi - TODO */
                return 0;
        }


        /* Color values */
        float BufferData::Color ( float* array)
        {

            /* trebaju ti tri vrijednosti */
            return 0;
        }



        //=============== BUFFER CLASS ================//
        
        Buffer::Buffer()
        {            
        }

        Buffer::~Buffer()
        {            
        }        


        float Buffer::VertexBuffer_XY(float* buffer)
        {
            int count = countCoordinates;

            float* Xpositions;
            float* Ypositions;


            Xpositions = new float[count/2];
            Ypositions = new float[count/2];

            BufferData BD;
            BD.XPositionCoordinates(Xpositions);
            BD.YPositionCoordinates(Ypositions);
            
            for(int i=0; i<count/2; i++)
            {
                buffer[  i*2      ]= Xpositions[i] ;/* za X1 poziciju  */
                buffer[ (i*2) + 1 ]= Ypositions[i] ;/* za Y1 poziciju  */

            }

            return 0;    

        }




        float Buffer::VertexBuffer_XYZ(float* buffer, float* Xpositions, float* Ypositions, float* Zpositions)
        {
            int count = countCoordinates;
            
            for(int i=0; i<count/3; i++)
            {

                buffer[  i*3      ]= Xpositions[i] ;/* za X1 poziciju  */
                buffer[ (i*3) + 1 ]= Ypositions[i] ;/* za Y1 poziciju  */
                buffer[ (i*3) + 2 ]= Zpositions[i] ;/* za Z1 poziciju  */

            }

            return 0;    

        }


        float Buffer::VertexBuffer_XY_RGBA(float* buffer, float* Xpositions, float* Ypositions, float* R, float* G, float* B, float* A)
        {

            return 0;
        }

        float Buffer::VertexBuffer_XYZ_RGBA(float* buffer, float* Xpositions, float* Ypositions, float* Zposition, float* R, float* G, float* B, float* A)
        {

            return 0;
        }

        unsigned int Buffer::IndexBuffer( std::vector<unsigned int>& indices )
        {
           
             // indices.reserve(2*(width-1) * (height-1));

            for(int i = 0; i<colums; i++)
            {
                for(int j = 0; j<rows; j++)
                {

                int  xPos = j + i*(rows+1);

                indices.push_back(xPos);
                indices.push_back(xPos+1);
                indices.push_back(xPos+rows +1);


                indices.push_back(xPos+1);
                indices.push_back(xPos + rows+2);        
                indices.push_back(xPos + rows+1);        

                }
            }
                      
          return 0;
        }



} // namespace grid
