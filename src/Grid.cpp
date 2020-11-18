#include "Grid.h"

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
        }


        /* Color values */
        float BufferData::Color ( float* array)
        {

            /* trebaju ti tri vrijednosti */

        }



        //=============== BUFFER CLASS ================//
        
        Buffer::Buffer()
        {            
        }

        Buffer::~Buffer()
        {            
        }        


        float Buffer::VertexBufferTest(float* array)
        {
            
            int count = countCoordinates + countValues*4;
            /*  
            float* array;
            array = new float [count];
            */

            for(int i=0; i<count/6; i++)
            {
                array[  i*6      ]= 0 ;/* za X1 poziciju  */
                array[ (i*6) + 1 ]= 1 ;/* za Y1 poziciju  */
                array[ (i*6) + 2 ]= 2 ;/* za R boju  */
                array[ (i*6) + 3 ]= 3 ;/* za G boju  */
                array[ (i*6) + 4 ]= 4 ;/* za B boju  */
                array[ (i*6) + 5 ]= 5 ;/* za alfa kanal  */

            }

            return 0;    
        }

        float Buffer::VertexBuffer_XY(float* array)
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
                array[  i*2      ]= Xpositions[i] ;/* za X1 poziciju  */
                array[ (i*2) + 1 ]= Ypositions[i] ;/* za Y1 poziciju  */

            }

            return 0;    

        }




        float Buffer::VertexBuffer_XYZ(float* array, float* Xpositions, float* Ypositions, float* Zpositions)
        {
            int count = countCoordinates;
            
            for(int i=0; i<count/3; i++)
            {

                array[  i*3      ]= Xpositions[i] ;/* za X1 poziciju  */
                array[ (i*3) + 1 ]= Ypositions[i] ;/* za Y1 poziciju  */
                array[ (i*3) + 2 ]= Zpositions[i] ;/* za Z1 poziciju  */

            }

            return 0;    

        }




        float VertexBuffer_XY_RGBA(float* array, float* Xpositions, float* Ypositions, float* R, float* G, float* B, float* A)
        {

            return 0;
        }

        float VertexBuffer_XYZ_RGBA(float* array, float* Xpositions, float* Ypositions, float* Zposition, float* R, float* G, float* B, float* A)
        {

            return 0;
        }




} // namespace grid
