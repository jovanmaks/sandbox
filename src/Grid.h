#pragma once
#include "Atributes.h"
#include <vector>



namespace grid 
{
    class BufferData  : public Atributes
    {
    private:
    public:
        BufferData();
        ~BufferData();

        float Value                       ( float* values     );

          
        float XPositionCoordinates        ( float* Xpositions );
        float YPositionCoordinates        ( float* Ypositions );
        float ZPositionCoordinates        ( float* Zpositions );
        
        float ColorRGB                    ( float* rgb );//TODO 
        float ColorAlpha                  ( float* alpha );//TODO 


        float TextureCoordinates          ( float* array );//TODO


    };

    class Buffer : public Atributes
    {
    private:
    public:
        Buffer(/* args */);
        ~Buffer();

        float VertexBuffer_XY(float* bufferXY);
        float VertexBuffer_XYZ(float* bufferXYZ);
       
        float VertexBuffer_XY_RGBA(float* bufferXY_RGBA );
        float VertexBuffer_XYZ_RGBA(float* bufferXYZ_RGBA);

        unsigned int IndexBuffer(std::vector<unsigned int>& indices);
        unsigned int IndexBufferTracker( double mouseX, double mouseY, unsigned int* IndeksiElement);

        // unsigned int IndexBufferBase ()
        unsigned int IndexBufferElement( double mouseX,double mouseY, unsigned int* Igraliste );
        unsigned int IndexBufferMemory( unsigned int* Merged, unsigned int* Base, unsigned int* Element,  int countBase, int countElement, bool clicked );

    };
    
        
        
} // namespace grid
