    #ifndef __ATRIBUTES_H__
#define __ATRIBUTES_H__


class Atributes
{
private:
    
public:
    unsigned  int moduo;

    float GridValue = 0.5;/* VAZNO */

//============== GRID - CELL ==========================

    unsigned int rows = 5;/* VAZNO */
    unsigned int colums = 2;/* VAZNO */

    /* Isto */
    unsigned int width = 2;
    unsigned int height = 2;

//============== GRID - VERTEX ========================= 


    unsigned int widthVertex = rows + 1;/* VAZNO */
    unsigned int heightVertex = colums + 1;/* VAZNO */

    /* Isto */
    unsigned int GridVertexWidth = width + 1;
    unsigned int GridVertexHeight = height + 1;

//============= BUFFERS - COUNT =======================

    unsigned int countCoordinates = widthVertex * heightVertex * 2; /* VAZNO */
    unsigned int countVerteks = widthVertex * heightVertex; /* VAZNO */

    unsigned int countValues = rows * colums;
    unsigned int countIndeks = rows * colums * 6;

    /* Isto */
    unsigned int indexCount= width *height * 4;
    unsigned int indexCountTriangles= width *height * 4 *1.5;

    unsigned int vertexCount = GridVertexWidth * GridVertexHeight *2;
    /*
    it goes * 2 becouse each vertex has 2 component (X and Y)
    */

    unsigned int GridVertexCount = GridVertexWidth * GridVertexHeight * 2; 

//======================================================
////// ovo jos nije odradjeno //////
    unsigned int posX;
    unsigned int posY;

//============= ELEMENT - CELL ========================
    unsigned int ColumnWidth = 2;
    unsigned int ColumnHeight = 2;
    unsigned int ColumnValue = 5;

    unsigned int FurnitureWidth = 4;
    unsigned int FurnitureHeight = 4;
    unsigned int FurnitureValue = 6;



    //mozes ubaciti i funkcije koje su globalne


    //============================================
    /*
    
    -STUB == 15;
    -ZID == 14;
    -OTVOR== -8;   ONDA TI KAD SABERES OTVOR DODJE NPR 14 - 8 = 6
        -PROZOR
        -VRATA
        -PROLAZ


    -KOMUNIKACIJA
        -STEPENISTE
        -LIFT
        

    -NAMJESTAJ
        IIMA KOLKO TI BOG HOCE ALI NEKA GRUBA PODJELA PO SOBAMA

    */
   //=============================================


};



#endif