#ifndef __ATRIBUTES_H__
#define __ATRIBUTES_H__


class Atributes
{
private:
    
public:
    unsigned  int moduo;

    unsigned int GridValue = 0;

//============== GRID - CELL ==========================
    unsigned int width = 12;
    unsigned int height = 8;

//============== GRID - VERTEX ========================= 

    unsigned int GridVertexWidth = width + 1;
    unsigned int GridVertexHeight = height + 1;

//============= BUFFERS - COUNT =======================

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