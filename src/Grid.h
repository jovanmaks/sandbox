#pragma once
#include "Atributes.h"



namespace grid
{
    class BufferData : public Atributes
    {
    private:

    public:
        BufferData();
        ~BufferData();

        float Value                       ( float* values     );
          
        float XPositionCoordinates        ( float* Xpositions );
        float YPositionCoordinates        ( float* Ypositions );
        float ZPositionCoordinates        ( float* Zpositions );


        float TextureCoordinates          ( float* array );//TODO
        float Color                       ( float* array );//TODO 

    };

    class Buffer : public Atributes
    {
    private:
    public:
        Buffer(/* args */);
        ~Buffer();

        float VertexBufferTest(float* array);

        float VertexBuffer_XY(float* array);
        float VertexBuffer_XYZ(float* array, float* Xpositions, float* Ypositions, float* Zpositions);
       
        float VertexBuffer_XY_RGBA(float* array, float* Xpositions, float* Ypositions, float* R, float* G, float* B, float* A);
        float VertexBuffer_XYZ_RGBA(float* array, float* Xpositions, float* Ypositions, float* Zposition, float* R, float* G, float* B, float* A);


    };
    
        
        
} // namespace grid
