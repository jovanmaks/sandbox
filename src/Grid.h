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

        float VertexBuffer_XY(float* buffer);
        float VertexBuffer_XYZ(float* buffer, float* Xpositions, float* Ypositions, float* Zpositions);
       
        float VertexBuffer_XY_RGBA(float* buffer );
        float VertexBuffer_XYZ_RGBA(float* buffer, float* Xpositions, float* Ypositions, float* Zposition, float* R, float* G, float* B, float* A);

        unsigned int IndexBuffer(std::vector<unsigned int>& indices);



    };
    
        
        
} // namespace grid
