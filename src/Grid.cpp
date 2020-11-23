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


        float BufferData::ColorRGB ( float* rgb)
        {


             for(int i=0; i<countSingleColor/2;i++)
            {
                
                rgb[i*2] = RGB1;
                rgb[i*2 + 1] = RGB2;

            } 
            
            return 0;
        }

        float BufferData::ColorAlpha ( float* alpha )
        {
            
            for(int i=0; i<countAlfa;i++)
            {
                alpha[i] = 1;
            }

            return 0;
        }

        /* Texture coordinates */
        float BufferData::TextureCoordinates ( float* array )
        {
                /* ovo ostaje da se uradi - TODO */
                return 0;
        }
       



        //=============== BUFFER CLASS ================//
        
        Buffer::Buffer()
        {            
        }

        Buffer::~Buffer()
        {            
        }        


        float Buffer::VertexBuffer_XY(float* bufferXY)
        {       

           float* Xpositions = new float[countVerteks];
           float* Ypositions = new float[countVerteks];

            BufferData BD;
            BD.XPositionCoordinates(Xpositions);
            BD.YPositionCoordinates(Ypositions);
            
            for(int i=0; i<countCoordinatesXY/2; i++)
            {
                bufferXY[  i*2      ]= Xpositions[i] ;/* za X1 poziciju  */
                bufferXY[ (i*2) + 1 ]= Ypositions[i] ;/* za Y1 poziciju  */

            }

            return 0;    
        }


        float Buffer::VertexBuffer_XYZ(float* bufferXYZ)
        {

            float* Xpositions = new float[countVerteks];
            float* Ypositions = new float[countVerteks];
            float* Zpositions = new float[countVerteks];

            BufferData BD;
            BD.XPositionCoordinates(Xpositions);
            BD.YPositionCoordinates(Ypositions);
            BD.ZPositionCoordinates(Zpositions);

            
            for(int i=0; i<countCoordinatesXYZ/3; i++)
            {

                bufferXYZ[  i*3      ]= Xpositions[i] ;/* za X1 poziciju  */
                bufferXYZ[ (i*3) + 1 ]= Ypositions[i] ;/* za Y1 poziciju  */
                bufferXYZ[ (i*3) + 2 ]= Zpositions[i] ;/* za Z1 poziciju  */                 

            }

            return 0;    

        }


        float Buffer::VertexBuffer_XY_RGBA(float* bufferXY_RGBA)
        {            
            
            float* Xpositions = new float[countVerteks];
            float* Ypositions = new float[countVerteks]; 

            float* rgb = new float[countSingleColor];            
            float* A   = new float[countAlfa];


            BufferData BD;
            BD.XPositionCoordinates(Xpositions);
            BD.YPositionCoordinates(Ypositions);
            BD.ColorRGB(rgb);
            BD.ColorAlpha(A);
            


            for(int i=0; i<countAllXY/6; i++)
            {
                bufferXY_RGBA[  i*6      ]= Xpositions[i] ;/* za X1 poziciju  */
                bufferXY_RGBA[ (i*6) + 1 ]= Ypositions[i] ;/* za Y1 poziciju  */
                bufferXY_RGBA[ (i*6) + 2 ]= rgb[i] ;/* za Y1 poziciju  */
                bufferXY_RGBA[ (i*6) + 3 ]= rgb[i] ;/* za Y1 poziciju  */
                bufferXY_RGBA[ (i*6) + 4 ]= rgb[i] ;/* za Y1 poziciju  */
                bufferXY_RGBA[ (i*6) + 5 ]= A[i] ;/* za Y1 poziciju  */

            }

            return 0;    
        }

        float Buffer::VertexBuffer_XYZ_RGBA(float* bufferXYZ_RGBA)
        {

            
            float* Xpositions = new float[countVerteks];
            float* Ypositions = new float[countVerteks];
            float* Zpositions = new float[countVerteks];


            float* rgb = new float[countSingleColor];            
            float* A = new float[countAlfa];


            BufferData BD;
            BD.XPositionCoordinates(Xpositions);
            BD.YPositionCoordinates(Ypositions);
            BD.ColorRGB(rgb);
            BD.ColorAlpha(A);
            


            for(int i=0; i<countAllXYZ/7; i++)
            {
                bufferXYZ_RGBA[  i*7      ]= Xpositions[i] ;/* za X1 poziciju  */
                bufferXYZ_RGBA[ (i*7) + 1 ]= Ypositions[i] ;/* za Y1 poziciju  */
                bufferXYZ_RGBA[ (i*7) + 2 ]= Zpositions[i] ;/* za Y1 poziciju  */

                bufferXYZ_RGBA[ (i*7) + 3 ]= rgb[i] ;/* za Y1 poziciju  */
                bufferXYZ_RGBA[ (i*7) + 4 ]= rgb[i] ;/* za Y1 poziciju  */
                bufferXYZ_RGBA[ (i*7) + 5 ]= rgb[i] ;/* za Y1 poziciju  */
                bufferXYZ_RGBA[ (i*7) + 6 ]= A[i] ;/* za Y1 poziciju  */


            }

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
